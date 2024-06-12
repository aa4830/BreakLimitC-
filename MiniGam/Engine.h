#pragma once
#include <iostream>
#include <vector>
using namespace std;
class AActor;

class AEngine
{
public: 
	virtual ~AEngine();
	bool IsRunning;
	
	void Tick();
	void Render();
	void Input();
	void Run();
	void DrawMap(std::string MapFileName);

	std::vector<AActor*>Actors;

	vector<int*> X;

	void SpawnActor(AActor* NewActor);

	static AEngine* instance;
	static AEngine* Getinstance();

protected:
	AEngine();
};

