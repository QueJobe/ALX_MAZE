#include "raycasting.h"

/**
 * render_game - Calls functions to render all elements on the screen.
 */
void render_game(void)
{
	clearColorBuffer(0xFF000000);
	
	renderWall();
	renderMap();
	renderRays();
	renderPlayer();
	
	renderColorBuffer();
}

/**
 * destroy_game - Frees wall textures and destroys the game window.
 */
void destroy_game(void)
{
	freeWallTextures();
	destroyWindow();
}

