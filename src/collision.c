#include "raycasting.h"

/**
 * check_collision - checks for collisions on walls
 * @x: player object
 * @y: player object
 * @map: map object of the function
 * Return: map collision if there was a collision
 */

int check_collision(float x, float y, int map[MAP_W][MAP_H])
{
	int map_x = (int)x;
	int map_y = (int)y;

	if (max_x < 0 || map_x >= MAP_W || may_y < 0 || map_y >= MAP_H)
	{
		return (1);
	}
	return (map[map_x][map_y] > 0);
}
