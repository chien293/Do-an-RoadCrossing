#include "cMap.h"
#include "cMap.h"
#include "cConsole.h"

void cMap::resetMap() {
	cout << "This is resetMap" << endl;
	for (int i = 0; i <= width + 1; i++)
	{
		map[0][i] = map[height + 1][i] = '-';
	}
	for (int i = 1; i <= height; ++i) {
		map[i][0] = map[i][width + 1] = '|';
		for (int j = 1; j <= width; ++j)
		{
			map[i][j] = ' ';
		}
	}
}
cMap::cMap()
{
	int f = 0, e = width - 1, ii = 0;
	for (int i = 1; i < width; i++)
	{
		map[0][i] = map[3][i] = map[6][i] = map[9][i] = map[12][i] = map[15][i] = map[18][i] = char(196);
		if (i < width - 1)
		{
			map[1][i] = ' '; map[2][i] = ' '; map[4][i] = ' '; map[5][i] = ' ';
			map[7][i] = ' '; map[8][i] = ' '; map[10][i] = ' '; map[11][i] = ' ';
			map[13][i] = ' '; map[14][i] = ' '; map[16][i] = ' '; map[17][i] = ' ';
		}

	}
	map[0][0] = char(218);
	map[0][width - 1] = char(191);
	for (int i = 1; i < 19; i++)
	{
		map[i][f] = char(179);
		map[i][e] = char(179);
	}
	map[3][0] = char(195); map[6][0] = char(195); map[9][0] = char(195);
	map[12][0] = char(195); map[15][0] = char(195); map[18][0] = char(192);
	map[3][e] = char(180); map[6][e] = char(180); map[9][e] = char(180);
	map[12][e] = char(180); map[15][e] = char(180); map[18][e] = char(217);
}
void cMap::printMap()
{
	int row = 10;
	int col = 50;
	gotoXY(col, row);
	for (int i = 0; i < height; ++i)
	{
		cout << "  ";
		for (int j = 0; j < width; ++j)
		{
			cout << map[i][j];
		}
		gotoXY(50, ++row);
	}

	gotoXY(125, 12); cout << "---RoadCrossing---";
	gotoXY(125, 16); cout << "[ W ]: UP" << endl;
	gotoXY(125, 17); cout << "[ S ]: DOWN" << endl;
	gotoXY(125, 18); cout << "[ A ]: LEFT" << endl;
	gotoXY(125, 19); cout << "[ D ]: RIGHT" << endl;
	gotoXY(125, 22); cout << "[ L ]: Save game" << endl;
	gotoXY(125, 23); cout << "[ T ]: Load game" << endl;
	gotoXY(125, 24); cout << "[ P ]: Pause game/Menu" << endl;
}
void cMap::drawTitle()
{
	int row = 1;
	int col = 45;
	int i, j;
	for (i = 0; i < 7; ++i)
	{
		gotoXY(col, row++);
		for (j = 0; j < 82; ++j)
		{
			cout << TITLE[i][j];
		}
	}

}




