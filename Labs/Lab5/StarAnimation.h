#pragma once
#include "..\Lab3\FigureAnimation.h"
#include "..\Lab3\GraphicEngine.h"
#define PI 3.14159265

class StarAnimation : public FigureAnimation
{
public:
	StarAnimation(Trajectory*, GraphicEngine*, double, double);
	virtual Figure* getFigure();

private:
	double _centerX, _centerY;
	const double _r = 50, _R = 100;
};