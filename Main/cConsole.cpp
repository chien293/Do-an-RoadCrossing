#include <stdio.h>
#include <conio.h>
#include "cConsole.h"
using namespace std;

int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)	// special key
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return key_none;
	}

	return key_none;
}

void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}
//screen: goto x,y
void gotoXY(int column, int line)
{
	ShowConsoleCursor(false);
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//screen: get x
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
//screen: get y
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void FixConsoleWindow() 
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void DisableMouse() 
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void drawTitle()
{
	const char TITLE[30][90] = { {218,196,196,196,196,'\\',32, 32,32,32,32,32,32,32,32,    32,32,32,32,32,32,32,		  32,32,32,32,32,'_',32,	   32,32,32,32,32,  32,32,32,'_','_','_','_',32,	32,32,32,32,32,32,		 32,32,32,32,32,32,32,		 32,32,32,32,32,	   32,32,32,32,32,		 32,'_',32,	  32,32,32,32,32,32,32,		  32,32,32},
									 { 179,32,32,'_','_',32,92,32,	 32,32,32,32,32,32,32,		 32,32,32,32,32,32,32,		  32,32,32,32,179,32,179,	   32,32,32,32,32,  32,32,'/',32,218,196,196,179,	32,32,32,32,32,32,		 32,32,32,32,32,32,32,		 32,32,32,32,32,	   32,32,32,32,32,		 179,'_',179,	 32,32,32,32,32,32,32,	  32,32,32,32},
									 { 179,32,179,'_','_',179,32,')', 32,32,95,95,95,32,32,	     32,32,'_','_','_','_',32,	  32,32,'_','_',179,32,179,	   32,32,32,32,32,  32,'/',32,32,179,32,32,32,		32,'_','_','_','_',32,	 32,32,'_','_','_',32,32,	 218,196,196,196,32,   218,196,196,196,32,	 32,'_',32,   '_','_','_','_','_',32,	  32,32,'_','_','_','_','_','_',32,32},
									 { 179,32,32,'_',32,32,'/',32,	 32, '/',32,'_',32,'\\',32,	 32,'/',32,'_',32,32,179,	  32,'/',32,'_',32,32,179,	   32,32,32,32,32,  32,179,32,32,179,32,32,32,		'/',32,32,'_','_',179, 32,'/',32,'_',32,'\\',32,	 179,32,32,32,32,      179,32,32,32,32,      179,32,179,  '|',32,32,'_',32,'\\',32,   32,'/',32,'_',32,32,179,32},
									 { 179,32,179,32,92,32,92,32,	 40,32,179,'_',179,32,')',	 '(',32,179,'_',179,32,179,	  '(',32,179,'_',179,32,179,   32,32,32,32,32,  32,'\\',32,32,179,'_','_','_',  179,32,179,32,32,32,	 '(',32,179,'_',179,32,')',  179,196,196,196,191,  179,196,196,196,191, 179,32,179,  '|',32,179,32,'|',32,'|',	  '(',32,179,'_',179,32,179,32},
									 { 179,'_',179,32,32,92,'_',92,	 32,'\\','_','_','_','/',32, 32,'\\','_','_','_','_',179, 32,'\\','_','_','_','_',179, 32,32,32,32,32,  32,32,'\\','_','_','_','_',179, 179,'_',179,32,32,32,	 32,'\\','_','_','_','/',32, '_','_','_','_',217,  '_','_','_','_',217,  179,'_',179, '|','_',179,32,'|','_','|', 32,'\\','_','_','.',32,179,32},
									 { 32,32,32,32,32,32,32,32,		 32,32,32,32,32,32,32,		 32,32,32,32,32,32,32,		  32,32,32,32,32,32,32,		   32,32,32,32,32,  32,32,32,32,32,32,32,32,		32,32,32,32,32,32,		 32,32,32,32,32,32,32,		 32,32,32,32,32,	   32,32,32,32,32,		 32,32,32,	  32,32,32,32,32,32,32,		  32,179,'_','_','_','/',32} };

	int MAX_X = 7, MAX_Y = 82;
	char prevTITLE[7][82];
	std::memset((char*)prevTITLE, 0, MAX_X * MAX_Y);

	// ...
	int row = 30;
	int col = 1;
	for (int x = 0; x != 7; x++)
	{
		gotoXY(col, row++);
		for (int y = 0; y != 82; y++)
		{
			if (TITLE[x][y] == prevTITLE[x][y])
			{
				continue;
			}

			//setCursorPosition(col, row++);
			cout << TITLE[x][y];
		}
	}
	cout.flush();
	memcpy((char*)TITLE, (char const*)TITLE, MAX_X * MAX_Y);

}