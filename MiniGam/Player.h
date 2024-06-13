#pragma once
#include "Actor.h"
#include "Engine.h"

class APlayer : public AActor
{
public:
	APlayer();
	APlayer(int NewX, int NewY,char NewShape = 'P');
	virtual ~APlayer();
	virtual void Tick() override;
	bool PredictForward(int NewX, int NewY);
	void Input();
};

