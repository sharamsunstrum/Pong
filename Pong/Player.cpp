#include "Player.h"

Player::Player(int xp, int yp, int s)
	:speed(s)
{
	playersprite.x = xp;
	playersprite.y = yp;

	playersprite.h = HEIGHT_SPRITE;
	playersprite.w = WIDTH_SPRITE;

}

Player::~Player()
{
	Log("Deallocate memory player", INFO);
}

void DrawPlayer(SDL_Rect p, std::shared_ptr<Screen> r)
{
	SDL_SetRenderDrawColor(r->renderer, COLOR, COLOR, COLOR, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(r->renderer, &p);
}



void MovePlayer(SDL_Event e, SDL_Rect* p, int s)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_w:

			//to make the player teleport to the bottom
			p->y == 0 - HEIGHT_SPRITE ? p->y = HEIGHT : p->y - (p->y -= 1 * s);

			break;
		case SDLK_s:
			//to make the player teleport to the top
			p->y == HEIGHT ? p->y = 0 - HEIGHT_SPRITE : p->y + (p->y += 1 * s);

			break;
		}
		break;
	}

}



void OpponentMovement(SDL_Rect* opponent, std::shared_ptr<Ball>b)
{
	if (b->xb > WIDTH / 2 && b->xb < WIDTH)
	{
		// to make the opponent follow the ball
		(opponent->y != b->yb && b->yb > opponent->y) ? opponent->y = opponent->y + 1 : opponent->y = opponent->y - 1;

	}
	else if (b->xb < WIDTH / 2 && b->xb > 0)
	{
		//to make sure the opponent come back to his initial position
		(opponent->y != HEIGHT / 2 - 40 && opponent->y >= HEIGHT / 2 - 40) ? opponent->y = opponent->y - 1 : opponent->y = opponent->y + 1;

	}
}