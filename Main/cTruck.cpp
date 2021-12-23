#include "cTruck.h"
using namespace std;

cTruck::cTruck(cPosition pos) : animal_vehical(pos) {
	int color = 1;
	TextColor(color);
	a = new char* [3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[8];
	}

	a[0][0] = (char)218, ColorCode_Blue;
	for (int i = 1; i < 7; i++)
		a[0][i] = char(240), ColorCode_Blue;
	a[0][7] = (char)191, ColorCode_Blue;

	a[1][0] = (char)179, ColorCode_Blue;
	for (int i = 1; i < 8; i++)
	{
		if (i == 6)a[1][i] = '<>';
		else if (i == 7)a[1][i] = (char)179, ColorCode_Blue;
		else
			a[1][i] = ' ', ColorCode_Blue;
	}

	a[2][0] = (char)192, ColorCode_Blue;
	for (int i = 1; i < 7; i++) {
		if (i == 1 || i == 6)a[2][i] = 'O', ColorCode_Blue;
		else
			a[2][i] = (char)240, ColorCode_Blue;
	}
	a[2][7] = (char)217, ColorCode_Blue;

};


char** cTruck::array2()
{

	return a;
}

void cTruck::sound()
{
	PlaySound(TEXT("carstarthonkbackfire.wav"), NULL, SND_ASYNC);
}

cTruck::cTruck()
{
	int color = 1;
	TextColor(color);
	a = new char* [3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[8];
	}

	a[0][0] = (char)218, ColorCode_Blue;
	for (int i = 1; i < 7; i++)
		a[0][i] = char(240), ColorCode_Blue;
	a[0][7] = (char)191, ColorCode_Blue;

	a[1][0] = (char)179, ColorCode_Blue;
	for (int i = 1; i < 8; i++)
	{
		if (i == 6)a[1][i] = '<>';
		else if (i == 7)a[1][i] = (char)179, ColorCode_Blue;
		else
			a[1][i] = ' ', ColorCode_Blue;
	}

	a[2][0] = (char)192, ColorCode_Blue;
	for (int i = 1; i < 7; i++) {
		if (i == 1 || i == 6)a[2][i] = 'O', ColorCode_Blue;
		else
			a[2][i] = (char)240, ColorCode_Blue;
	}
	a[2][7] = (char)217, ColorCode_Blue;

}

cTruck::~cTruck()
{
	for (int i = 0; i < 3; i++)
		delete[] a[i];
	delete[] a;
}

void cTruck::draw()
{
	int color = 1;
	TextColor(color);

	a[0][0] = (char)218, ColorCode_Blue;
	for (int i = 1; i < 7; i++)
		a[0][i] = char(240), ColorCode_Blue;
	a[0][7] = (char)191, ColorCode_Blue;

	a[1][0] = (char)179, ColorCode_Blue;
	for (int i = 1; i < 8; i++)
	{
		if (i == 6)a[1][i] = '<>';
		else if (i == 7)a[1][i] = (char)179, ColorCode_Blue;
		else
			a[1][i] = ' ', ColorCode_Blue;
	}

	a[2][0] = (char)192, ColorCode_Blue;
	for (int i = 1; i < 7; i++) {
		if (i == 1 || i == 6)a[2][i] = 'O', ColorCode_Blue;
		else
			a[2][i] = (char)240, ColorCode_Blue;
	}
	a[2][7] = (char)217, ColorCode_Blue;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
}

int cTruck::getType()
{
	return 4;
}

int cTruck::getWidth()
{
	return 8;
}