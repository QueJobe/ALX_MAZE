#include "raycasting.h"
#include <math.h>

/**
 * render_scene -  function to render scene
 * @renderer: renderer object to pass
 * @player: player object to pass
 * @map: map object to pass to function
 * return: nothing void
 */

void render_scene(SDL_Renderer *renderer, Player *player,
		int map[MAP_W][MAP_H])
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	int x;

	for (x = 0; x < WINDOW_W; x++)
	{
		float ray_angle = player->angle - (FOV / 2.0f) +
			((float)x / (float)WINDOW_W) * FOV;
		float ray_x = player->x;
		float ray_y = player->y;
		float ray_dx = cos(ray_angle);
		float ray_dy = sin(ray_angle);
		int hit = 0;
		int side;

		while (!hit)
		{
			int map_x = (int)ray_x;
			int map_y = (int)ray_y;

			if (map_x < 0 || map_x >= MAP_W || map_y < 0 || map_y >= MAP_H)
				hit = 1;
			else if (map[map_x][map_y] > 0)
			{
				hit = 1;
				side = (fabs(ray_dx) > fabs(ray_dy)) ? 0 : 1;
			}
			ray_x += ray_dx * 0.1f;
			ray_y += ray_dy * 0.1f;
		}
		float distance = sqrt(pow(ray_x - player->x, 2) +
				pow(ray_y - player->y, 2));
		int wall_ht = (int)(WINDOW_H / distance);
		int wall_top = (WINDOW_H / 2) - (wall_ht / 2);
		int wall_bottom = (WINDOW_H / 2) + (wall_ht / 2);

		SDL_SetRenderDrawColor(renderer, side ? 0 : 255, 0,
				side ? 255 : 0, 255);
		SDL_RenderDrawLine(renderer, x, wall_top, x, wall_bottom);
	}
}
