#pragma once
#include "Actor.h"

class APlayer : public AActor
{
public:
	APlayer();
	APlayer(int NewX, int NewY,char NewShape);
	virtual ~APlayer();

	virtual void Tick() override;
	virtual void Render() override;
	bool PredictForward(int NewX, int NewY);

	int SpirteIndexX;
	int SpirteIndexY;
	Uint64 ElapsedTime;

};

