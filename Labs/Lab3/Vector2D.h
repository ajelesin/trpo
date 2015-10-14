#pragma once

class Vector2D
{
public:
	Vector2D() :X(0), Y(0){};
	Vector2D(double x, double y) :X(x), Y(y){};
	double X, Y;
};