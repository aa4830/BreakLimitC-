#pragma once
#include "Engine.h"
class AActor
{
public: 
	AActor();
	AActor(int NewX, int NewY, char NewShape);
	virtual ~AActor();

	virtual void Tick();
	virtual void Render();
protected:
	int X;
	int Y;
	char Shape;
	bool Collision;
};
