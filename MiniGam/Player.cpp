#include "Player.h"
#include <conio.h>
#include "Engine.h"
APlayer::APlayer()
{
	X = 0;
	Y = 0;
	Shape = 'P';
	Collision = true;
	IsMonster = false;
	Layer = 5;
	R = 0;
	G = 255;
	B = 0;

	ColorKeyR = 255;
	ColorKeyG = 0;
	ColorKeyB = 255;

	SpirteIndexX = 0;
	SpirteIndexY = 0;

	ElapsedTime = 0;

	Hp = 6;
	PlayerDamage = 10;
}

APlayer::APlayer(int NewX, int NewY,char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Collision = true;
	IsMonster = false;
	Layer = 5;

	R = 0;
	G = 255;
	B = 0;

	ColorKeyR = 255;
	ColorKeyG = 0;
	ColorKeyB = 255;

	SpirteIndexX = 0;
	SpirteIndexY = 0;

	Filename = "Data/test.bmp";
	LoadTexture(Filename);
	ElapsedTime = 0;
	Hp = 5;
	PlayerDamage = 10;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	switch (AEngine::GetInstance()->MyEvent.type)
	{
	case SDL_KEYDOWN:
		switch (AEngine::GetInstance()->MyEvent.key.keysym.sym)
		{
		case SDLK_w:
			SpirteIndexY = 2;
			if (PredictForward(X, Y - 1))
			{
				Y--;
			}
			break;
		case SDLK_s:
			SpirteIndexY = 3;
			if (PredictForward(X, Y + 1))
			{
				Y++;
			}
			break;
		case SDLK_a:
			SpirteIndexY = 0;
			if (PredictForward(X - 1, Y))
			{
				X--;
			}
			break;
		case SDLK_d:
			SpirteIndexY = 1;
			if (PredictForward(X + 1, Y))
			{
				X++;
			}
			break;
		case SDLK_LSHIFT:
			SpirteIndexY = 4;
			Attack(X, Y - 1);
			Attack(X, Y + 1);
			Attack(X - 1, Y);
			Attack(X + 1, Y);
			Attack(X , Y);

		}
	}
}

void APlayer::Render()
{
	SDL_Rect MyRect;
	MyRect.x = X * SpriteSize;
	MyRect.y = Y * SpriteSize;
	MyRect.w = SpriteSize;
	MyRect.h = SpriteSize;

	int SpriteSizeX = MySurface->w / 5;
	int SpriteSizeY = MySurface->h / 5;
	SDL_Rect SrcRect;

	SrcRect.x = SpriteSizeX * SpirteIndexX;
	SrcRect.y = SpriteSizeY * SpirteIndexY;
	SrcRect.w = SpriteSizeX;
	SrcRect.h = SpriteSizeY;
	ElapsedTime += AEngine::GetInstance()->GetWorldDeltaSeconds();
	if (ElapsedTime >= 200)
	{
		SpirteIndexX++;
		SpirteIndexX = SpirteIndexX % 5;
		ElapsedTime = 0;
	}

	if (MyTexture)
	{
		SDL_RenderCopy(AEngine::GetInstance()->MyRenderer,
			MyTexture,
			&SrcRect,
			&MyRect);
	}
	else
	{
		SDL_RenderFillRect(AEngine::GetInstance()->MyRenderer, &MyRect);
	}
}

bool APlayer::PredictForward(int NewX, int NewY)
{
	for (int i = 0; i < AEngine::GetInstance()->Actors.size(); ++i)
	{
		if (this == AEngine::GetInstance()->Actors[i])
		{
			continue;
		}

		if (AEngine::GetInstance()->Actors[i]->GetCollision() == false)
		{
			continue;
		}

		if (AEngine::GetInstance()->Actors[i]->GetX() == NewX && AEngine::GetInstance()->Actors[i]->GetY() == NewY)
		{
			return false;
		}
	}
	return true;
}

void APlayer::Attack(int NewX, int NewY)
{
	for (int i = 0; i < AEngine::GetInstance()->Actors.size(); ++i)
	{
		if (this == AEngine::GetInstance()->Actors[i])
		{
			continue;
		}
		if (AEngine::GetInstance()->Actors[i]->GetIsMonster())
		{
			if (AEngine::GetInstance()->Actors[i]->GetX() == NewX && AEngine::GetInstance()->Actors[i]->GetY() == NewY)
			{
				AEngine::GetInstance()->Actors[i]->SetHp(AEngine::GetInstance()->Actors[i]->GetHp() - PlayerDamage);
			}
		}
	}
}
