#pragma once
#include "Actor.h"

class CameraController : public Actor
{
private:

public:
    virtual void initialize() override;
    virtual void step() override;
};
