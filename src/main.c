#include <SDL2/SDL.h>
#include "raycasting.h"

bool GameRunning = false;
/**
 * main - Entry point of the game application.
 * Return: 0 on success.
 */
int main(void)
{
	GameRunning = initializeWindow();

	setup_game();

	while (GameRunning)
	{
		handleInput();
		update_game();
		render_game();
	}
	destroy_game();
	return (0);
}
