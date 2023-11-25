#ifndef _LOG
#define _LOG

#include <SDL.h>
#include <iostream>
#include <string>
#include <memory>
#include <SDL_image.h>


typedef enum
{

	ERROR,
	WARNING,
	INFO

}LevelLog;

//The 'm' is the message of the log, and 'l' is the level
//of it. level you have : ERROR, WARNING, INFO
void Log(const char* m, __int8 l);

//Take a SDL struct pointer, and check if it can allocate
//memory to it, second argument 'm' is Message to display
void Initialization(void* objectpointer, const char* m);



#endif _LOG

