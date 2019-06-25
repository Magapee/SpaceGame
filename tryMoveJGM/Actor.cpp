#include "Actor.h"


Actor::Actor()
{
    this->coordinates.x = 0;
    this->coordinates.y = 0;
    this->coordinates.angle = 0;
}



void Actor::changeCoord(long x, long y, float angle)
{
    this->coordinates.x += x;
    this->coordinates.y += y;
    this->coordinates.angle += angle;
}



Coord Actor::getCoord()
{
    return this->coordinates;
}


void Actor::setCoord(Coord* newCoordinates)
{
    this->coordinates = (*newCoordinates);
}

void Actor::setSprite(Sprite* newSprite)
{
	if (newSprite != nullptr)
		this->sprite = newSprite;
	else
		assert(0);
}

void Actor::render(Camera* activeCamera)
{

    if(this->sprite != nullptr)
    {
        this->sprite->render(&(this->coordinates), activeCamera);
    }
}
