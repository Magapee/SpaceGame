#pragma once
#include "Coord.h"
#include <memory>


class Camera
{
private:
    float scale = 1;
    std::shared_ptr<Coord> coordinates = nullptr;
public:
    Camera();
    void setCoord(Coord* position);
    void changeCoord(long, long, float);
    Coord* getPosition();
    void changeScale(float);
};
