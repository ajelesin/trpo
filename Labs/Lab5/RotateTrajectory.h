#pragma once
#include "..\Lab3\Trajectory.h"

class RotateTrajectory : public Trajectory
{
public:
	RotateTrajectory();
	RotateTrajectory(double, double);
	virtual Vector2D next(Vector2D);
	virtual bool hasNext();
	virtual void reset();

private:
	double _centerX, _centerY;
};