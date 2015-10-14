#include <iostream>
#include <Windows.h>
#include "StarAnimation.h"
#include "RotateTrajectory.h"
#include "..\Lab3\WinApiGraphics.h"
#include "..\Lab3\WinApiGraphics.cpp"

using namespace std;

int main()
{
	HWND hwnd = GetConsoleWindow();
	WinApiGraphics* gra = new WinApiGraphics(hwnd);
	RotateTrajectory* rotateTrajectory = new RotateTrajectory(100.0, 100.0);

	StarAnimation animation = StarAnimation(rotateTrajectory, gra, 100.0, 100.0);
	animation.runAnimation();
	getchar();
	return 0;
}