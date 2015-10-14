#pragma once
#include "Figure.h"
#include "Point.h"
#include "Circle.h"
#include "Segment.h"

Figure::Figure()
{
	_figures = std::vector<Drawable*>();
}

Figure::~Figure()
{
	for (int i = 0; i < _figures.size(); i++){
		delete _figures[i];
	}
	_figures.clear();
}

void Figure::add(Drawable* figure)
{
	_figures.push_back(figure);
}

void Figure::show(GraphicEngine& engine)
{
	for (int i = 0; i < _figures.size(); i++){
		_figures[i]->show(engine);
	}
}

void Figure::hide(GraphicEngine& engine)
{
	for (int i = 0; i < _figures.size(); i++){
		_figures[i]->hide(engine);
	}
}

void Figure::move(GraphicEngine& engine, Trajectory& trajectory)
{
	for (int i = 0; i < _figures.size(); i++){
		_figures[i]->move(engine, trajectory);
	}
}

void Figure::save(FILE* file)
{
	fprintf(file, "%d\n", _figures.size());
	for (int i = 0; i < _figures.size(); i++){
		_figures[i]->save(file);
		fprintf(file, "\n");
	}
}

void Figure::load(FILE* file)
{
	for (int i = 0; i < _figures.size(); i++){
		delete _figures[i];
	}
	_figures.clear();

	int size;
	fscanf(file, "%d", &size);
	for (int i = 0; i < size; i++){
		char figureType[20];
		fscanf(file, "%s", figureType);
		if (!strcmp(figureType, "POINT")){
			double x, y;
			char colorString[20];
			fscanf(file, "%lf %lf %s", &x, &y, colorString);

			Color color;
			color.fromString(colorString);
			_figures.push_back(new Point(x, y, color));
		}
		else if (!strcmp(figureType, "CIRCLE")){
			double x, y, r;
			char colorString[20];
			fscanf(file, "%lf %lf %lf %s", &x, &y, &r, colorString);

			Color color;
			color.fromString(colorString);
			_figures.push_back(new Circle(x, y, r, color));
		}
		else if (!strcmp(figureType, "SEGMENT")){
			double x1, y1, x2, y2;
			char colorString[20];
			fscanf(file, "%lf %lf %lf %lf %s", &x1, &y1, &x2, &y2, colorString);

			Color color;
			color.fromString(colorString);
			_figures.push_back(new Segment(x1, y1, x2, y2, color));
		}
	}
}