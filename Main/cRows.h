#ifndef cRow_h
#define cRow_h

#include <vector>
#include "cOneRow.h"

using namespace std;

class cRows
{
private:
	vector <cOneRow*> subRows;
public:
	cRows();
	~cRows() = default;
	bool pushEnemy(int row, animal_vehical* enemy); //  push a new enemy to a row
	void pushRow(cOneRow*);
	vector <animal_vehical*> listEnemy(); // return all enemies from all rowsgit ad
	vector <cOneRow*> listRow();
	int moveToNextState(int t);
	void redrawState();

};

#endif // cRows