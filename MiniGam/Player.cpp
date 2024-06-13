#include "Player.h"
#include <conio.h>
#include "Engine.h"
APlayer::APlayer()
{
	X = 0;
	Y = 0;
	Shape = 'P';
	Collision = false;
}

APlayer::APlayer(int NewX, int NewY, char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Collision = false;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	if (AEngine::GetInstance()->Key == 'w')
	{
		Y--;
	}
	if (AEngine::GetInstance()->Key == 's')
	{
		Y++;
	}
	if (AEngine::GetInstance()->Key == 'a')
	{
		X--;
	}
	if (AEngine::GetInstance()->Key == 'd')
	{
		X++;
	}
}

void APlayer::Render()
{
}

void APlayer::Input()
{
}
