// Emma Vuksich
// CSIS 297
// 18 October 2023
// Battleship Simulator

#include <iostream>
#include <iomanip>
#include <string>
#include <tuple>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "ship.h"
#include "board.h"
using namespace std;

tuple<int, int, int> deploy_ships(int, Board);

int main()
{
    Ship frigate, sub, destroyer, battleship, aircraftCarrier, hit, miss, hits, missed;
    Board game;
	SinkingShips ships;
	int numRow, numCol, misses = 15, chances = 32;
	char charCol, commander;

    srand(time(NULL));
		
	// Game lore:
	character:
	commander = game.aestheticCharacterChoice();
	if (commander == '1')
	{
		cout << " ______________________________________________________________\n";
		cout << "|                                                              |\n";
		cout << "|  Commander C. Reeves,                                        |\n";
	}
    else if (commander == '2')
    {
		cout << " ______________________________________________________________\n";
		cout << "|                                                              |\n";
		cout << "|  Commander S. Howard,                                        |\n";
    }
	else if (commander == '3')
	{
		cout << " ______________________________________________________________\n";
		cout << "|                                                              |\n";
		cout << "|  Commander B. Walker,                                        |\n";
	}
	else
	{
		goto character;
	}
	game.aestheticIntro(commander);

    // Initializes the board:
    game.initializeBoard();
	
    // Assigning info and deploying the Frigate:
    frigate.setLabel("|F|");
    frigate.setSize(2);
	frigate.setHitsLeft(frigate.getSize());
	ships.frigateShip = frigate.getHitsLeft();
	auto [frigateRow, frigateCol, frigateDirection] = deploy_ships(frigate.getSize(), game);
    for (int i = 0; i < frigate.getSize(); i++)
    {
        if (frigateDirection == 0)
        {
            frigate.setSpot(frigateRow, frigateCol + i, i);
            game.setGameBoard(frigateRow, frigateCol + i, frigate.getLabel());
        }
        else if (frigateDirection == 1)
        {
            frigate.setSpot(frigateRow + i, frigateCol, i);
            game.setGameBoard(frigateRow + i, frigateCol, frigate.getLabel());
        }

    }
    
    // Assigning info and deploying the Sub:
    sub.setLabel("|S|");
    sub.setSize(3);
	sub.setHitsLeft(sub.getSize());
	ships.subShip = sub.getHitsLeft();
    auto [subRow, subCol, subDirection] = deploy_ships(sub.getSize(), game);
    for (int i = 0; i < sub.getSize(); i++)
    {
        if (subDirection == 0)
        {
            sub.setSpot(subRow, subCol + i, i);
            game.setGameBoard(subRow, subCol + i, sub.getLabel());
        }
        else if (subDirection == 1)
        {
            sub.setSpot(subRow + i, subCol, i);
            game.setGameBoard(subRow + i, subCol, sub.getLabel());
        }
    }
    
    // Assigning info and deploying the Destroyer:
    destroyer.setLabel("|D|");
    destroyer.setSize(3);
	destroyer.setHitsLeft(destroyer.getSize());
	ships.destroyerShip = destroyer.getHitsLeft();
    auto [destroyerRow, destroyerCol, destroyerDirection] = deploy_ships(destroyer.getSize(), game);
    for (int i = 0; i < destroyer.getSize(); i++)
    {
        if (destroyerDirection == 0)
        {
            destroyer.setSpot(destroyerRow, destroyerCol + i, i);
            game.setGameBoard(destroyerRow, destroyerCol + i, destroyer.getLabel());
        }
        else if (destroyerDirection == 1)
        {
            destroyer.setSpot(destroyerRow + i, destroyerCol, i);
            game.setGameBoard(destroyerRow + i, destroyerCol, destroyer.getLabel());
        }
    }
    
    // Assigning info and deploying the Battleship:
    battleship.setLabel("|B|");
    battleship.setSize(4);
	battleship.setHitsLeft(battleship.getSize());
	ships.battleshipShip = battleship.getHitsLeft();
    auto [battleshipRow, battleshipCol, battleshipDirection] = deploy_ships(battleship.getSize(), game);
    for (int i = 0; i < battleship.getSize(); i++)
    {
        if (battleshipDirection == 0)
        {
            battleship.setSpot(battleshipRow, battleshipCol + i, i);
            game.setGameBoard(battleshipRow, battleshipCol + i, battleship.getLabel());
        }
        else if (battleshipDirection == 1)
        {
            battleship.setSpot(battleshipRow + i, battleshipCol, i);
            game.setGameBoard(battleshipRow + i, battleshipCol, battleship.getLabel());
        }
    }
    
    // Assigning info and deploying the Aircraft Carrier:
    aircraftCarrier.setLabel("|A|");
    aircraftCarrier.setSize(5);
	aircraftCarrier.setHitsLeft(aircraftCarrier.getSize());
	ships.aircraftCarrierShip = aircraftCarrier.getHitsLeft();
    auto [aircraftCarrierRow, aircraftCarrierCol, aircraftCarrierDirection] = deploy_ships(aircraftCarrier.getSize(), game);
    for (int i = 0; i < aircraftCarrier.getSize(); i++)
    {
        if (aircraftCarrierDirection == 0)
        {
            aircraftCarrier.setSpot(aircraftCarrierRow, aircraftCarrierCol + i, i);
            game.setGameBoard(aircraftCarrierRow, aircraftCarrierCol + i, aircraftCarrier.getLabel());
        }
        else if (aircraftCarrierDirection == 1)
        {
            aircraftCarrier.setSpot(aircraftCarrierRow + i, aircraftCarrierCol, i);
            game.setGameBoard(aircraftCarrierRow + i, aircraftCarrierCol, aircraftCarrier.getLabel());
        }
    }
	
	game.outputBoard(ships);
	cout << "|                                                              |\n";

	for (int i = 0; i < chances; i++)
	{
		if (misses >= 10)
		{
			cout << "| Misses Until Game Over: " << misses << "                                   |\n";
		}
		else
		{
			cout << "| Misses Until Game Over: " << misses << "                                    |\n";
		}

		// All ships found and user won the game:
		if (frigate.getShipsSunk() == 1 && sub.getShipsSunk() == 1 && destroyer.getShipsSunk() == 1 && battleship.getShipsSunk() == 1 && aircraftCarrier.getShipsSunk() == 1)
		{
			game.gameWon();
			return 0;
		}
		
		input:
		cout << "|______________________________________________________________|\n\n";
		cout << " Enter the column (A-J) then row (1-10) of your target: ";
		cin >> charCol >> numRow;
		
		// Option to exit the game:
		if (numRow == 0 && charCol == 'X')
		{
			game.aestheticGameOver();
			game.outputBoard(ships);
			cout << "|                                                              |\n";
			cout << "|             Thank you for your service, Commander.           |\n";
			cout << "|          We look foward to battling by your side again.      |\n";
			cout << "|                                                              |\n";
			cout << "|                          GAME OVER                           |\n";
			cout << "|                       Thanks for playing!                    |\n";
			cout << "|______________________________________________________________|\n";
			return 0;
		}
		// Input validation:
		if (numRow != 1 && numRow != 2 && numRow != 3 && numRow != 4 && numRow != 5 && numRow != 6 && numRow != 7 && numRow != 8 && numRow != 9 && numRow != 10)
		{
			cin.ignore();
			cin.clear();
			game.aestheticFail();
			game.outputBoard(ships);
			cout << "|                                                              |\n";
			cout << "| Invalid input.                                               |\n";
			cout << "|                                                              |\n";
			cout << "| Target must be within numbered bounds (1-10), try again.     |\n";
			goto input;
		}
		// Input validation:
		if (charCol != 'A' && charCol != 'B' && charCol != 'C' && charCol != 'D' && charCol != 'E' && charCol != 'F' && charCol != 'G' && charCol != 'H' && charCol != 'I' && charCol != 'J')
		{
			cin.ignore();
			cin.clear();
			game.aestheticFail();
			game.outputBoard(ships);
			cout << "|                                                              |\n";
			cout << "| Invalid input.                                               |\n";
			cout << "|                                                              |\n";
			cout << "| Target must be a capital letter in bounds (A-J), try again.  |\n";
			goto input;
		}
		
		numRow = numRow - 2;
		numCol = (charCol - '0') - 7;
		
		// User missed:
		if (game.gameboard[numRow][numCol] == "| |")
		{
			misses--;
			missed.setGameLabel("|O|");
			missed.setGameSpot(numRow, numCol, i);
			game.setGameBoard(numRow, numCol, missed.getGameLabel());
			miss.setLabel("[O]");
			miss.setSpot(numRow, numCol, i);
			game.setBoard(numRow, numCol, miss.getLabel());
			game.aestheticMiss();
			game.outputBoard(ships);
			// Misses ran out and the user lost the game:
			if (misses < 1)
			{
				game.gameLost();
				return 0;
			}
		}
		// User hit a hit position:
		else if (game.gameboard[numRow][numCol] == "|X|" || game.gameboard[numRow][numCol] == "|O|")
		{
			game.aestheticFail();
			game.outputBoard(ships);
			cout << "|                                                              |\n";
			cout << "| That position has already been a target, try again.          |\n";
			goto input;
		}
		// User hit the FRIGATE:
		else if (game.gameboard[numRow][numCol] == "|F|")
		{
			hits.setGameLabel("|X|");
			hits.setGameSpot(numRow, numCol, i);
			game.setGameBoard(numRow, numCol, hits.getGameLabel());
			hit.setLabel("[X]");
			hit.setSpot(numRow, numCol, i);
			game.setBoard(numRow, numCol, hit.getLabel());
			ships.frigateShip--;
			if (ships.frigateShip < 1)
			{
				frigate.setShipsSunk(1);
				game.aestheticSink();
			}
			else
			{
				game.aestheticHit();
			}
			game.outputBoard(ships);
			i = -1;
		}
		// User hit the SUB:
		if (game.gameboard[numRow][numCol] == "|S|")
		{
			hits.setGameLabel("|X|");
			hits.setGameSpot(numRow, numCol, i);
			game.setGameBoard(numRow, numCol, hits.getGameLabel());
			hit.setLabel("[X]");
			hit.setSpot(numRow, numCol, i);
			game.setBoard(numRow, numCol, hit.getLabel());
			ships.subShip--;
			if (ships.subShip < 1)
			{
				sub.setShipsSunk(1);
				game.aestheticSink();
			}
			else
			{
				game.aestheticHit();
			}
			game.outputBoard(ships);
			i = 0;
		}
		// User hit the DESTROYER:
		else if (game.gameboard[numRow][numCol] == "|D|")
		{
			hits.setGameLabel("|X|");
			hits.setGameSpot(numRow, numCol, i);
			game.setGameBoard(numRow, numCol, hits.getGameLabel());
			hit.setLabel("[X]");
			hit.setSpot(numRow, numCol, i);
			game.setBoard(numRow, numCol, hit.getLabel());
			ships.destroyerShip--;
			if (ships.destroyerShip < 1)
			{
				destroyer.setShipsSunk(1);
				game.aestheticSink();
			}
			else
			{
				game.aestheticHit();
			}
			game.outputBoard(ships);
			i = -1;
		}
		// User hit the BATTLESHIP:
		else if (game.gameboard[numRow][numCol] == "|B|")
		{
			hits.setGameLabel("|X|");
			hits.setGameSpot(numRow, numCol, i);
			game.setGameBoard(numRow, numCol, hits.getGameLabel());
			hit.setLabel("[X]");
			hit.setSpot(numRow, numCol, i);
			game.setBoard(numRow, numCol, hit.getLabel());
			ships.battleshipShip--;
			if (ships.battleshipShip < 1)
			{
				battleship.setShipsSunk(1);
				game.aestheticSink();
			}
			else
			{
				game.aestheticHit();
			}
			game.outputBoard(ships);
			i = -1;
		}
		// User hit the AIRCRAFT CARRIER:
		else if (game.gameboard[numRow][numCol] == "|A|")
		{
			hits.setGameLabel("|X|");
			hits.setGameSpot(numRow, numCol, i);
			game.setGameBoard(numRow, numCol, hits.getGameLabel());
			hit.setLabel("[X]");
			hit.setSpot(numRow, numCol, i);
			game.setBoard(numRow, numCol, hit.getLabel());
			ships.aircraftCarrierShip--;
			if (ships.aircraftCarrierShip < 1)
			{
				aircraftCarrier.setShipsSunk(1);
				game.aestheticSink();
			}
			else
			{
				game.aestheticHit();
			}
			game.outputBoard(ships);
			i = -1;
		}
		cout << "|                                                              |\n";
	}
    
    return 0;
}

// Function to deploy the ships onto the board:
tuple<int, int, int> deploy_ships(int size, Board game)
{
    int rowBoundary = ROWS - size;
    int colBoundary = COLS - size;
    int r;
    int c;
    int d;
    
    while (true)
    {
        // Randomizing numbers for row, column, and direction:
        r = (rand() % rowBoundary);
        c = (rand() % colBoundary);
        d = (rand() % (1 - 0 + 1)) + 0;
        
        if (d == 0) // If the random number is 0, the direction will be horizontal.
        {
            for (int i = 0; i < (size + 1); i++)
            {
				if (game.gameboard[r][c + i] != "| |")
                {
                    i = (ROWS + COLS); 
                }
                if (i == size)
                {
                    return {r, c, d};
                }
            }
        } 
        else // If the random number is 1, the direction will be vertical.
        {
			for (int i = 0; i < (size + 1); i++)
            {
				if (game.gameboard[r + i][c] != "| |")
				{
                    i = (ROWS + COLS);
                }
                if (i == size)
                {
                    return {r, c, d};
                }
            }
        }
    }
}
