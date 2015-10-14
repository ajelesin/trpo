#pragma once
#include <Windows.h>

class Color
{
public:
	Color();
	Color(int, int, int);

	COLORREF toRgb();
	char* toString();
	void fromString(char*);

private:
	int _red, _green, _blue;
};