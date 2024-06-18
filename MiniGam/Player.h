#pragma once
#include "Actor.h"
#include "Monster.h"

class APlayer : public AActor
{
public:
	APlayer();
	APlayer(int NewX, int NewY,char NewShape);
	virtual ~APlayer();

	virtual void Tick() override;
	virtual void Render() override;
	void Attack();
	bool PredictForward(int NewX, int NewY);

	int SpirteIndexX;
	int SpirteIndexY;
	Uint64 ElapsedTime;
	AMonster Monster;
};

