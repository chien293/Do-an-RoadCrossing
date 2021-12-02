#include "cBird.h"
#include"cConsole.h"
using namespace std;


cBird::~cBird()
{
	for (int i = 0; i < 3; i++)
		delete[] a[i];
	delete[] a;
}

int cBird::getType()
{
	return 0;
}

int cBird::getWidth()
{
	return 6;
}

char** cBird::array2() {

	return a;
}

void cBird::sound() {
	PlaySound(TEXT("boc4.wav"), NULL, SND_ASYNC);
}

cBird::cBird(cPosition pos) : animal_vehical(pos) {
	int color = 10;
	TextColor(color);
	a = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[6];
	}
	a[0][0] = ' ';
	for (int i = 1; i < 6; i++)
	{
		if (i == 2 || i == 4)a[0][i] = '.', ColorCode_DarkYellow;
		else
			a[0][i] = '^', ColorCode_DarkYellow;
	}

	a[1][0] = '{', ColorCode_DarkYellow;
	a[1][1] = '0', ColorCode_DarkYellow;
	a[1][2] = ' ', ColorCode_DarkYellow;
	a[1][3] = '>', ColorCode_DarkYellow;
	a[1][4] = ' ', ColorCode_DarkYellow;
	a[1][5] = '3', ColorCode_DarkYellow;
	
	a[2][0] = ' ', ColorCode_DarkYellow;
	a[2][1] = 'v', ColorCode_DarkYellow;
	a[2][2] = ' ', ColorCode_DarkYellow;
	a[2][3] = ' ', ColorCode_DarkYellow;
	a[2][4] = 'v', ColorCode_DarkYellow;
	a[2][5] = ' ', ColorCode_DarkYellow;
}


void cBird::draw() {
	int color = 10;
	TextColor(color);
	a[0][0] = ' ';
	for (int i = 1; i < 6; i++)
	{
		if (i == 2 || i == 4)a[0][i] = '.', ColorCode_DarkYellow;
		else
			a[0][i] = '^', ColorCode_DarkYellow;
	}
	
	a[1][0] = '{', ColorCode_DarkYellow;
	a[1][1] = '0', ColorCode_DarkYellow;
	a[1][2] = ' ', ColorCode_DarkYellow;
	a[1][3] = '>', ColorCode_DarkYellow;
	a[1][4] = ' ', ColorCode_DarkYellow;
	a[1][5] = '3', ColorCode_DarkYellow;

	a[2][0] = ' ', ColorCode_DarkYellow;
	a[2][1] = 'v', ColorCode_DarkYellow;
	a[2][2] = ' ', ColorCode_DarkYellow;
	a[2][3] = ' ', ColorCode_DarkYellow;
	a[2][4] = 'v', ColorCode_DarkYellow;
	a[2][5] = ' ', ColorCode_DarkYellow;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
}

cBird::cBird()
{
	int color = 10;
	TextColor(color);
	a = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[6];
	}

	a[0][0] = ' ';
	for (int i = 1; i < 6; i++)
	{
		if (i == 2 || i == 4)a[0][i] = '.', ColorCode_DarkYellow;
		else
			a[0][i] = '^', ColorCode_DarkYellow;
	}

	a[1][0] = '{', ColorCode_DarkYellow;
	a[1][1] = '0', ColorCode_DarkYellow;
	a[1][2] = ' ', ColorCode_DarkYellow;
	a[1][3] = '>', ColorCode_DarkYellow;
	a[1][4] = ' ', ColorCode_DarkYellow;
	a[1][5] = '3', ColorCode_DarkYellow;

	a[2][0] = ' ', ColorCode_DarkYellow;
	a[2][1] = 'v', ColorCode_DarkYellow;
	a[2][2] = ' ', ColorCode_DarkYellow;
	a[2][3] = ' ', ColorCode_DarkYellow;
	a[2][4] = 'v', ColorCode_DarkYellow;
	a[2][5] = ' ', ColorCode_DarkYellow;
}
