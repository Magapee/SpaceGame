#include "Wall.h"
#include "Sprite.h"

void Wall::initialize(){}

void Wall::step(){}

void Wall::set(int a, int b)
{
	//this->changeCoord(a, b, 0);
	auto tempCoord = new Coord;
	tempCoord->angle = 0;
	tempCoord->x = a;
	tempCoord->y = b;
	this->setCoord(tempCoord);
	delete tempCoord;
}