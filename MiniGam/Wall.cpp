#include "Wall.h"

AWall::AWall()
{
	X = 0;
	Y = 0;
	Shape = '*';
	Collision = false;
}

AWall::AWall(int NewX, int NewY, char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Collision = false;
}

AWall::~AWall()
{
}
