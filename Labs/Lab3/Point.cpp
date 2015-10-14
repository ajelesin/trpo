#pragma once
#include "Point.h"

Point::Point()
{
	_x = 0;
	_y = 0;
	_color = Color();
}

Point::Point(double x, double y, Color color)
{
	_x = x;
	_y = y;
	_color = color;
}

void Point::show(GraphicEngine& engine)
{
	engine.drawPoint(_x, _y, _color);
}

void Point::hide(GraphicEngine& engine)
{
	Color backgroundColor = engine.getBackgroundColor();
	engine.drawPoint(_x, _y, backgroundColor);
}

void Point::move(GraphicEngine& engine, Trajectory& trajectory)
{
	hide(engine);
	Vector2D result = trajectory.next(Vector2D(_x, _y));
	_x = result.X;
	_y = result.Y;
	show(engine);
}

void Point::save(FILE* file)
{
	char buff[20];
	strcpy(buff, _color.toString());
	fprintf(file, "POINT %f %f %s", _x, _y, buff);
}