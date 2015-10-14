#pragma once
#include "Color.h"

class GraphicEngine
{
public:
	virtual void drawPoint(double, double, Color) = 0;
	virtual void drawCircle(double, double, double, Color) = 0;
	virtual void drawLine(double, double, double, double, Color) = 0;
	virtual Color getBackgroundColor() = 0;
};