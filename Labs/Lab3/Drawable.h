#pragma once
#include <stdio.h>
#include "GraphicEngine.h"
#include "Trajectory.h"

class Drawable
{
public:
	virtual void show(GraphicEngine&) = 0;
	virtual void hide(GraphicEngine&) = 0;
	virtual void move(GraphicEngine&, Trajectory&) = 0;

	virtual void save(FILE*) = 0;
};