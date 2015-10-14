#pragma once
#include <conio.h>
#include "LineTrajectory.h"

Vector2D LineTrajectory::next(Vector2D prevPoint)
{
	Vector2D curr(prevPoint.X + 1.0, prevPoint.Y);
	return curr;
}

bool LineTrajectory::hasNext()
{
	if (!_kbhit())
		return true;

	return _getch() != 27;
}

void LineTrajectory::reset()
{
	// do nothing
}