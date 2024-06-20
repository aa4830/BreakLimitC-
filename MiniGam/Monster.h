#pragma once
#include "Actor.h"
class AMonster : public AActor
{
public:
	AMonster();
	AMonster(int NewX, int NewY, char NewShape);
	bool PredictForward(int NewX, int NewY);
	void Die();
	virtual ~AMonster();
	virtual void Tick() override;
	Uint64 ElapsedTime;
};

