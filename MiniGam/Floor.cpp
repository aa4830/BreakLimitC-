#include "Floor.h"

AFloor::AFloor()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	Collision = false;
	Layer = 0;
	R = 100;
	G = 100;
	B = 100;
}

AFloor::AFloor(int NewX, int NewY, char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Collision = false;
	Layer = 0;

	R = 100;
	G = 100;
	B = 100;
	Filename = "Data/floor.bmp";
	LoadTexture(Filename);
}

AFloor::~AFloor()
{
}
