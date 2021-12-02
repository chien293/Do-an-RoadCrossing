#include "cCar.h"
using namespace std;

cCar::cCar(cPosition pos) : animal_vehical(pos) {
	int color = 4;
	TextColor(color);
	a = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[8];
	}
	
	for (int i = 0; i < 8; i++) {
		if (i == 0 || i == 6 || i == 7 || i == 8)
			a[0][i] = ' ', ColorCode_Cyan;
		else
			a[0][i] = '=', ColorCode_Cyan;
	}

	a[1][0] = '/';
	for (int i = 1; i < 8; i++) {
		if (i>0 && i<5)	a[1][i] = ' ', ColorCode_Cyan;
		if (i == 5)	a[1][5] = char(248), ColorCode_Cyan;
		if (i == 6)	a[1][6] = '\\', ColorCode_Cyan;
		else a[1][i] = ' ', ColorCode_Cyan;
	}

	for (int i = 0; i < 7; i++) {
		if (i == 0)a[2][i] = (char)248, ColorCode_Cyan;
		else
			if (i == 1 || i == 5)a[2][i] = 'O', ColorCode_Cyan;
			else
				a[2][i] = '-', ColorCode_Cyan;
	}
	a[2][7] = (char)217, ColorCode_Cyan;
}


cCar::cCar()
{
	int color = 4;
	TextColor(color);
	a = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[8];
	}
	
	for (int i = 0; i < 8; i++) {
		if (i == 0 || i == 6 || i == 7 || i == 8)
			a[0][i] = ' ', ColorCode_Cyan;
		else
			a[0][i] = '=', ColorCode_Cyan;
	}

	a[1][0] = '/';
	for (int i = 1; i < 8; i++) {
		if (i > 0 && i < 5)	a[1][i] = ' ', ColorCode_Cyan;
		if (i == 5)	a[1][5] = char(248), ColorCode_Cyan;
		if (i == 6)	a[1][6] = '\\', ColorCode_Cyan;
		else a[1][i] = ' ', ColorCode_Cyan;
	}

	for (int i = 0; i < 7; i++) {
		if (i == 0)a[2][i] = (char)248, ColorCode_Cyan;
		else
			if (i == 1 || i == 5)a[2][i] = 'O', ColorCode_Cyan;
			else
				a[2][i] = '-', ColorCode_Cyan;
	}
	a[2][7] = (char)217, ColorCode_Cyan;
}

cCar::~cCar()
{
	for (int i = 0; i < 3; i++)
		delete[] a[i];
	delete[] a;
}
char ** cCar::array2()
{

	return a;
}

void cCar::sound()
{
	PlaySound(TEXT("trafficjam.wav"), NULL, SND_ASYNC);
}

void cCar::draw()
{
	int color = 4;
	TextColor(color);
	
	for (int i = 0; i < 8; i++) {
		if (i == 0 || i == 6 || i == 7 || i == 8)
			a[0][i] = ' ', ColorCode_Cyan;
		else
			a[0][i] = '=', ColorCode_Cyan;
	}

	a[1][0] = '/';
	for (int i = 1; i < 8; i++) {
		if (i > 0 && i < 5)	a[1][i] = ' ', ColorCode_Cyan;
		if (i == 5)	a[1][5] = char(248), ColorCode_Cyan;
		if (i == 6)	a[1][6] = '\\', ColorCode_Cyan;
		else a[1][i] = ' ', ColorCode_Cyan;
	}

	for (int i = 0; i < 7; i++) {
		if (i == 0)a[2][i] = (char)248, ColorCode_Cyan;
		else
			if (i == 1 || i == 5)a[2][i] = 'O', ColorCode_Cyan;
			else
				a[2][i] = '-', ColorCode_Cyan;
	}
	a[2][7] = (char)217, ColorCode_Cyan;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}

}

int cCar::getType()
{
	return 1;
}

int cCar::getWidth()
{
	return 8;
}