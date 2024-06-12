#include "Player.h"
#include <conio.h>
APlayer::APlayer()
{
	X = 0;
	Y = 0;
	Key = ' ';
	Shape = 'P';
	Collision = false;
}

APlayer::APlayer(int NewX, int NewY, char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Collision = false;
	Key = ' ';
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	if (Key == 'w')
	{
		Y--;
	}
	if (Key == 's')
	{
		Y++;
	}
	if (Key == 'a')
	{
		X--;
	}
	if (Key == 'd')
	{
		X++;
	}
}

void APlayer::Render()
{
}

void APlayer::Input()
{
	Key = _getch();
}
