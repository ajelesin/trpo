#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
using namespace std;
#define ESCAPE_KEY 27

int coloredPixelAmount = 0;
HWND hwnd;
HDC hdc;
RECT rect;

int random(int a, int b)
{
	return (rand() % (b - a)) + a;
}

bool isTimeToFinish()
{
	if (!_kbhit())
		return false;

	int c = _getch();
	return c == ESCAPE_KEY;
}

void drawStar()
{
	int x = random(0, rect.right);
	int y = random(0, rect.bottom);

	if (GetPixel(hdc, x, y) == RGB(0, 0, 0)){
		int redColor = random(0, 255);
		int greenColor = random(0, 255);
		int blueCoor = random(0, 255);

		SetPixel(hdc, x, y, RGB(redColor, greenColor, blueCoor));
		coloredPixelAmount++;
	}
	else {
		SetPixel(hdc, x, y, RGB(0, 0, 0));
		coloredPixelAmount--;
	}
}

void drawStatistics()
{
	int totalAmount = rect.right * rect.bottom;
	double percent = (double)coloredPixelAmount / (double)totalAmount * 100;

	char buff[100];
	sprintf_s(buff, "%.2f%%", percent);

	double heightInMillimeters = GetDeviceCaps(hdc, VERTSIZE);
	double heightInPixels = GetDeviceCaps(hdc, HORZRES);
	double pixelsPerMillimeters = heightInPixels / heightInMillimeters;

	HFONT newFont = CreateFont(10 * pixelsPerMillimeters, 0, 0, 0, FW_BOLD, 0, 0, 0,
		DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY,
		FF_MODERN, "Harrington");
	HFONT oldFont = (HFONT)SelectObject(hdc, newFont);

	SetTextColor(hdc, RGB(255, 0, 0));
	SetBkMode(hdc, TRANSPARENT);
	DrawText(hdc, buff, strlen(buff), &rect, DT_SINGLELINE | DT_NOCLIP | DT_CENTER | DT_VCENTER);

	SelectObject(hdc, oldFont);
	DeleteObject(newFont);
}

int main()
{
	srand(time(NULL));
	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);
	GetClientRect(hwnd, &rect);

	while (!isTimeToFinish())
	{
		drawStar();
	}
	drawStatistics();

	ReleaseDC(hwnd, hdc);
	_getch();
	return 0;
}