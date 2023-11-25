#ifndef _PLAYER
#define _PLAYER

#include "Screen.h"
#include "Log.h"
#include "Score.h"

// p = sprite player , r = renderer
void DrawPlayer(SDL_Rect p, std::shared_ptr<Screen> r);

//it's for the vertical movement, e = event for keyboard
//p is the sprite, and s is the speed of the movement
void MovePlayer(SDL_Event e, SDL_Rect* p, int s);



enum SpriteProperties
{
	HEIGHT_SPRITE = 120,
	WIDTH_SPRITE = 40,
	COLOR = 220
};



class Player :public Screen
{
public:
	//The player parameter are xp = x position
	//yp = y position, and s = speed
	explicit Player(int xp, int yp, int s);
	~Player();

	SDL_Rect playersprite;


	int speed = NULL;
};


struct Ball
{
	int xb{ NULL }, yb{ NULL };
	__int8 radius = NULL;

	int speedball = NULL;

	bool isactive = NULL;

	explicit Ball(int x, int y, int r, int sb);
	~Ball();
};

void BallCollision(std::shared_ptr<Ball> b, SDL_Rect* p, SDL_Rect* o,
	std::shared_ptr<Score>score, std::shared_ptr<Score>opponent);

void DrawBall(std::shared_ptr<Ball> b, SDL_Renderer* re);

void BallMovement(std::shared_ptr<Ball> b, char modifier, char coordinate,
	std::shared_ptr<Score>score, std::shared_ptr<Score>opponent);


void OpponentMovement(SDL_Rect* opponent, std::shared_ptr<Ball>b);

#endif _PLAYER

