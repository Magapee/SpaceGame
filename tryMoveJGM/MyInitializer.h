#pragma once
#include <vector>
#include "SceneInitializer.h"
#include "MyActor.h"

class MyInitializer : public SceneInitializer
{
    virtual void initialize(Scene*) override;
    ~MyInitializer() override;
};