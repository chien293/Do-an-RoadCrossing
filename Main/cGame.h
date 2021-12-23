#ifndef cGame_h
#define cGame_h

#include <iostream>
#include <fstream>
#include <thread>
#include "cConsole.h"
#include "cPeople.h"
#include "animal_vehical.h"
#include "cRows.h"
#include "cMap.h"

using namespace std;

class cGame
{
	bool isLoaded = false;
	cMap map;
	bool isPausing = false;
public:
	cGame() = default;
	~cGame() = default;
	void gameSettings();
	bool newGame(); // start a new game, initialize cMap map
	bool continueGame();  //continue our game
	bool loadGameMenu(); // get file of cMap map
	void saveGameMenu(); //void saveGame(); // print file of cMap map
	void togglePauseGame(); // toggle status of isPausing
	void toggleMute();
	void toggleHard();
	void loading();
	vector<string> getAllFilename(const std::string& name);
	void menu();
	bool continueMenu();
};
#endif // cGame
