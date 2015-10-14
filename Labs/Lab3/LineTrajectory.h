#pragma once
#include "Trajectory.h"
#include "Vector2D.h"

class LineTrajectory : public Trajectory
{
public:
	Vector2D next(Vector2D);
	bool hasNext();
	void reset();
};