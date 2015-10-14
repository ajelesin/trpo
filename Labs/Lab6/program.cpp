#include <iostream>
#include <Windows.h>
#include "SnowAnimation.h"
#include "ShootingTrajectory.h"
#include "..\Lab3\WinApiGraphics.h"
#include "..\Lab3\WinApiGraphics.cpp"
using namespace std;

void gotoxy(int x, int y)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

int readAmount()
{
	int amount;
	printf("Enter amout of shows: ");
	scanf("%d", &amount);
	gotoxy(0, 0);
	printf("                                     ");
	gotoxy(0, 0);
	return amount;
}

int main()
{
	int amount = readAmount();
	HWND hwnd = GetConsoleWindow();
	RECT rect;
	GetClientRect(hwnd, &rect);
	WinApiGraphics* gra = new WinApiGraphics(hwnd);
	ShootingTrajectory* shootingTrajectory = new ShootingTrajectory(rect.right, rect.bottom);

	SnowAnimation animation = SnowAnimation(shootingTrajectory, gra, rect.right, rect.bottom, amount);
	animation.runAnimation();
	getchar();
	return 0;
}