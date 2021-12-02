#ifndef cTruck_h
#define cTruck_h
#include "animal_vehical.h"

class cTruck : public animal_vehical
{
	char** a; //a[3][8]
public:
	cTruck(cPosition pos);
	char **array2();
	void sound();
	void draw();
	int getWidth();
	int getType();
	cTruck();
	~cTruck();
};
#endif 
