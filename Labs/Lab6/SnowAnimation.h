#pragma once
#include "..\Lab3\FigureAnimation.h"
#include "..\Lab3\GraphicEngine.h"
#define PI 3.14159265

class SnowAnimation : public FigureAnimation
{
public:
	SnowAnimation(Trajectory*, GraphicEngine*, double, double, int);
	virtual Figure* getFigure();

private:
	double _width, _height;
	int _amount;

private:
	static int random(int a, int b);
};