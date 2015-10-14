#pragma once
#include "WinApiGraphics.h"

WinApiGraphics::WinApiGraphics(HWND hwnd)
{
	_hwnd = hwnd;
}

void WinApiGraphics::drawPoint(double x, double y, Color color)
{
	HDC hdc = GetDC(_hwnd);
	SetPixel(hdc, x, y, color.toRgb());
	ReleaseDC(_hwnd, hdc);
}

void WinApiGraphics::drawCircle(double x, double y, double r, Color color)
{
	HDC hdc = GetDC(_hwnd);
	HPEN colorPen = CreatePen(PS_SOLID, 1, color.toRgb());
	HBRUSH colorBrush = CreateSolidBrush(getBackgroundColor().toRgb());
	HGDIOBJ oldPen = SelectObject(hdc, colorPen);
	HGDIOBJ oldBrush = SelectObject(hdc, colorBrush);
	Ellipse(hdc, x - r, y - r, x + r, y + r);
	SelectObject(hdc, oldPen);
	SelectObject(hdc, oldBrush);
	DeleteObject(colorBrush);
	DeleteObject(colorPen);
	ReleaseDC(_hwnd, hdc);
}

void WinApiGraphics::drawLine(double x1, double y1, double x2, double y2, Color color)
{
	HDC hdc = GetDC(_hwnd);
	HPEN colorPen = CreatePen(PS_SOLID, 1, color.toRgb());
	HGDIOBJ oldPen = SelectObject(hdc, colorPen);

	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);

	SelectObject(hdc, oldPen);
	DeleteObject(oldPen);
	DeleteObject(colorPen);
	ReleaseDC(_hwnd, hdc);
}

Color WinApiGraphics::getBackgroundColor()
{
	return Color(0, 0, 0);
}