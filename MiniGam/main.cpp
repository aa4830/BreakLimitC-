#include "Engine.h"

int SDL_main(int argc, char* argv[])
{
	AEngine::GetInstance()->DrawMap("JamMap.txt");
	AEngine::GetInstance()->Run();

	delete AEngine::GetInstance();

	return 0;
}