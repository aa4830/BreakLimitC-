#pragma once
#include "Actor.h"
#include "Monster.h"
class AHeart : public AActor
{
public:
	AHeart();
	AHeart(int NewX, int NewY, char NewShape);
	virtual void Render() override;
	int SpirteIndexX;
	int SpirteIndexY;
	virtual ~AHeart();
	AMonster Monster;
};

