#include <iostream>
#include "CarAnimation.h"
#include "LineTrajectory.h"
#include "WinApiGraphics.h"
using namespace std;

int main()
{
	HWND hwnd = GetConsoleWindow();
	WinApiGraphics* gra = new WinApiGraphics(hwnd);
	LineTrajectory* lineTrajectory = new LineTrajectory();

	CarAnimation animation = CarAnimation(lineTrajectory, gra, 100, 100);
	animation.runAnimation();
	getchar();
	return 0;
}