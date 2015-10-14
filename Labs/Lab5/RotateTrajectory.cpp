#pragma once
#include <conio.h>
#include <math.h>
#include "RotateTrajectory.h"

RotateTrajectory::RotateTrajectory()
{
	_centerX = 0.0;
	_centerY = 0.0;
}

RotateTrajectory::RotateTrajectory(double x, double y)
{
	_centerX = x;
	_centerY = y;
}


Vector2D RotateTrajectory::next(Vector2D prevPoint)
{
	Vector2D curr = Vector2D(
		((prevPoint.X - _centerX) * cos(0.1) - (prevPoint.Y - _centerY) * sin(0.1)) + _centerX,
		((prevPoint.X - _centerX) * sin(0.1) + (prevPoint.Y - _centerY) * cos(0.1)) + _centerY
		);
	return curr;
}

bool RotateTrajectory::hasNext()
{
	if (!_kbhit())
		return true;

	return _getch() != 27;
}

void RotateTrajectory::reset()
{
	// do nothing
}