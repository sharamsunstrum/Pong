#include "Player.h"

Ball::Ball(int x, int y, int r, int sb)
	:xb(x), yb(y), radius(r), speedball(sb)
{
	isactive = true;
}

Ball::~Ball()
{
	Log("Ball destroy", INFO);
}

//Arguments are b = Ball object, r is the radius, and re the renderer
void DrawBall(std::shared_ptr<Ball> b, SDL_Renderer* re)
{

	int diameter = b->radius * 2;

	SDL_SetRenderDrawColor(re, COLOR, COLOR, COLOR, SDL_ALPHA_OPAQUE);

	for (int width = 0; width < diameter; width++)
	{
		for (int height = 0; height < diameter; height++)
		{
			int dx = b->radius - width;
			int dy = b->radius - height;

			if ((dx * dx + dy * dy) <= (b->radius * b->radius))
			{
				SDL_RenderDrawPoint(re, b->xb + dx, b->yb + dy);
			}

		}
	}


}


void BallCollision(std::shared_ptr<Ball> b, SDL_Rect* p, SDL_Rect* o,
	std::shared_ptr<Score>score, std::shared_ptr<Score>opponent)
{

	static int direction;


	bool wallup = b->yb <= 0;
	bool walldown = b->yb >= HEIGHT;

	bool opponentbounce = b->xb > o->x && b->yb >= o->y && b->yb < o->y + HEIGHT_SPRITE;
	bool playerbounce = b->xb < p->x + WIDTH_SPRITE && b->yb >= p->y && b->yb < p->y + HEIGHT_SPRITE;

	if (b->isactive)
	{
		srand((unsigned)time(NULL));
		direction = rand() % 4 + 1;
		b->isactive = false;
	}

	switch (direction)
	{
	case 1:

		BallMovement(b, '-', 'y', score, opponent);
		BallMovement(b, '+', 'x', score, opponent);

		//to bounce on wall
		if (wallup)
			direction = 3;

		//to bounce on opponent
		if (opponentbounce)
			direction = 2;

		break;
	case 2:

		BallMovement(b, '-', 'y', score, opponent);
		BallMovement(b, '-', 'x', score, opponent);

		//to bounce on wall
		if (wallup)
			direction = 4;

		//to bounce on player
		if (playerbounce)
			direction = 1;


		break;
	case 3:


		BallMovement(b, '+', 'y', score, opponent);
		BallMovement(b, '+', 'x', score, opponent);

		//to bounce on wall
		if (walldown)
			direction = 1;

		//to bounce on opponent
		if (opponentbounce)
			direction = 4;


		break;
	case 4:

		BallMovement(b, '+', 'y', score, opponent);
		BallMovement(b, '-', 'x', score, opponent);

		//to bounce on wall
		if (walldown)
			direction = 2;

		//to bounce on player
		if (playerbounce)
			direction = 3;

		break;

	}


}

void BallMovement(std::shared_ptr<Ball> b, char modifier, char coordinate,
	std::shared_ptr<Score>score, std::shared_ptr<Score>opponent)
{

	switch (modifier)
	{
	case '+':

		(coordinate == 'y') ? b->yb = b->yb + 1 * b->speedball : b->xb = b->xb + 1 * b->speedball;

		break;
	case '-':

		(coordinate == 'y') ? b->yb = b->yb - 1 * b->speedball : b->xb = b->xb - 1 * b->speedball;

		break;
	}


	if (b->xb > WIDTH || b->xb < 0)
	{



		if (b->xb > WIDTH)
		{
			score->scoreplayer = score->scoreplayer + 1;
			score->spritecrop.x = score->spritecrop.x + 256;

		}
		else
		{
			opponent->scoreplayer = opponent->scoreplayer + 1;
			opponent->spritecrop.x = opponent->spritecrop.x + 256;
		}




		b->yb = HEIGHT / 2;
		b->xb = WIDTH / 2;




		std::cout << "Player : " << score->scoreplayer << '\n';
		std::cout << "Opponent : " << opponent->scoreplayer << '\n';



		b->isactive = true;
	}
}