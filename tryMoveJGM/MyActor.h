#pragma once
#include "Actor.h"
#include <string>
#include <sstream>


class MyActor : public Actor
{
private:
    int speed = 3;
    int x_direction = 0;
    int y_direction = 0;
public:
    virtual void initialize();
    virtual void step();
};
