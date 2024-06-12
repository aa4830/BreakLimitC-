#pragma once
#include "Actor.h"
class APlayer : public AActor
{
public:
	APlayer();
	APlayer(int NewX, int NewY, char NewShape);
	virtual ~APlayer();
	virtual void Tick();
	virtual void Render();
	virtual void Input();
	char Key;

private:
	int X;
	int Y;
	char Shape;
	bool Collision;
};

