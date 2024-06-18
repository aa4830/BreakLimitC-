#include "Monster.h"
#include "Player.h"
#include "Engine.h"
AMonster::AMonster()
{
	X = 0;
	Y = 0;
	Shape = 'M';
	Collision = false;
	Layer = 1;
	Hp = 3;
	R = 255;
	G = 0;
	B = 255;
	ElapsedTime = 0;
}

AMonster::AMonster(int NewX, int NewY, char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Collision = false;
	Layer = 1;
	Hp = 3;
	R = 255;
	G = 0;
	B = 255;

	ElapsedTime = 0;
	Filename = "Data/Slime.bmp";
	LoadTexture(Filename);
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
	ElapsedTime += AEngine::GetInstance()->GetWorldDeltaSeconds();

	if (ElapsedTime < 500)
	{
		return;
	}

	ElapsedTime = 0;

	int Direction = rand() % 4;

	switch (Direction)
	{
	case 0:
		if (PredictForward(X, Y - 1))
		{
			Y--;
		}
		break;
	case 1:
		if (PredictForward(X, Y + 1))
		{
			Y++;
		}
		break;
	case 2:
		if (PredictForward(X - 1, Y))
		{
			X--;
		}
		break;
	case 3:
		if (PredictForward(X + 1, Y))
		{
			X++;
		}
		break;
	}
}
