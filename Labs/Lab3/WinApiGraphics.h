#pragma once
#include <Windows.h>
#include "GraphicEngine.h"

class WinApiGraphics: public GraphicEngine
{
public:
	WinApiGraphics(HWND);

	virtual void drawPoint(double, double, Color);
	virtual void drawCircle(double, double, double, Color);
	virtual void drawLine(double, double, double, double, Color);
	virtual Color getBackgroundColor();

private:
	HWND _hwnd;
};