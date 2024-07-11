#include "raycasting.h"

/**
 * init_sdl - create the game window
 * @window: passes the window object
 * @renderer: the renderer of the function
 * return: Nothing void
 */

void init_sdl(SDL_Window **window, SDL_Renderer **renderer)
{
	*window = SDL_CreateWindow("Raycasting Game",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			WINDOW_W,
			WINDOW_H,
			SDL_WINDOW_SHOWN);

	if (*window == NULL)
	{
		fprintf(stderr, "Error creating window: %s\n", SDL_GetError());
		exit(1);
	}

	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);

	if (*renderer == NULL)
	{
		fprintf(stderr, "Error creating renferer: %s\n", SDL_GetError());
		exit(1);
	}
}

/**
 * close_sdl - function to close game window
 * @window: window object to pass/ create
 * @renderer: rendere object to pass
 * return: nothing void
 */

void close_sdl(SDL_Window *window, SDL_Renderer *renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
