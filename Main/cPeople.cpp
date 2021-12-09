#include "cPeople.h"
#include"cConsole.h"
#include"cPosition.h"

void cPeople::killPlayer() {

	isDead = true;

}

char** cPeople::array2() {

	return a;

}

char** cPeople::emptyShape() {
	return emptyPlayer;
}

cPosition cPeople::getPos() {
	return pos;
}

int cPeople::getX() {
	return pos.getX();
}

int cPeople::getY() {
	return pos.getY();
}

int cPeople::getHeight() {

	return height;

}

int cPeople::getWidth() {

	return width;

}

void cPeople::Up() {
	sound();
	if (pos.getX() <= 2) return;
	pos.setPos(pos.getX() - 2, pos.getY());
}

void cPeople::Down() {
	sound();
	if (pos.getX() + 2 > 20) return;
	pos.setPos(pos.getX() + 2, pos.getY());
}

void cPeople::Left() {
	sound();
	if (pos.getY() <= LEFTMAP) return;
	pos.setPos(pos.getX(), pos.getY() - 1);
}

void cPeople::Right() {
	sound();
	if (pos.getY() + 2 >= RIGHTMAP) return;
	pos.setPos(pos.getX(), pos.getY() + 1);
}

bool cPeople::checkIsDead() {
	return isDead;
}

cPeople::cPeople() : isDead(false) {
	int color = rand() % 7 + 9;
	TextColor(color);
	pos.setPos(20, 28);
	a = new char* [3];
	emptyPlayer = new char* [3];
	for (int i = 0; i < 3; ++i) {
		emptyPlayer[i] = new char[5];
		for (int j = 0; j < 5; ++j) {
			emptyPlayer[i][j] = ' ';
		}
	}
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[5];
	}

	for (int i = 0; i < 5; i++) {
		if (i == 2)
			a[0][i] = 'O';
		else
			a[0][i] = ' ';
	}
	
	for (int i = 0; i < 5; i++) {
		if (i == 0)	a[1][i] = '/';
		if (i == 4)	a[1][i] = '\\';
	}

	for (int i = 0; i < 5; i++) {
		if (i == 1)	a[2][i] = '/';
		else if (i == 3)	a[2][i] = '\\';
		else a[2][i] = ' ';
	}
}

cPeople::cPeople(cPosition pos) : isDead(false), pos(pos) {
	int color = rand() % 7 + 9;
	TextColor(color);
	a = new char* [3];
	emptyPlayer = new char* [3];
	for (int i = 0; i < 3; ++i) {
		emptyPlayer[i] = new char[5];
		for (int j = 0; j < 5; ++j) {
			emptyPlayer[i][j] = ' ';
		}
	}
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[5];
	}
	
	for (int i = 0; i < 5; i++) {
		if (i == 2)
			a[0][i] = 'O';
		else
			a[0][i] = ' ';
	}
	
	for (int i = 0; i < 5; i++) {
		if (i == 0)	a[1][i] = '/';
		if (i == 4)	a[1][i] = '\\';
	}

	for (int i = 0; i < 5; i++) {
		if (i == 1)	a[2][i] = '/';
		else if (i == 3)	a[2][i] = '\\';
		else a[2][i] = ' ';
	}

}

cPeople::~cPeople()
{
	for (int i = 0; i < 3; i++) {
		delete[] a[i];
		delete[] emptyPlayer[i];
	}
	delete[] a;
	delete[] emptyPlayer;
}


bool cPeople::Impact(cPosition pos, int w, int h) {
	
	if (w == 5) {
		//crash while Car/Truck on the right
		if (this->getX() == pos.getX()) {
			if (this->getY() <= pos.getY() && max(getY(), pos.getY()) <= min(getY() + getWidth(), pos.getY()))
			{
				return true;
			}
			if (this->getY() >= pos.getY() && getY() - pos.getY() <= 3)
				return true;
		}
	}
	if (w == 3) {
		if (this->getX() == pos.getX())
		{
			if (this->getY() >= pos.getY() && pos.getY() + w  >= this->getY()) // crash while bird on the left
			{
				return true;
			}
			if (getY() <= pos.getY() && pos.getY() - getY() <= 2) //crash while bird on the right
				return true;
		}
	}
	else
		if (this->getX() == pos.getX() && max(getY(), pos.getY()) <= min(getY() + getWidth() , pos.getY())) {
			return true;
		}
	return false;
}


void cPeople::sound()
{
	if (!constantVar::isMute && !isDead)
		PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
}
