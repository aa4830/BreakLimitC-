#pragma once
#include "Engine.h"
#include "SDL.h"
#include <string>
class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY, char NewShape, int NewLayer);
	virtual ~AActor();
	int Layer;

	int R;
	int G;
	int B;
	int SpriteSize;
	int ColorKeyR;
	int ColorKeyG;
	int ColorKeyB;

	void SetX(int NewX);
	void SetY(int NewY);
	void SetHp(int NewHp);
	inline int GetX() { return X;}
	inline int GetY() { return Y; }
	inline int GetCollision() { return Collision; }
	inline int GetIsMonster() { return IsMonster; }
	inline int GetHp() { return Hp; }
	virtual void Tick();
	virtual void Render();
	void LoadTexture(std::string TextureFilename);

	std::string Filename;
	SDL_Surface* MySurface;
	SDL_Texture* MyTexture;

protected:
	int X;
	int Y;
	char Shape;
	bool Collision;
	bool IsMonster;
	int Hp;
};

