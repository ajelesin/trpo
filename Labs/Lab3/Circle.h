#pragma once
#include "Point.h"

class Circle :public Point
{
public:
	Circle();
	Circle(double, double, double, Color);

	virtual void show(GraphicEngine&);
	virtual void hide(GraphicEngine&);

	virtual void save(FILE*);

protected:
	double _r;
};