#ifndef _SCREEN
#define _SCREEN

#include "Log.h"

enum SizeScreen
{
	WIDTH = 800,
	HEIGHT = 600
};

class Screen
{
private:
	__int16 height = NULL;
	__int16 width = NULL;
	mutable const char* caption = nullptr;

public:
	//Create the windows with this constructor
	//h is height, w width and c is caption
	explicit Screen(__int16 h, __int16 w, const char* c);
	Screen() {};
	~Screen();

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;


	bool gameover = false;
	bool winnerscreen = false;

};


#endif _SCREEN