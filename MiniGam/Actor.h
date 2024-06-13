#pragma once
#include "Engine.h"
class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY, char NewShape, int NewLayer);
	virtual ~AActor();
	int Layer;
	inline int GetX() { return X;}
	inline int GetY() { return Y; }
	inline int GetCollision() { return Collision; }
	virtual void Tick();
	virtual void Render();
protected:
	int X;
	int Y;
	char Shape;
	bool Collision;
};

