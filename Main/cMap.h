#ifndef cMap_h
#define cMap_h

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <cmath>
#include "cPeople.h"
#include "cPosition.h"
#include "cRows.h"
#include "cLevel.h"
#include "animal_vehical.h"

using namespace std;
class cMap
{
	const int width = 100, height = 26;
	char map[40][125];
	cPeople people;
	cRows rowsData;
	cLevel level;
	int t = 0;
public:
	cMap();
	~cMap() = default;
	void resetMap(); // reset the map to default with no enemy and no player
	void printMap(); // print map to screen
	void hitMap();
	void redrawMap(); // redraw
	int draw(cPosition pos, char ** shape, int w, int h); // draw from position pos(x, y), shape(w, h) | 1: ok 0: go out of map, -1: crash
	void deleteOldPlayer();
	void drawPlayer(); // draw player to map, check if crash 
	void drawEnemies(animal_vehical* enemy); // draw enemy to map
	void initializeNewState(); // intialize a new map base on level, reset player state		
	void randomNextState();
	void updatePosPlayer(char moving);
	void bombEffect();
	void saveGame(string file);
	bool loadGame(string file);
	void printBorder();
	void printCongrats();
	bool printLevelUp();
	bool isEnd();
	bool isWin();
	void nextLevel();
	void printInt(int x, ofstream& outfile);
	int readInt(ifstream& infile);
};
#endif 