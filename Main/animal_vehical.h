#pragma once
#include <Windows.h>
#include <iostream>
#include "cConsole.h"
#include <mmsystem.h>
#include "cPosition.h"

using namespace std;
class animal_vehical
{
private:
	cPosition point;
	bool outMap;
public:
	cPosition getPos();
	int getX();
	int getY();
	animal_vehical();
	animal_vehical(cPosition st); // create new enemy with starting position
	virtual ~animal_vehical() = default;
	virtual char** array2() = 0; // return the shape of enemy to draw
	virtual void sound() = 0;
	virtual int getType() = 0;
	void updatePosition(int dx, int dy);
	bool isOutOfMap();
	void goOutMap();
	virtual int getWidth();
	int getHeight();
};

