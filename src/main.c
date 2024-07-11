#include <SDL2/SDL.h>
#include "raycasting.h"

/**
 * main - Main entry point
 * @argc: number of aguments
 * @argv: aggument array
 * return: 0 on success
 */

int main(int argc, char *argv[])
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	Player player = {5.0f, 5.0f, 0.0f};
	int map[MAP_W][MAP_H] = {0};
	SDL_Event e;
	int quit = 0;

	if (argc > 1)
	{
		if (!load_map(argv[1], map))
		{
			fprintf(stderr, "Failed to load map from file\n");
			return (1);
		}
	} else
	{
		fprintf(stderr, "Usage: %s <map file>\n", argv[0]);
		return (1);
	}
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
		return (1);
	}
	init_sdl(&window, &renderer);
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
				quit = 1;
		}
		handle_input(&player, map);
		render_scene(renderer, &player, map);
		SDL_RenderPresent(renderer);
	}
	close_sdl(window, renderer);
	SDL_Quit();
	return (0);
}
