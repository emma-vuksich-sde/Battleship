// Emma Vuksich
// CSIS 297
// 18 October 2023
// Battleship Simulator

#ifndef BOARD
#define BOARD
#include <iostream>
#include <string>
using namespace std;

const int ROWS = 10;
const int COLS = 10;

struct SinkingShips
{
	int frigateShip, subShip, destroyerShip, battleshipShip, aircraftCarrierShip;
};

class Board 
{
    public:
        string board[ROWS][COLS];
		string gameboard[ROWS][COLS];
        void initializeBoard();
        void outputBoard(SinkingShips);
        void setBoard(int r, int c, string newSpot);
		void setGameBoard(int r, int c, string secretSpot);
		void aesthetic();
		void aestheticMiss();
		void aestheticHit();
		void aestheticSink();
		void aestheticFail();
		void aestheticIntro(char commander);
		void gameLost();
		void gameWon();
		void aestheticGameOver();
		char aestheticCharacterChoice();
};

#endif