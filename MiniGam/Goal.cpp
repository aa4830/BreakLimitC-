#include "Goal.h"

AGoal::AGoal()
{
	X = 0;
	Y = 0;
	Shape = 'G';
	Collision = false;
	Layer = 4;
}

AGoal::AGoal(int NewX, int NewY, char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Collision = false;
	Layer = 4;
}

AGoal::~AGoal()
{
}
