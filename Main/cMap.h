#ifndef cMap_h
#define cMap_h

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <cmath>


using namespace std;
class cMap
{
	const int width = 65, height = 19;
	char map[40][125];
	static const char TITLE[30][90];
	int t = 0;
public:
	cMap();
	~cMap() = default;
	void resetMap();
	void printMap(); // print map to screen
	void drawTitle();

};
#endif // cMap