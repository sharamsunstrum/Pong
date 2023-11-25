#include "Score.h"

Score::Score(int sp)
	:scoreplayer(sp)
{

	filename = "score.png";
	filemessage = "winorloose.png";
}

Score::~Score()
{
	Log("Score deallocate", INFO);


}


void DrawSpriteScore(SDL_Renderer* r, std::shared_ptr<Score>sprite, int x, int y)
{
	sprite->scoresprite = IMG_LoadTexture(r, sprite->filename);
	SDL_QueryTexture(sprite->scoresprite, NULL, NULL, &sprite->wtexture, &sprite->htexture);

	//separate the sprite into 4 parts
	sprite->wframe = sprite->wtexture / 4;
	sprite->hframe = sprite->htexture;

	sprite->spritecrop.x = sprite->spritecrop.y = 0;
	sprite->spritecrop.w = sprite->wframe;
	sprite->spritecrop.h = sprite->hframe;


	//set the position
	sprite->spriteposition.x = x;
	sprite->spriteposition.y = y;

	sprite->spriteposition.w = sprite->spriteposition.h = 128;

}

void DrawMessage(SDL_Renderer* r, std::shared_ptr<Score>message, int x, int y)
{
	message->message = IMG_LoadTexture(r, message->filemessage);
	SDL_QueryTexture(message->message, NULL, NULL, &message->sizew, &message->sizeh);

	message->croph = message->sizeh;
	message->cropw = message->sizew / 2;

	message->messagecrop.x = message->messagecrop.y = 0;
	message->messagecrop.h = message->croph;
	message->messagecrop.w = message->cropw;

	message->messageposition.x = x;
	message->messageposition.y = y;

	message->messageposition.w = message->messageposition.h = 256;

}


