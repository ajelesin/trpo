#pragma once
#include "FigureAnimation.h"
#include "GraphicEngine.h"

class CarAnimation:public FigureAnimation
{
public:
	CarAnimation(Trajectory*, GraphicEngine*, double, double);
	virtual Figure* getFigure();

private:
	double _centerX = 100, _centerY = 100;
};