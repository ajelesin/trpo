#pragma once
#include "Segment.h"

Segment::Segment()
{
	_x1 = _x2 = _y1 = _y2 = 0;
	_color = Color();
}

Segment::Segment(double x1, double y1, double x2, double y2, Color color)
{
	_x1 = x1;
	_y1 = y1;
	_x2 = x2;
	_y2 = y2;
	_color = color;
}

void Segment::show(GraphicEngine& engine)
{
	engine.drawLine(_x1, _y1, _x2, _y2, _color);
}

void Segment::hide(GraphicEngine& engine)
{
	Color backgroundColor = engine.getBackgroundColor();
	engine.drawLine(_x1, _y1, _x2, _y2, backgroundColor);
}

void Segment::move(GraphicEngine& engine, Trajectory& trajectory)
{
	hide(engine);
	Vector2D startPoint = trajectory.next(Vector2D(_x1, _y1));
	Vector2D endPoint = trajectory.next(Vector2D(_x2, _y2));
	_x1 = startPoint.X;
	_x2 = endPoint.X;
	_y1 = startPoint.Y;
	_y2 = endPoint.Y;
	show(engine);
}

void Segment::save(FILE* file)
{
	char buff[20];
	strcpy(buff, _color.toString());
	fprintf(file, "SEGMENT %f %f %f %f %s", _x1, _y1, _x2, _y2, buff);
}