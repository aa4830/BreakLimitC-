#pragma once
#include <iostream>
#include "Engine.h"
#include "Player.h"
class AActor : public AEngine
{
public: 
	AActor();
	AActor(int NewX, int NewY, char NewShape);
	virtual ~AActor();

	virtual void Tick();
	virtual void Render();
private:
	int X;
	int Y;
	char Shape;
	bool Collision;
};

