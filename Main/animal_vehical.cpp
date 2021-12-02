#include "animal_vehical.h"

animal_vehical::animal_vehical() : outMap(false) {}

animal_vehical::animal_vehical(cPosition pos) : point(pos), outMap(false) {}

cPosition animal_vehical::getPos() {

	return point;

}

int animal_vehical::getX() {
	return point.getX();
}

int animal_vehical::getY() {
	return point.getY();
}

bool animal_vehical::isOutOfMap() {

	return outMap;

}

void animal_vehical::goOutMap() {

	outMap = true;

}

int animal_vehical::getWidth() {

	return 5;

}

int animal_vehical::getHeight() {

	return 3;

}

void animal_vehical::updatePosition(int dx, int dy) {
	point.setPos(point.getX() + dx, point.getY() + dy);
}
