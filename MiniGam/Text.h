#pragma once
#include "Actor.h"
#include "SDL_ttf.h"
#include <string>
class AText : public AActor
{
public:
	AText();
	virtual ~AText();
	virtual void Render() override;
	std::string Text;

protected:
	TTF_Font* Font;
	int FontSize;
};

