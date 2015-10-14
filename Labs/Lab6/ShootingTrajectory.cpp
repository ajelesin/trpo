#pragma once
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "ShootingTrajectory.h"

ShootingTrajectory::ShootingTrajectory(double width, double height)
{
	srand(time(NULL));
	_width = width;
	_height = height;
	left = false;
}

Vector2D ShootingTrajectory::next(Vector2D prevPoint)
{
	double dx = random(0, 5) - random(0, 2);
	double dy = 5;

	Vector2D newPoint;
	newPoint.X = prevPoint.X + (left ? -dx : dx);
	newPoint.Y = prevPoint.Y + dy;

	if (newPoint.X > _width)
		newPoint.X = 1;
	if (newPoint.Y > _height)
		newPoint.Y = 1;
	if (newPoint.X <= 0)
		newPoint.X = _width - 1;

	return newPoint;
}

bool ShootingTrajectory::hasNext()
{
	if (!_kbhit())
		return true;

	int key = _getch();
	if (key == 224){
		int key2 = _getch();
		if (key2 == 77){
			left = false;
			return true;
		}
		else if (key2 == 75){
			left = true;
			return true;
		}
	}

	return key != 27;
}

void ShootingTrajectory::reset()
{
	// do nothing
}

int ShootingTrajectory::random(int a, int b)
{
	return (rand() % (b - a)) + a;
}
