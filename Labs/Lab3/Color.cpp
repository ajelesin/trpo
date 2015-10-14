#pragma once
#include <stdio.h>
#include "Color.h"

Color::Color()
{
	_red = 0;
	_green = 0;
	_blue = 0;
}

Color::Color(int red, int green, int blue)
{
	_red = red;
	_green = green;
	_blue = blue;
}

COLORREF Color::toRgb()
{
	return RGB(_red, _green, _blue);
}

char* Color::toString()
{
	char buff[20];
	sprintf(buff, "%d;%d;%d", _red, _green, _blue);
	return buff;
}

void Color::fromString(char* str)
{
	sscanf(str, "%d;%d;%d", &_red, &_green, &_blue);
}