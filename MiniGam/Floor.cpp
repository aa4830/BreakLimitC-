#include "Floor.h"

AFloor::AFloor()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	Collision = false;
	Layer = 0;
}

AFloor::AFloor(int NewX, int NewY, char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Collision = false;
	Layer = 0;
}

AFloor::~AFloor()
{
}
