#include "Heart.h"
AHeart::AHeart()
{
	X = 0;
	Y = 0;
	Shape = 'H';
	Collision = false;
	Layer = 4;
	R = 0;
	G = 0;
	B = 255;
	SpirteIndexX = 0;
	SpirteIndexY = 0;
	IsMonster = false;
}

AHeart::AHeart(int NewX, int NewY, char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Collision = false;
	Layer = 4;
	R = 0;
	G = 0;
	B = 255;
	SpirteIndexX = 0;
	SpirteIndexY = 0;
	IsMonster = false;

	Filename = "Data/heart.bmp";
	LoadTexture(Filename);
}

void AHeart::Render()
{
	SDL_Rect MyRect;
	MyRect.x = X * SpriteSize;
	MyRect.y = Y * SpriteSize;
	MyRect.w = SpriteSize;
	MyRect.h = SpriteSize;

	int SpriteSizeX = MySurface->w / 3;
	int SpriteSizeY = MySurface->h / 1;
	SDL_Rect SrcRect;

	SrcRect.x = SpriteSizeX * SpirteIndexX;
	SrcRect.y = SpriteSizeY * SpirteIndexY;
	SrcRect.w = SpriteSizeX;
	SrcRect.h = SpriteSizeY;
	for (int i = 0; i < AEngine::GetInstance()->Actors.size(); ++i)
	{
		if (this == AEngine::GetInstance()->Actors[i])
		{
			continue;
		}
		if (AEngine::GetInstance()->Actors[i]->GetIsMonster() == true && AEngine::GetInstance()->Actors[i]->GetHp()==10)
		{
			SpirteIndexX++;
		}
		if (AEngine::GetInstance()->Actors[i]->GetIsMonster() == true && AEngine::GetInstance()->Actors[i]->GetHp() == 0)
		{
			SpirteIndexX++;
		}
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

AHeart::~AHeart()
{
}
