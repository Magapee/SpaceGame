#pragma once
#include "Actor.h"

class Wall : public Actor
{
private:
public:
	virtual void initialize() override;
	virtual void step() override;
	virtual void set(int, int);
};