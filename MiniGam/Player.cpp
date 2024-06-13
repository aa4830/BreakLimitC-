#include "Player.h"
#include <conio.h>
#include "Engine.h"
APlayer::APlayer()
{
	X = 0;
	Y = 0;
	Shape = 'P';
	Collision = true;
	Layer = 5;
}

APlayer::APlayer(int NewX, int NewY,char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Collision = true;
	Layer = 5;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	if (PredictForward(X, Y - 1)) 
	{
		if (AEngine::GetInstance()->Key == 'w')
		{
			Y--;
		}
	}
	if (PredictForward(X, Y + 1))
	{
		if (AEngine::GetInstance()->Key == 's')
		{
			Y++;
		}
	}
	if (PredictForward(X-1, Y))
	{
		if (AEngine::GetInstance()->Key == 'a')
		{
			X--;
		}
	}
	if (PredictForward(X+1, Y))
	{
		if (AEngine::GetInstance()->Key == 'd')
		{
			X++;
		}
	}
}

bool APlayer::PredictForward(int NewX, int NewY)
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


void APlayer::Input()
{
}
