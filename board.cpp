// Emma Vuksich
// CSIS 297
// 18 October 2023
// Battleship Simulator

#include "board.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void Board::initializeBoard()
{
    int r = 0;
    int c = 0;

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            board[r][c] = "[ ]";
        }
        if (r >= 0 && r <= 10 && c >= 0 && c <= 10)
        {
            cout << "";
            board[r][c];
        }
    }
	
	for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            gameboard[r][c] = "| |";
        }
        if (r >= 0 && r <= 10 && c >= 0 && c <= 10)
        {
            cout << "";
            gameboard[r][c];
        }
    }
}


void Board::outputBoard(SinkingShips ships)
{
    int rows = 1;
	
	cout << "\n|             BATTLESHIP                                       |\n";
        
    cout << "|     A  B  C  D  E  F  G  H  I  J                             |\n";
	
    for (int row = 0; row < ROWS; row++)
    {
        if (rows == 10)
        {   
            cout << "| " << rows++ << " ";
        }
        if (rows < 10)
        {
            cout << "|  " << rows++ << " ";
        }
        for (int col = 0; col < COLS; col++)
        {
            cout << board[row][col];
        }
		if (rows == 2)
			{
				cout << "      Sonar Register        |" << endl;
			}
		else if (rows == 3)
			{
				cout << "  ---------------------     |" << endl;
			}
		else if (rows == 4)
			{
				cout << "  Frigate:           " << ships.frigateShip << "      |" << endl;
			}
		else if (rows == 5)
			{
				cout << "  Sub:               " << ships.subShip << "      |" << endl;
			}
		else if (rows == 6)
			{
				cout << "  Destroyer:         " << ships.destroyerShip << "      |" << endl;
			}
		else if (rows == 7)
			{
				cout << "  Battleship:        " << ships.battleshipShip << "      |" << endl;
			}
		else if (rows == 8)
			{
				cout << "  Aircraft Carrier:  " << ships.aircraftCarrierShip << "      |" << endl;
			}
		else if (rows == 11)
			{
				cout << "    (Enter X0 to exit)      |" << endl;
			}
        else
		{
			cout << "                            |" << endl;
		}
    }
}

void Board::setBoard(int r, int c, string newSpot)
{
    board[r][c] = newSpot;
}

void Board::setGameBoard(int r, int c, string secretSpot)
{
    gameboard[r][c] = secretSpot;
}

void Board::aestheticMiss()
{
	cout << " ______________________________________________________________\n";
	cout << "|   *       *          *    *         *          *           * |\n";
	cout << "|  *              *               *       *                    |\n";
	cout << "|         *               *                           *        |\n";
	cout << "|                                  _                           |\n";
	cout << "|         YOU MISSED!             | |            *             |\n";
	cout << "|                                 | |_                         |\n";
	cout << "|                              __/    |___                     |\n";
	cout << "|              _______________/           |_____               |\n";
	cout << "|             /                                 |              |\n";
	cout << "|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n";
	cout << "|                                                              |";
}

void Board::aestheticHit()
{
	cout << " ______________________________________________________________\n";
	cout << "|   *       *          *    *         *          *           * |\n";
	cout << "|  *              *               *       *                    |\n";
	cout << "|         *               *                           *        |\n";
	cout << "|                                  _                           |\n";
	cout << "|       YOU HIT A SHIP!           | |            *             |\n";
	cout << "|                                 | |_                         |\n";
	cout << "|                              __/    |___                     |\n";
	cout << "|              _______________/           |_____               |\n";
	cout << "|             /                                 |              |\n";
	cout << "|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n";
	cout << "|                                                              |";
}

void Board::aestheticSink()
{
	cout << " ______________________________________________________________\n";
	cout << "|   *       *          *    *         *          *           * |\n";
	cout << "|  *              *               *       *                    |\n";
	cout << "|         *               *                           *        |\n";
	cout << "|                                  _                           |\n";
	cout << "|       YOU SUNK A SHIP!          | |            *             |\n";
	cout << "|                                 | |_                         |\n";
	cout << "|                              __/    |___                     |\n";
	cout << "|              _______________/           |_____               |\n";
	cout << "|             /                                 |              |\n";
	cout << "|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n";
	cout << "|                                                              |";
}

void Board::aestheticFail()
{
	cout << " ______________________________________________________________\n";
	cout << "|   *       *          *    *         *          *           * |\n";
	cout << "|  *              *               *       *                    |\n";
	cout << "|         *               *                           *        |\n";
	cout << "|                                  _                           |\n";
	cout << "|       YOUR LAUNCH FAILED!       | |            *             |\n";
	cout << "|                                 | |_                         |\n";
	cout << "|                              __/    |___                     |\n";
	cout << "|              _______________/           |_____               |\n";
	cout << "|             /                                 |              |\n";
	cout << "|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n";
	cout << "|                                                              |";
}

void Board::aestheticIntro(char commander)
{
	
	cout << "|                                                              |\n";
	cout << "|  The USS John Paul Jones missile destroyer is under attack!  |\n";
	cout << "|   Our satellites are down, but the sonar register is still   |\n";
	cout << "|   functioning properly. Your mission is to sink the enemy    |\n";
	cout << "|   fleet before they retaliate. It's known that the enemy     |\n";
	cout << "|   ships are located in a 10x10 grid near the Amalfi Coast,   |\n";
	cout << "|   you will be able to choose your target and determine if    |\n";
	cout << "|   your launhched missile was a hit or a miss on the sonar.   |\n";
	cout << "|                                                              |\n";
	cout << "|  Our intel has relayed that the enemy fleet is comprised of  |\n";
	cout << "| a frigate, sub, destroyer, battleship, and aircraft carrier. |\n";
	cout << "| The number of necessary hits to sink each ship is located on |\n";
	cout << "|  the sonar register, you'll be able to track the hits there. |\n";
	cout << "| If you miss your targets 15 times, the enemy will coordinate |\n";
	cout << "|              your position and destroy your ship.            |\n";
	cout << "|                                                              |\n";
	cout << "|        The Naval brigade is at your command, good luck.      |\n";
	cout << "|                                                              |\n";
	cout << "|                                   ()                         |\n";
	cout << "|                                  ()                          |\n";
	cout << "|                                  _()                         |\n";
	cout << "|                                 | |                          |\n";
	cout << "|                                 | |_                         |\n";
	cout << "|                              __/    |___                     |\n";
	cout << "|              _______________/           |_____               |\n";
	cout << "|             /                                 |              |\n";
	cout << "|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n";
	cout << "|                                                              |";

}

void Board::gameLost()
{
	cout << "|                                                              |\n";
	cout << "| Misses Until Gave Over: 0                                    |\n";
	cout << "|                                                              |\n";
	cout << "|                          YOU LOST!                           |\n";
	cout << "|                                                              |\n";
	cout << "|                          GAME OVER                           |\n";
	cout << "|                       Thanks for playing!                    |\n";
	cout << "|______________________________________________________________|";
	cout << endl;
}

void Board::gameWon()
{
	cout << "|                                                              |\n";
	cout << "|                           YOU WON!                           |\n";
	cout << "|                                                              |\n";
	cout << "|                          GAME OVER                           |\n";
	cout << "|                       Thanks for playing!                    |\n";
	cout << "|______________________________________________________________|";
	cout << endl;
}

void Board::aestheticGameOver()
{
	cout << " ______________________________________________________________\n";
	cout << "|   *       *          *    *         *          *           * |\n";
	cout << "|  *              *               *       *                    |\n";
	cout << "|         *               *                           *        |\n";
	cout << "|                                  _                           |\n";
	cout << "|          GAME OVER!             | |            *             |\n";
	cout << "|                                 | |_                         |\n";
	cout << "|                              __/    |___                     |\n";
	cout << "|              _______________/           |_____               |\n";
	cout << "|             /                                 |              |\n";
	cout << "|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n";
	cout << "|                                                              |";
}

char Board::aestheticCharacterChoice()
{
	char commander;
	
	cout << " ______________________________________________________________\n";
	cout << "|                                                              |\n";
	cout << "|       1.] COMMANDER CLARK REEVES                             |\n";
	cout << "|           - TACTICAL SPECIALIST                              |\n";
	cout << "|           - 34 YEARS EXPERIENCE ON THE SEAS                  |\n";
	cout << "|           - EXCELLENT COMMUNICATION                          |\n";
	cout << "|                                                              |\n";
	cout << "|       2.] COMMANDER STELLA HOWARD                            |\n";
	cout << "|           - STRATEGIC EXPERT                                 |\n";
	cout << "|           - 25 YEARS OF EXPERIENCE ON THE SEAS               |\n";
	cout << "|           - DECISIVENESS UNDER PRESSURE                      |\n";
	cout << "|                                                              |\n";
	cout << "|       3.] COMMANDER BUSHWELL WALKER                          |\n";
	cout << "|           - MISSION INTELLIGENCE                             |\n";
	cout << "|           - 41 YEARS EXPEREINCE ON THE SEAS                  |\n";
	cout << "|           - STRONG LEADERSHIP SKILLS                         |\n";
	cout << "|                                                              |\n";
	cout << "|                                   ()                         |\n";
	cout << "|                                  ()                          |\n";
	cout << "|                                  _()                         |\n";
	cout << "|     CHOOSE YOUR CHARACTER!      | |                          |\n";
	cout << "|                                 | |_                         |\n";
	cout << "|                              __/    |___                     |\n";
	cout << "|              _______________/           |_____               |\n";
	cout << "|             /                                 |              |\n";
	cout << "|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n";
	cout << "|______________________________________________________________|\n\n";

	cout << " Choose Your Character (1, 2, or 3): ";
	cin >> commander;
	
	return commander;
}