#ifndef cDino_h
#define cDino_h
#include "animal_vehical.h"
class cDinosaur : public animal_vehical
{
	char **a; //a[3][6]
public:

	cDinosaur(cPosition pos);

	char ** array2();
	void sound();
	void draw();
	int getWidth();
	int getType();
	cDinosaur();
	~cDinosaur();
};
#endif 
