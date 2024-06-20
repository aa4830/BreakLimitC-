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
	bool PredictForward(int NewX, int NewY);
	void Attack(int NewX, int NewY);

	int SpirteIndexX;
	int SpirteIndexY;
	int PlayerDamage;
	Uint64 ElapsedTime;
};

