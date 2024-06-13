
#include "Actor.h"
#include <windows.h>
#include "Engine.h"
AActor::AActor()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	Collision = false;
	Layer = 0;
}

AActor::AActor(int NewX, int NewY,char NewShape, int NewLayer)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Collision = false;
	Layer = NewLayer;
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
	std::cout << Shape;
}
