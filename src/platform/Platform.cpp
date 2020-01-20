#include "Platform.h"
#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

bool Platform::Init() {

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << '\n';
		return false;
	}

	return true;
}


void Platform::Release()
{
	SDL_Quit();
}

bool Platform::Tick()
{
	bool quit = false;
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)				quit = true;
		if (e.type == SDL_KEYDOWN)			quit = true;
		if (e.type == SDL_MOUSEBUTTONDOWN)	quit = true;
	}

	return !quit;
}
