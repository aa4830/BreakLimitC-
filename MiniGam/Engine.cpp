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
using namespace std;
#include <iostream>

AEngine* AEngine::Instance = nullptr;

AEngine::AEngine()
{
	IsRunning = true;
	Key = ' ';
}

AEngine::~AEngine()
{
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
	Key = _getch();
}

void AEngine::Run()
{
	while (IsRunning)
	{
		Input();
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
	while (InputFile.getline(Map, 80))
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
		}
		++Y;
	}
	SortLayer();
	InputFile.close();
}