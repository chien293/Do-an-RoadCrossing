#ifndef cLevel_h
#define cLevel_h
#include <algorithm>
#include "cPosition.h"
#include "animal_vehical.h"
#include "cBird.h"
#include "cCar.h"
#include "cDinosaur.h"
#include "cTruck.h"
#include "cPeople.h"
class cLevel
{
private:
	int level;
	int maxEnemy, minSpeed, maxSpeed, nEnemy;
	int nRow;
	const int maxLevel = 5;
	//  int nColumn;
	void initialize();
public:
	cLevel();
	cLevel(int level, int nEnemy);
	//  ~cLevel();
	int getLevel();
	bool newLevel(int lv);
	bool nextLevel();
	int getMaxSpeed();
	int getMinSpeed();
	animal_vehical* randNewEnemy(cPosition pos);
	animal_vehical* getNewEnemy(cPosition pos, int type);
	void decNEnemy(int d);
};

#endif 