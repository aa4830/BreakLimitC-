#pragma once
#include "Actor.h"
#include "Engine.h"

class APlayer : public AActor
{
public:
	APlayer();
	APlayer(int NewX, int NewY, char NewShape);
	virtual ~APlayer();
	void Tick();
	void Render();
	void Input();

private:
	int X;
	int Y;
	char Shape;
	bool Collision;
};

