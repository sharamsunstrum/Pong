#include "Screen.h"


Screen::Screen(__int16 h, __int16 w, const char* c)
	:height(h), width(w), caption(c)
{
	window = SDL_CreateWindow(
		c,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		w, h,
		SDL_WINDOW_SHOWN
	);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

}

Screen::~Screen()
{

}