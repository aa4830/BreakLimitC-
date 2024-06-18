#include "Engine.h"
#include "Actor.h"
#include "Monster.h"
#include "Wall.h"
#include "Floor.h"
#include "Goal.h"
#include "Player.h"
#include <vector>
#include <fstream>
#include <conio.h>
#include <iostream>
#include "SDL.h"
#include <SDL_mixer.h>
#include "SDL_ttf.h"
#include "Heart.h"
#include "Text.h"
using namespace std;

AEngine* AEngine::Instance = nullptr;
int AEngine::KeyCode = 0;

AEngine::AEngine()
{
	DeltaSeconds = 0;
	LastTime = 0;
	Init();
}

AEngine::~AEngine()
{
	Term();
}

void AEngine::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);
}

void AEngine::SortLayer()
{	
	AActor* Temp;
	for (int i = 0; i < Actors.size(); ++i)
	{
		for (int j = i + 1; j < Actors.size(); ++j)
		{
			if (Actors[i]->Layer > Actors[j]->Layer)
			{
				Temp = Actors[i];
				Actors[i] = Actors[j];
				Actors[j] = Temp;
			}
		}
	}


}

void AEngine::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "Init error" << endl;
		return;
	}
	MyWindow = SDL_CreateWindow(" I am Window ", 100, 100, 660, 600, SDL_WINDOW_OPENGL);
	MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
	srand((unsigned int)(time(0)));
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	Mix_Music* bgm = Mix_LoadMUS("data/bgm.mp3");
	Mix_VolumeMusic(1);
	Mix_PlayMusic(bgm, -1);
	TTF_Init();
	IsRunning = true;
}

void AEngine::Term()
{
	for (int i = 0; i < Actors.size(); ++i)
	{
		delete Actors[i];
	}
	Actors.clear();
	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	Mix_CloseAudio();
	TTF_Quit();
	SDL_Quit();
}

void AEngine::Tick()
{
	switch (MyEvent.type)
	{
	case SDL_QUIT:
		IsRunning = false;
		break;
	case SDL_MOUSEBUTTONDOWN:
		cout << "Mouse Button Down" << endl;
		break;
	case SDL_KEYDOWN:
		switch (MyEvent.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			IsRunning = false;
			break;
		}
	}

	for (int i = 0; i < Actors.size(); ++i)
	{
		Actors[i]->Tick();
	}
}

void AEngine::Render()
{
	SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 0);
	SDL_RenderClear(MyRenderer);
	for (int i = 0; i < Actors.size(); ++i)
	{
		Actors[i]->Render();
	}
	SDL_RenderPresent(MyRenderer);
}

void AEngine::Input()
{
	SDL_PollEvent(&MyEvent);
}

void AEngine::Run()
{
	while (IsRunning)
	{
		Input();
		DeltaSeconds = SDL_GetTicks64() - LastTime;
		LastTime = SDL_GetTicks64();
		Tick();
		Render();
	}
}

void AEngine::DrawMap(std::string MapFileName)
{
	char Map[256];

	ifstream InputFile;

	InputFile.open(MapFileName);

	int Y = 0;
	while (InputFile.getline(Map, 300))
	{
		for (int X = 0; X < strlen(Map); ++X)
		{
			if (Map[X] == 'P')
			{
				SpawnActor(new AFloor(X, Y,' '));
				SpawnActor(new APlayer(X, Y,'P'));
			}
			else if(Map[X] == '*')
			{
				SpawnActor(new AFloor(X, Y, ' '));
				SpawnActor(new AWall(X, Y,'*'));
			}
			else if (Map[X] == ' ')
			{
				SpawnActor(new AFloor(X, Y, ' '));
			}
			else if (Map[X] == 'G')
			{
				SpawnActor(new AFloor(X, Y, ' '));
				SpawnActor(new AGoal(X, Y,'G'));
			}
			else if (Map[X] == 'M')
			{
				SpawnActor(new AFloor(X, Y, ' '));
				SpawnActor(new AMonster(X, Y,'M'));
			}
			else if (Map[X] == 'H')
			{
				SpawnActor(new AFloor(X, Y, ' '));
				SpawnActor(new AHeart(X, Y, 'H'));
			}

		}
		++Y;
	}
	SortLayer();
	InputFile.close();
}