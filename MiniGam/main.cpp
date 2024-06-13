#include <iostream>
#include "Engine.h"
using namespace std;

int main()
{
	AEngine::GetInstance()->DrawMap("JamMap.txt");
	AEngine::GetInstance()->Run();




	return 0;
}