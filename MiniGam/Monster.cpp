#include "Monster.h"

AMonster::AMonster()
{
	X = 0;
	Y = 0;
	Shape = 'M';
	Collision = false;
	Layer = 1;
}

AMonster::AMonster(int NewX, int NewY, char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Collision = false;
	Layer = 1;
}

AMonster::~AMonster()
{
}
