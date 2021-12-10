#include "cLevel.h"

cLevel::cLevel() 
{
	level = 1;
	nEnemy = 0;
	initialize();
}

cLevel::cLevel(int level, int nEnemy) 
{
	this->level = level;
	this->nEnemy = nEnemy;
	initialize();
}

void cLevel::initialize() 
{
	int difficulty = 20, maxE = 20;
	if (constantVar::isHard)
	{
		difficulty = 20, maxE = 40;
		maxEnemy = 40;
		maxSpeed = difficulty - level * 2;  //speed nho toc do thuc hien nhanh
		minSpeed = difficulty - level * 1;

	}
	else
	{
		difficulty = 10, maxE = 20;
		maxEnemy = 20;
		maxSpeed = difficulty - level * 2;  //speed nho toc do thuc hien nhanh
		minSpeed = difficulty - level * 1;
	}
	nRow = 5;
	
}

int cLevel::getLevel() 
{
	return level;
}

bool cLevel::newLevel(int lv)
{
	if (lv > maxLevel) return false;
	level = lv;
	nEnemy = 0;
	initialize();
	return true;
}

bool cLevel::nextLevel() 
{
	if (level == maxLevel) return false;
	++level;
	nEnemy = 0;
	return true;
}

int cLevel::getMaxSpeed() 
{
	return maxSpeed;
}

int cLevel::getMinSpeed()
{
	return minSpeed;
}

animal_vehical* cLevel::randNewEnemy(cPosition pos)
{
	if (nEnemy == maxEnemy) return NULL;
	if ((nEnemy < (maxEnemy / 2)) || (rand() % 3)) 
	{
		++nEnemy;
		animal_vehical* pEnemy = NULL;
		int type = rand() % 4;
		switch (type)
		{
		case 0: {
			pEnemy = new cBird(pos);
			break;
		}
		case 1: {
			pEnemy = new cCar(pos);
			break;
		}
		case 2: {
			pEnemy = new cDinosaur(pos);
			break;
		}
		default:
			pEnemy = new cTruck(pos);
			break;
		}
		//    pEnemy = new cEnemy(pos); // random type of enemy
		return pEnemy;
	}
	return NULL;
}

animal_vehical* cLevel::getNewEnemy(cPosition pos, int type)
{
	++nEnemy;
	animal_vehical* pEnemy = NULL;
	switch (type)
	{
	case 0: {
		pEnemy = new cBird(pos);
		break;
	}
	case 1: {
		pEnemy = new cCar(pos);
		break;
	}
	case 2: {
		pEnemy = new cDinosaur(pos);
		break;
	}
	default:
		pEnemy = new cTruck(pos);
		break;
	}
	return pEnemy;
}

void cLevel::decNEnemy(int d) {
	nEnemy -= d;
}
