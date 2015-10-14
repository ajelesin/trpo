#pragma once
#include "LineTrajectory.h"
#include "WinApiGraphics.h"
#include "CarAnimation.h"
#include "Circle.h"
#include "Segment.h"

CarAnimation::CarAnimation(Trajectory* trajectory, GraphicEngine* graphicEngine, double centerX, double centerY)
	:FigureAnimation(trajectory, graphicEngine)
{
	_centerX = centerX;
	_centerY = centerY;
}

Figure* CarAnimation::getFigure()
{
	Figure* fig = new Figure();
	fig->add(new Circle(_centerX - 20, _centerY + 20, 10, Color(255, 0, 0)));
	fig->add(new Circle(_centerX + 20, _centerY + 20, 10, Color(255, 0, 0)));
	fig->add(new Segment(_centerX - 10, _centerY + 20, _centerX + 10, _centerY + 20, Color(255, 0, 0)));
	fig->add(new Segment(_centerX - 40, _centerY + 20, _centerX - 30, _centerY + 20, Color(255, 0, 0)));
	fig->add(new Segment(_centerX + 40, _centerY + 20, _centerX + 30, _centerY + 20, Color(255, 0, 0)));
	fig->add(new Segment(_centerX - 40, _centerY, _centerX - 20, _centerY, Color(255, 0, 0)));
	fig->add(new Segment(_centerX + 40, _centerY, _centerX + 20, _centerY, Color(255, 0, 0)));
	fig->add(new Segment(_centerX - 20, _centerY - 20, _centerX + 20, _centerY - 20, Color(255, 0, 0)));
	fig->add(new Segment(_centerX - 20, _centerY, _centerX - 20, _centerY - 20, Color(255, 0, 0)));
	fig->add(new Segment(_centerX + 20, _centerY, _centerX + 20, _centerY - 20, Color(255, 0, 0)));
	fig->add(new Segment(_centerX - 40, _centerY, _centerX - 40, _centerY + 20, Color(255, 0, 0)));
	fig->add(new Segment(_centerX + 40, _centerY, _centerX + 40, _centerY + 20, Color(255, 0, 0)));
	return fig;
}