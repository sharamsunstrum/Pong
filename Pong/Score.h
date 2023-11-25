#ifndef _SCORE
#define _SCORE

#include "Log.h"

struct Score
{
	int scoreplayer = NULL;

	//score sprite 246 x 1024
	const char* filename = nullptr;
	SDL_Rect spritecrop = { 0 };
	SDL_Rect spriteposition = { 0 };
	int wframe{ NULL }, hframe{ NULL };
	int wtexture{ NULL }, htexture{ NULL };

	SDL_Texture* scoresprite = nullptr;

	//message sprite 246 x 512
	const char* filemessage = nullptr;
	SDL_Texture* message = nullptr;
	SDL_Rect messagecrop = { 0 };
	SDL_Rect messageposition = { 0 };
	int sizeh{ NULL }, sizew{ NULL };
	int croph{ NULL }, cropw{ NULL };

	Score(int sp);
	~Score();
};

void DrawSpriteScore(SDL_Renderer* r, std::shared_ptr<Score>sprite, int x, int y);
void DrawMessage(SDL_Renderer* r, std::shared_ptr<Score>message, int x, int y);


#endif _SCORE

