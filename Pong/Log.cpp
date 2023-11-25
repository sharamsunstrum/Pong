#include "Log.h"


void Log(const char* m, __int8 l)
{

	switch (l)
	{
	case ERROR:

		std::cerr << "ERROR : " << m << ' ' << SDL_GetError() << '\n';
		SDL_Quit();

		break;
	case WARNING:

		std::cout << "WARNING : " << m << ' ' << SDL_GetError() << '\n';

		break;
	case INFO:

		std::clog << "INFO : " << m << ' ' << SDL_GetError() << '\n';

		break;
	}

}

void Initialization(void* objectpointer, const char* m)
{

	if (objectpointer == nullptr)
	{
		Log(m, ERROR);
		std::cerr << "Failed..." << '\n';
	}
	else
	{

		Log(m, INFO);
		std::clog << "Success..." << '\n';
	}

}