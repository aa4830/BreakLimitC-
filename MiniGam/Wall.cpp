#include "Wall.h"

AWall::AWall()
{
	X = 0;
	Y = 0;
	Shape = '*';
	Collision = true;
	IsMonster = false;
	Layer = 1;

	R = 255;
	G = 0;
	B = 0;
}

AWall::AWall(int NewX, int NewY, char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Collision = true;
	IsMonster = false;
	Layer = 1;

	R = 255;
	G = 0;
	B = 0;
	Filename = "Data/wall.bmp";
	LoadTexture(Filename);
}

AWall::~AWall()
{
}
