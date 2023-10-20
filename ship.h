// Emma Vuksich
// CSIS 297
// 18 October 2023
// Battleship Simulator

#ifndef SHIP
#define SHIP
#include <iostream>
#include <string>
using namespace std;

class Ship
{
    private:
        string shipName;
        string shipLabel;
		string gameLabel;
        int shipSize;
		int hitsLeft;
		int shipsSunk;
    public:
        Ship() {
        };
        void setLabel(string l);
		void setGameLabel(string g);
        void setSize(int s);
        string getLabel();
		string getGameLabel();
        int getSize();
        void setSpot(int r, int c, int i);
		void setGameSpot(int r, int c, int i);
		void setHitsLeft(int h);
		int getHitsLeft();
		void setShipsSunk(int s);
		int getShipsSunk();
		// The max and min spots the ships can take up:
        int spot[5][2] = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}};
		int spots[5][2] = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}};

};

#endif