#pragma once
#include "Drawable.h"

class Segment :public Drawable
{
public:
	Segment();
	Segment(double, double, double, double, Color);

	virtual void show(GraphicEngine&);
	virtual void hide(GraphicEngine&);
	virtual void move(GraphicEngine&, Trajectory&);

	virtual void save(FILE*);

protected:
	double _x1, _y1, _x2, _y2;
	Color _color;
};