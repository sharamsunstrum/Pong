#include "Screen.h"
#include "Log.h"
#include "Player.h"
#include "Score.h"



int main(int argc, char** argv)
{
	//is to empty the data of the parameters from main
	(void)argc;
	(void)argv;

	constexpr int     FPS = 60;


	if (SDL_Init(SDL_INIT_VIDEO) < NULL)
	{
		Log("Cannot Initizalize SDL_Init SDL_INIT_VIDEO", ERROR);
	}
	else
	{
		Log("SDL_Init...SDL_INIT_VIDEO, Success", INFO);
	}





	std::shared_ptr<Screen> screen = std::make_shared<Screen>(HEIGHT, WIDTH, "Pong");


	Initialization(screen->window, "Window");
	Initialization(screen->renderer, "Renderer");



	std::shared_ptr<Player>     player = std::make_shared<Player>(5, HEIGHT / 2 - 40, 10);
	std::shared_ptr<Player>     opponent = std::make_shared<Player>(755, HEIGHT / 2 - 40, NULL);
	std::shared_ptr<Ball>       ball = std::make_shared<Ball>(WIDTH / 2, HEIGHT / 2, 15, 2);




	std::shared_ptr<Score>score = std::make_shared<Score>(NULL);
	std::shared_ptr<Score>scoreopponent = std::make_shared<Score>(NULL);




	DrawSpriteScore(screen->renderer, score, (WIDTH / 2) - 200, 100);
	DrawSpriteScore(screen->renderer, scoreopponent, (WIDTH / 2) + 100, 100);
	DrawMessage(screen->renderer, score, (WIDTH / 2) - 100, (HEIGHT / 2) - 100);

	SDL_Event event;


	// main loop
	while (!screen->gameover)
	{
		Uint64 start = SDL_GetPerformanceCounter();



		// it's for the background
		SDL_SetRenderDrawColor(screen->renderer, 10, 10, 10, SDL_ALPHA_OPAQUE);


		SDL_RenderClear(screen->renderer);




		while (SDL_PollEvent(&event))
		{

			if (event.type == SDL_QUIT)
			{
				Log("Quit", INFO);
				screen->gameover = true;
				break;
			}


			MovePlayer(event, &player->playersprite, player->speed);



		}

		OpponentMovement(&opponent->playersprite, ball);

		DrawPlayer(player->playersprite, screen);
		DrawPlayer(opponent->playersprite, screen);
		DrawBall(ball, screen->renderer);



		BallCollision(ball, &player->playersprite, &opponent->playersprite, score, scoreopponent);


		//render the score with a crop
		SDL_RenderCopy(screen->renderer, score->scoresprite, &score->spritecrop, &score->spriteposition);
		SDL_RenderCopy(screen->renderer, scoreopponent->scoresprite, &scoreopponent->spritecrop, &scoreopponent->spriteposition);



		if (score->scoreplayer == 3 || scoreopponent->scoreplayer == 3)
		{
			screen->winnerscreen = true;
			screen->gameover = true;
		}

		SDL_RenderPresent(screen->renderer);


		//fps
		Uint64 end = SDL_GetPerformanceCounter();

		float framerate = (end - start) / (float)SDL_GetPerformanceFrequency();

		SDL_Delay((Uint32)(floor((1000.0f / FPS) - framerate)));





	}

	while (screen->winnerscreen)
	{

		while (SDL_PollEvent(&event))
		{

			if (event.type == SDL_QUIT)
			{
				Log("Quit", INFO);
				screen->winnerscreen = false;
				break;
			}


		}

		if (score->scoreplayer == 3)
		{

			SDL_RenderCopy(screen->renderer, score->message, &score->messagecrop, &score->messageposition);

		}
		if (scoreopponent->scoreplayer == 3)
		{

			score->messagecrop.x += 256;
			SDL_RenderCopy(screen->renderer, score->message, &score->messagecrop, &score->messageposition);
		}

		SDL_RenderPresent(screen->renderer);
	}

	SDL_DestroyRenderer(screen->renderer);
	Log("Renderer deleted", INFO);
	SDL_DestroyWindow(screen->window);
	Log("Windows deleted", INFO);


	SDL_Quit();

	return 0;
}