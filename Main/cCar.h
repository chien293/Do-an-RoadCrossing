	#ifndef cCar_h
#define cCar_h
#include "animal_vehical.h"

class cCar : public animal_vehical
{
	char **a; //a[3][8]
public:
	cCar(cPosition pos);
	char ** array2();
	void sound();
	void draw();
	int getWidth();
	int getType();
	cCar();
	~cCar();

};
#endif 
