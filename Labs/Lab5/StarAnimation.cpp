#pragma once
#include "StarAnimation.h"
#include "..\Lab3\Segment.h"
#include "..\Lab3\Color.cpp"
#include "..\Lab3\Figure.cpp"
#include "..\Lab3\FigureAnimation.cpp"
#include "..\Lab3\Segment.cpp"
#include "..\Lab3\Point.cpp"
#include "..\Lab3\Circle.cpp"

StarAnimation::StarAnimation(Trajectory* trajectory, GraphicEngine* graphicEngine, double centerX, double centerY)
	:FigureAnimation(trajectory, graphicEngine)
{
	_centerX = centerX;
	_centerY = centerY;
}

Figure* StarAnimation::getFigure()
{

	double rad72 = 72.0 * PI / 180.0;
	double rad36 = 36.0 * PI / 180.0;

	Figure* star = new Figure();
	star->add(new Segment(
		_r * cos(0 * rad72) + _centerX, _r * sin(0 * rad72) + _centerY,
		_R * cos(rad36 + 0 * rad72) + _centerX, _R * sin(rad36 + 0 * rad72) + _centerY,
		Color(255, 0, 0)
		));
	star->add(new Segment(
		_r * cos(1 * rad72) + _centerX, _r * sin(1 * rad72) + _centerY,
		_R * cos(rad36 + 0 * rad72) + _centerX, _R * sin(rad36 + 0 * rad72) + _centerY,
		Color(255, 0, 0)
		));
	star->add(new Segment(
		_r * cos(1 * rad72) + _centerX, _r * sin(1 * rad72) + _centerY,
		_R * cos(rad36 + 1 * rad72) + _centerX, _R * sin(rad36 + 1 * rad72) + _centerY,
		Color(255, 0, 0)
		));
	star->add(new Segment(
		_r * cos(2 * rad72) + _centerX, _r * sin(2 * rad72) + _centerY,
		_R * cos(rad36 + 1 * rad72) + _centerX, _R * sin(rad36 + 1 * rad72) + _centerY,
		Color(255, 0, 0)
		));
	star->add(new Segment(
		_r * cos(2 * rad72) + _centerX, _r * sin(2 * rad72) + _centerY,
		_R * cos(rad36 + 2 * rad72) + _centerX, _R * sin(rad36 + 2 * rad72) + _centerY,
		Color(255, 0, 0)
		));
	star->add(new Segment(
		_r * cos(3 * rad72) + _centerX, _r * sin(3 * rad72) + _centerY,
		_R * cos(rad36 + 2 * rad72) + _centerX, _R * sin(rad36 + 2 * rad72) + _centerY,
		Color(255, 0, 0)
		));
	star->add(new Segment(
		_r * cos(3 * rad72) + _centerX, _r * sin(3 * rad72) + _centerY,
		_R * cos(rad36 + 3 * rad72) + _centerX, _R * sin(rad36 + 3 * rad72) + _centerY,
		Color(255, 0, 0)
		));
	star->add(new Segment(
		_r * cos(4 * rad72) + _centerX, _r * sin(4 * rad72) + _centerY,
		_R * cos(rad36 + 3 * rad72) + _centerX, _R * sin(rad36 + 3 * rad72) + _centerY,
		Color(255, 0, 0)
		));
	star->add(new Segment(
		_r * cos(4 * rad72) + _centerX, _r * sin(4 * rad72) + _centerY,
		_R * cos(rad36 + 4 * rad72) + _centerX, _R * sin(rad36 + 4 * rad72) + _centerY,
		Color(255, 0, 0)
		));
	star->add(new Segment(
		_r * cos(5 * rad72) + _centerX, _r * sin(5 * rad72) + _centerY,
		_R * cos(rad36 + 4 * rad72) + _centerX, _R * sin(rad36 + 4 * rad72) + _centerY,
		Color(255, 0, 0)
		));

	return star;
}