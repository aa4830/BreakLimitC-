
#include "Actor.h"
#include <windows.h>
#include "Engine.h"
AActor::AActor()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	Collision = false;
}

AActor::AActor(int NewX, int NewY, char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Collision = false;
}

AActor::~AActor()
{
}

void AActor::Tick()
{

}

void AActor::Render()
{
	COORD Cur;
	Cur.X = X;
	Cur.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
