#include <iostream>
#include "Engine.h"
#include "Actor.h"
#include "Player.h"
#include "Wall.h"
#include "Floor.h"
#include "Monster.h"
#include "Goal.h"
using namespace std;

int main()
{
	AEngine::GetInstance()->DrawMap("JamMap.txt");
	AEngine::GetInstance()->Run();




	return 0;
}