#include "raycasting.h"

/**
 * handle_input - function to handle input
 * @player: player object passed to function
 * @map: map object to pass
 * return: Null void function
 */

void handle_input(Player *player, int map[MAP_W][MAP_H])
{
	const Uint8 *keystate = SDL_GetKeyboardState(NULL);

	if (keystate[SDL_SCANCODE_LEFT])
		player->angle -= ROTATE_SPEED;
	if (keystate[SDL_SCANCODE_RIGHT])
		player->angle += ROTATE_SPEED;
	if (keystate[SDL_SCANCODE_W])
	{
		float new_x = player->x + cos(player->angle) * MOVE_SPEED;
		float new_y = player->y + sin(player->angle) * MOVE_SPEED;

		if (!check_collision(new_x, new_y, map))
		{
			player->x = new_x;
			player->y = new_y;
		}
	}
	if (keystate[SDL_SCANCODE_S])
	{
		float new_x = player->x - cos(player->angle) * MOVE_SPEED;
		float new_y = player->y - sin(player->angle) * MOVE_SPEED;
		if (!check_collision(new_x, new_y, map))
		{
			player->x = new_x;
			player->y = new_y;
		}
	}
	if (keystate[SDL_SCANCODE_A])
	{
		float new_x = player->x + cos(player->angle - M_PI_2) * MOVE_SPEED;
		float new_y = player->y + sin(player->angle - M_PI_2) * MOVE_SPEED;

		if (!check_collision(new_x, new_y, map))
		{
			player->x = new_x;
			player->y = new_y;
		}
	}
	if (keystate[SDL_SCANCODE_D])
	{
		float new_x = player->x + cos(player->angle + M_PI_2) * MOVE_SPEED;
		float new_y = player->y + sin(player->angle + M_PI_2) * MOVE_SPEED;

		if (!check_collision(new_x, new_y, map))
		{
			player->x = new_x;
			player->y = new_y;
		}
	}
}
