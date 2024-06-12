#include "Engine.h"
#include "Actor.h"
#include <vector>
#include <fstream>
#include "Player.h"
#include "Monster.h"
#include "Wall.h"
#include "Floor.h"
#include "Goal.h"
using namespace std;
AEngine::AEngine()
{
	IsRunning = true;
	instance = nullptr;
}

AEngine::~AEngine()
{
}

void AEngine::Tick()
{
	for (int i = 0; i < Actors.size(); ++i)
	{
		Actors[i]->Tick();
	}
}

void AEngine::Render()
{
	for (int i = 0; i < Actors.size(); ++i)
	{
		Actors[i]->Render();
	}
}

void AEngine::Input()
{
	
}

void AEngine::Run()
{
	while (IsRunning)
	{
		Tick();
		Render();
		Input();
	}
}

void AEngine::DrawMap(std::string MapFileName)
{
	int Y = 0;
	char Map[256];
	ifstream InputFile;
	InputFile.open(MapFileName);
	while (InputFile.getline(Map, 100))
	{
		for (int X = 0; X < strlen(Map); ++X)
		{
			if (Map[X] == 'P')
			{
				SpawnActor(new APlayer (X, Y,'P'));
			}
			else if(Map[X] == '*')
			{
				SpawnActor(new AWall(X, Y, '*'));
			}
			else if (Map[X] == ' ')
			{
				SpawnActor(new AFloor(X, Y, ' '));
			}
			else if (Map[X] == 'G')
			{
				SpawnActor(new AGoal(X, Y, 'G'));
			}
			else if (Map[X] == 'M')
			{
				SpawnActor(new AMonster (X, Y, 'M'));
			}
		}
		++Y;
	}
}


void AEngine::SpawnActor(AActor* newActor)
{
	Actors.push_back(newActor);
}

AEngine* AEngine::Getinstance()
{
	if (!instance)
	{
		instance = new AEngine();
		return instance;
	}
	return instance;
}