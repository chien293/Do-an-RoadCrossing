#pragma once
#ifndef cConsole_
#define cConsole_


#include<iostream>
using namespace std;
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include <string.h>

#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15

#define default_ColorCode		7


#define key_Up		72
#define key_Down	80
#define key_Left	75
#define key_Right	77

class Console
{
private:
	int m_width;
	int m_height;
public:

};

void showCursor();
void FixConsoleWindow();
void gotoXY(int x, int y);
void hideCursor();
void clrscr();

void textcolor(int x);
int getSize();
#endif // !Console_
