#include "cDinosaur.h"
using namespace std;

cDinosaur::cDinosaur(cPosition pos) : animal_vehical(pos) {
	
	a = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[6];
	}

	a[0][0] = ' ', ColorCode_DarkPink;
	a[0][1] = ' ', ColorCode_DarkPink;
	a[0][2] = ' ', ColorCode_DarkPink;
	a[0][3] = ' ', ColorCode_DarkPink;
	a[0][4] = (char)177, ColorCode_DarkPink;
	a[0][5] = (char)223, ColorCode_DarkPink;
	
	a[1][0] = (char)223, ColorCode_DarkPink;
	a[1][1] = (char)254, ColorCode_DarkPink;
	a[1][2] = (char)177, ColorCode_DarkPink;
	a[1][3] = (char)177, ColorCode_DarkPink;
	a[1][4] = (char)177, ColorCode_DarkPink;
	a[1][5] = (char)221, ColorCode_DarkPink;
	
	a[2][0] = ' ', ColorCode_DarkPink;
	a[2][1] = '!', ColorCode_DarkPink;
	a[2][2] = '!', ColorCode_DarkPink;
	a[2][3] = ' ', ColorCode_DarkPink;
	a[2][4] = '!', ColorCode_DarkPink;
	a[2][5] = '!', ColorCode_DarkPink;
	int color = 6;
	TextColor(color);
};


char ** cDinosaur::array2() {

	return a;
};
void cDinosaur::sound() {
	PlaySound(TEXT("./Tiger6.wav"), NULL, SND_ASYNC);
};
void cDinosaur::draw() {
	int color = 6;
	TextColor(color);

	a[0][0] = ' ', ColorCode_DarkPink;
	a[0][1] = ' ', ColorCode_DarkPink;
	a[0][2] = ' ', ColorCode_DarkPink;
	a[0][3] = ' ', ColorCode_DarkPink;
	a[0][4] = (char)177, ColorCode_DarkPink;
	a[0][5] = (char)223, ColorCode_DarkPink;

	a[1][0] = (char)223, ColorCode_DarkPink;
	a[1][1] = (char)254, ColorCode_DarkPink;
	a[1][2] = (char)177, ColorCode_DarkPink;
	a[1][3] = (char)177, ColorCode_DarkPink;
	a[1][4] = (char)177, ColorCode_DarkPink;
	a[1][5] = (char)221, ColorCode_DarkPink;

	a[2][0] = ' ', ColorCode_DarkPink;
	a[2][1] = '!', ColorCode_DarkPink;
	a[2][2] = '!', ColorCode_DarkPink;
	a[2][3] = ' ', ColorCode_DarkPink;
	a[2][4] = '!', ColorCode_DarkPink;
	a[2][5] = '!', ColorCode_DarkPink;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
};
cDinosaur::cDinosaur()
{
	int color = 6;
	TextColor(color);
	a = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[6];
	}

	a[0][0] = ' ', ColorCode_DarkPink;
	a[0][1] = ' ', ColorCode_DarkPink;
	a[0][2] = ' ', ColorCode_DarkPink;
	a[0][3] = ' ', ColorCode_DarkPink;
	a[0][4] = (char)177, ColorCode_DarkPink;
	a[0][5] = (char)223, ColorCode_DarkPink;

	a[1][0] = (char)223, ColorCode_DarkPink;
	a[1][1] = (char)254, ColorCode_DarkPink;
	a[1][2] = (char)177, ColorCode_DarkPink;
	a[1][3] = (char)177, ColorCode_DarkPink;
	a[1][4] = (char)177, ColorCode_DarkPink;
	a[1][5] = (char)221, ColorCode_DarkPink;

	a[2][0] = ' ', ColorCode_DarkPink;
	a[2][1] = '!', ColorCode_DarkPink;
	a[2][2] = '!', ColorCode_DarkPink;
	a[2][3] = ' ', ColorCode_DarkPink;
	a[2][4] = '!', ColorCode_DarkPink;
	a[2][5] = '!', ColorCode_DarkPink;
}
cDinosaur::~cDinosaur()
{
	for (int i = 0; i < 3; i++)
		delete[] a[i];
	delete[] a;
}
int cDinosaur::getType()
{
	return 2;
}

int cDinosaur::getWidth()
{
	return 6;
}