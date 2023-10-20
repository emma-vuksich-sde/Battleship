// Emma Vuksich
// CSIS 297
// 18 October 2023
// Battleship Simulator

#include "ship.h"
#include <string>
using namespace std;

void Ship::setLabel(string l) 
{
    shipLabel = l;
}

void Ship::setGameLabel(string g)
{
	gameLabel = g;
}

void Ship::setSize(int s) 
{
    shipSize = s;
}

string Ship::getLabel()
{
	return shipLabel;
}

string Ship::getGameLabel() 
{
    return gameLabel;
}

int Ship::getSize() 
{
    return shipSize;
}

void Ship::setSpot(int r, int c, int i)
{
    spot[i][0] = r; 
	spot[i][1] = c;
}

void Ship::setGameSpot(int r, int c, int i)
{
    spots[i][0] = r; 
	spots[i][1] = c;
}

void Ship::setHitsLeft(int h)
{
	hitsLeft = h;
}

int Ship::getHitsLeft()
{
	return hitsLeft;
}

void Ship::setShipsSunk(int s)
{
	shipsSunk = s;
}

int Ship::getShipsSunk()
{
	return shipsSunk;
}
