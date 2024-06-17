#include "Text.h"
#include "Engine.h"
AText::AText()
{
	X = 100;
	Y = 100;
	FontSize = 30;
	Font = TTF_OpenFont("data/NanumGothic.ttf", FontSize);
	Text = "Warning";
	R = 0;
	G = 0;
	B = 0;
	Layer = 100;

	SDL_Color Color;
	Color.r = R;
	Color.g = G;
	Color.b = B;
	MySurface = TTF_RenderText_Solid(Font, Text.c_str(), Color);
	MyTexture = SDL_CreateTextureFromSurface(AEngine::GetInstance()->MyRenderer, MySurface);

}

AText::~AText()
{
	SDL_FreeSurface(MySurface);
	SDL_DestroyTexture(MyTexture);
	TTF_CloseFont(Font);
}

void AText::Render()
{
	int Width = 0;
	int Height = 0;
	SDL_QueryTexture(MyTexture, nullptr, nullptr, &Width, &Height);
	SDL_Rect DestinationRect;
	DestinationRect.x = X;
	DestinationRect.y = Y;
	DestinationRect.w = Width;
	DestinationRect.h = Height;

	SDL_RenderCopy(AEngine::GetInstance()->MyRenderer, MyTexture, nullptr, &DestinationRect);
}
