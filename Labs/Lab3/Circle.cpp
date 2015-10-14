#pragma once
#include "Circle.h"

Circle::Circle()
	: Point()
{
	_r = 1;
}

Circle::Circle(double x, double y, double r, Color color)
	: Point(x, y, color)
{
	_r = r;
}

void Circle::show(GraphicEngine& engine)
{
	engine.drawCircle(_x, _y, _r, _color);
}

void Circle::hide(GraphicEngine& engine)
{
	Color backgroundColor = engine.getBackgroundColor();
	engine.drawCircle(_x, _y, _r, backgroundColor);
}

void Circle::save(FILE* file)
{
	char buff[20];
	strcpy(buff, _color.toString());
	fprintf(file, "CIRCLE %f %f %f %s", _x, _y, _r, buff);
}