#include "Monster.h"
#include <time.h>
#include "Player.h"
#include "Engine.h"
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

bool AMonster::PredictForward(int NewX, int NewY)
{
	for (int i = 0; i < AEngine::GetInstance()->Actors.size(); ++i)
	{
		if (this == AEngine::GetInstance()->Actors[i])
		{
			continue;
		}

		if (AEngine::GetInstance()->Actors[i]->GetCollision() == false)
		{
			continue;
		}

		if (AEngine::GetInstance()->Actors[i]->GetX() == NewX && AEngine::GetInstance()->Actors[i]->GetY() == NewY)
		{
			return false;
		}
	}
	return true;
}

void AMonster::Tick()
{
	if (rand() % 4 == 0)
	{
		if (PredictForward(X, Y - 1))
		{
			Y--;
		}
	}
	if (rand() % 4 == 1)
	{
		if (PredictForward(X, Y + 1))
		{
			Y++;
		}
	}
	if (rand() % 4 == 2)
	{
		if (PredictForward(X-1, Y))
		{
			X--;
		}
	}
	if (rand() % 4 == 3)
	{
		if (PredictForward(X+1,Y))
		{
			X++;
		}
	}
}
