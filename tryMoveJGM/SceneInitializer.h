#pragma once
#include "Scene.h"

class Actor;

class SceneInitializer
{
public:
    virtual void initialize(Scene*) = 0;
    virtual ~SceneInitializer(){};
};
