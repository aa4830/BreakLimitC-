#pragma once
#include <iostream>
#include <vector>
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
	static AEngine* Instance;
	bool IsRunning;
	char Key;
	void Tick();
	void Render();
	void Input();
	void Run();
	void DrawMap(std::string MapFileName);
	void SpawnActor(AActor* NewActor);

	vector<AActor*>Actors;


protected:
	AEngine();
};

