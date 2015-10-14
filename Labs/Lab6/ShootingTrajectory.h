#pragma once
#include "..\Lab3\Trajectory.h"

class ShootingTrajectory : public Trajectory
{
public:
	ShootingTrajectory(double, double);
	virtual Vector2D next(Vector2D);
	virtual bool hasNext();
	virtual void reset();

private:
	double _width, _height;
	bool left;

private:
	static int random(int a, int b);
};