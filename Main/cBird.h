#pragma once
#ifndef cBird_h
#define cBird_h
#include "animal_vehical.h"


class cBird : public animal_vehical
{
	char **a; //a[3][6]
public:

	cBird(cPosition pos);
	char ** array2();
	void sound();
	void draw();
	int getWidth();
	int getType();
	cBird();
	~cBird();
};
#endif 
