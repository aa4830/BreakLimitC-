#pragma once
#include "Actor.h"
class AMonster : public AActor
{
public:
	AMonster();
	AMonster(int NewX, int NewY, char NewShape);
	virtual ~AMonster();
private:

	int X;
	int Y;
	char Shape;
	bool Collision;
};

