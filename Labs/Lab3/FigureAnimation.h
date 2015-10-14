#pragma once
#include "Figure.h"
#include "Trajectory.h"
#include "GraphicEngine.h"

class FigureAnimation
{
public:
	FigureAnimation(Trajectory*, GraphicEngine*);
	~FigureAnimation();

	virtual Figure* getFigure() = 0;

	void load(char*);
	void save(char*);
	void runAnimation();
	void nextFrame();

private:
	Figure* _figure;
	Trajectory* _trajectory;
	GraphicEngine* _graphicEngine;
};