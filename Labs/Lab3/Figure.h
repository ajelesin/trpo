#pragma once
#include <vector>
#include"Drawable.h"

class Figure : public Drawable
{
public:
	Figure();
	~Figure();

	void add(Drawable*);
	virtual void show(GraphicEngine&);
	virtual void hide(GraphicEngine&);
	virtual void move(GraphicEngine&, Trajectory&);

	virtual void save(FILE*);
	void load(FILE*);

protected:
	std::vector<Drawable*> _figures;
};