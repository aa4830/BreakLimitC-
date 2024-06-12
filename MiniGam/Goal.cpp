#include "Goal.h"

AGoal::AGoal()
{
	X = 0;
	Y = 0;
	Shape = 'G';
	Collision = false;
}

AGoal::AGoal(int NewX, int NewY, char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Collision = false;
}

AGoal::~AGoal()
{
}
