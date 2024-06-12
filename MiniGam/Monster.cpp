#include "Monster.h"

AMonster::AMonster()
{
	X = 0;
	Y = 0;
	Shape = 'M';
	Collision = false;
}

AMonster::AMonster(int NewX, int NewY, char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Collision = false;
}

AMonster::~AMonster()
{
}