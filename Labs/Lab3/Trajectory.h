#pragma once
#include "Vector2D.h"

class Trajectory
{
public:
	virtual Vector2D next(Vector2D) = 0;
	virtual bool hasNext() = 0;
	virtual void reset() = 0;
};