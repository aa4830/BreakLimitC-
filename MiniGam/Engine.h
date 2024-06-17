#pragma once
#include <iostream>
#include <vector>
#include "SDL.h"
#include <string>
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")
#pragma comment(lib, "SDL2_mixer")
#pragma comment(lib, "SDL2_ttf")
using namespace std;
class AActor;

class AEngine
{
public: 
	virtual ~AEngine();

	static AEngine* GetInstance()
	{
		if (!Instance)
		{
			Instance = new AEngine();

			return Instance;
		}

		return Instance;
	}
	void Init();

	void Term();

	void Run();

	void DrawMap(std::string MapFileName);

	void SpawnActor(AActor* NewActor);

	void SortLayer();
	static int KeyCode;
	vector<AActor*>Actors;
	SDL_Window* MyWindow;
	SDL_Renderer* MyRenderer;
	SDL_Event MyEvent;
	bool IsRunning;
	inline Uint64 GetWorldDeltaSeconds() { return DeltaSeconds; }

protected:
	void Input();
	void Tick();
	void Render();
	Uint64 DeltaSeconds;
	Uint64 LastTime;

	static AEngine* Instance;

	AEngine();
};

