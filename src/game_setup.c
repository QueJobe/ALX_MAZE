#include "raycasting.h"

int TicksLastFrame;
player_t player;

/**
 * setup_game - Initializes player variables and loads wall textures.
 */
void setup_game(void)
{
	player.x = SCREEN_WIDTH / 2;
	player.y = SCREEN_HEIGHT / 2;
	player.width = 1;
	player.height = 30;
	player.walkDirection = 0;
	player.walkSpeed = 100;
	player.turnDirection = 0;
	player.turnSpeed = 45 * (PI / 180);
	player.rotationAngle = PI / 2;
	WallTexturesready();
}

/**
 * update_game - Updates the game state, including delta time calculation,
 *               player movement, and ray casting.
 */
void update_game(void)
{
	float DeltaTime;
	int timeToWait = FRAME_TIME_LENGTH - (SDL_GetTicks() - TicksLastFrame);
	
	if (timeToWait > 0 && timeToWait <= FRAME_TIME_LENGTH)
	{
		SDL_Delay(timeToWait);
	}
	DeltaTime = (SDL_GetTicks() - TicksLastFrame) / 1000.0f;
	
	TicksLastFrame = SDL_GetTicks();
	
	movePlayer(DeltaTime);
	castAllRays();
}
