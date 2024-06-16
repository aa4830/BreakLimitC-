#include "Goal.h"

AGoal::AGoal()
{
	X = 0;
	Y = 0;
	Shape = 'G';
	Collision = false;
	Layer = 4;
	R = 0;
	G = 0;
	B = 255;
}

AGoal::AGoal(int NewX, int NewY, char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Collision = false;
	Layer = 4;
	R = 0;
	G = 0;
	B = 255;

	Filename = "Data/coin.bmp";
	LoadTexture(Filename);
}

AGoal::~AGoal()
{
}
