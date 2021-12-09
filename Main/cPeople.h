#ifndef cPeople_h
#define cPeople_h

#define RIGHTMAP 48
#define LEFTMAP 2

#include "cConsole.h"
#include "cPosition.h"
#include "animal_vehical.h"
#include "cBird.h"
#include "cCar.h"
#include "cDinosaur.h"
#include "cTruck.h"
#include <cmath>

class cPeople
{
private:
	cPosition pos;
	bool isDead;
	char** a;  //a[3][5]
	char** emptyPlayer;
	int width = 5, height = 3;
public:
	cPeople(); // set default position
	cPosition getPos();
	cPeople(cPosition pos); // set current position when load game
	~cPeople();
	void Up();
	void Down();
	void Right();
	void Left();
	bool checkIsDead();
	void killPlayer(); // set isDead
	char** array2();
	char** emptyShape();
	int getWidth();
	int getHeight();
	int getX();
	int getY();
	bool Impact(cPosition pos, int w, int h);
	void sound();
};

class constantVar {
public:
	static bool isMute;
	static bool isHard;
};
#endif