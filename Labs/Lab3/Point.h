#pragma once
#include "Drawable.h"
#include "Color.h"

class Point : public Drawable
{
public:
	Point();
	Point(double, double, Color);

	int getX(){ return _x; }
	int getY(){ return _y; }

	virtual void show(GraphicEngine&);
	virtual void hide(GraphicEngine&);
	virtual void move(GraphicEngine&, Trajectory&);

	virtual void save(FILE*);
protected:
	double _x, _y;
	Color _color;
};