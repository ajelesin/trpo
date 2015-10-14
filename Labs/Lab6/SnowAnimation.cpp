#pragma once
#include <stdlib.h>
#include <time.h>
#include "SnowAnimation.h"
#include "..\Lab3\Segment.h"
#include "..\Lab3\Color.cpp"
#include "..\Lab3\Figure.cpp"
#include "..\Lab3\FigureAnimation.cpp"
#include "..\Lab3\Segment.cpp"
#include "..\Lab3\Circle.cpp"
#include "..\Lab3\Point.cpp"

SnowAnimation::SnowAnimation(
	Trajectory* trajectory, GraphicEngine* graphicEngine,
	double width, double height, int amount)
	:FigureAnimation(trajectory, graphicEngine)
{
	srand(time(NULL));
	_width = width;
	_height = height;
	_amount = amount;
}

Figure* SnowAnimation::getFigure()
{

	double rad72 = 72.0 * PI / 180.0;
	double rad36 = 36.0 * PI / 180.0;

	Figure* showfall = new Figure();
	for (int i = 0; i < _amount; i++){
		showfall->add(new Point(random(0, _width), random(0, _height), Color(255, 255, 255)));
	}

	return showfall;
}

int SnowAnimation::random(int a, int b)
{
	return (rand() % (b - a)) + a;
}
