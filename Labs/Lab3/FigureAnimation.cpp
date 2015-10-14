#pragma once
#include "FigureAnimation.h"
#include "Vector2D.h"

FigureAnimation::FigureAnimation(Trajectory* trajectory, GraphicEngine* graphicEngine)
{
	_trajectory = trajectory;
	_graphicEngine = graphicEngine;
}

FigureAnimation::~FigureAnimation()
{
	delete _figure;
	delete _graphicEngine;
	delete _trajectory;
}

void FigureAnimation::load(char* filename)
{
	FILE* file = fopen(filename, "r");
	delete _figure;
	Figure* figure = new Figure();
	figure->load(file);
	_figure = figure;
	fclose(file);
}

void FigureAnimation::save(char* filename)
{
	FILE* file = fopen(filename, "w");
	_figure->save(file);
	fclose(file);
}

void FigureAnimation::runAnimation()
{
	if (!_figure){
		_figure = getFigure();
	}
	while (_trajectory->hasNext()){
		Sleep(100);
		_figure->move(*_graphicEngine, *_trajectory);
	}
}

void FigureAnimation::nextFrame()
{
	if (!_figure){
		_figure = getFigure();
	}
	if (_trajectory->hasNext()){
		_figure->move(*_graphicEngine, *_trajectory);
	}
}