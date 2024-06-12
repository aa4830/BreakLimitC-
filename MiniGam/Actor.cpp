
#include "Actor.h"

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
}
