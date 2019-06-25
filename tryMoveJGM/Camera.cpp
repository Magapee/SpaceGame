#include "Camera.h"


void Camera::setCoord(Coord* position)
{
    this->coordinates->x = position->x;
    this->coordinates->y = position->y;
    this->coordinates->angle = position->angle;
}

void Camera::changeCoord(long x, long y, float angle)
{
    this->coordinates->x += x;
    this->coordinates->y += y;
    this->coordinates->angle += angle;
}

Coord* Camera::getPosition()
{
    return this->coordinates.get();
}

void Camera::changeScale(float newScale)
{
    this->scale = newScale;
}

Camera::Camera()
{
    this->coordinates.reset(new Coord);
    this->coordinates->x = 0;
    this->coordinates->y = 0;
    this->coordinates->angle = 0;
}
