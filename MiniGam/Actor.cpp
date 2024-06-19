
#include "Actor.h"
#include <windows.h>
#include "Engine.h"
AActor::AActor()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	Collision = false;
	IsMonster = false;
	Layer = 0;
	ColorKeyR = 255;
	ColorKeyG = 255;
	ColorKeyB = 255;
	R = 0;
	G = 0;
	B = 0;
	SpriteSize = 60;
	MySurface = nullptr;
	MyTexture = nullptr;
	Hp = 0;
}

AActor::AActor(int NewX, int NewY,char NewShape, int NewLayer)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Collision = false;
	Layer = NewLayer;
	ColorKeyR = 255;
	ColorKeyG = 255;
	ColorKeyB = 255;
	R = 0;
	G = 0;
	B = 0;
	SpriteSize = 60;
	MySurface = nullptr;
	MyTexture = nullptr;
	Hp = 0;
}

AActor::~AActor()
{
}

void AActor::SetX(int NewX)
{
	X = NewX;
}

void AActor::SetY(int NewY)
{
	Y = NewY;
}

void AActor::SetHp(int NewHp)
{
	Hp = NewHp;
}

void AActor::Tick()
{

}

void AActor::Render()
{
	COORD Cur;
	Cur.X = X;
	Cur.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	std::cout << Shape;

	SDL_Rect MyRect;
	MyRect.x = X * SpriteSize;
	MyRect.y = Y * SpriteSize;
	MyRect.w = SpriteSize;
	MyRect.h = SpriteSize;

	if (MyTexture)
	{
		SDL_RenderCopy(AEngine::GetInstance()->MyRenderer,
			MyTexture,
			nullptr,
			&MyRect);
	}
	else
	{
		SDL_RenderFillRect(AEngine::GetInstance()->MyRenderer, &MyRect);
	}
}
void AActor::LoadTexture(std::string TextureFilename)
{		
	MySurface = SDL_LoadBMP(TextureFilename.c_str());
	SDL_SetColorKey(MySurface, 1, SDL_MapRGB(MySurface->format, ColorKeyR, ColorKeyG, ColorKeyB));
	MyTexture = SDL_CreateTextureFromSurface(AEngine::GetInstance()->MyRenderer, MySurface);
}