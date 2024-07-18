#include "raycasting.h"
#include "sdl_utils.h"

extern SDL_Renderer *renderer;
extern SDL_Texture *wallTexture;
extern SDL_Texture *floorTexture;
extern SDL_Texture *ceilingTexture;

void renderFloor(int wallBottomPixel, color_t *texelColor, int x)
{
	int y;
	SDL_Rect srcRect, destRect;
	for (y = wallBottomPixel - 1; y < SCREEN_HEIGHT; y++)
	{
		float distance = (player.height / (y - SCREEN_HEIGHT / 2))
			* PROJ_PLANE;
		int textureX = (int)(distance * cos(rays[x].rayAngle))
			% floorTextureWidth;
		int textureY = (int)(distance * sin(rays[x].rayAngle))
			% floorTextureHeight;

		srcRect.x = textureX;
		srcRect.y = textureY;
		srcRect.w = 1;
		srcRect.h = 1;
		destRect.x = x;
		destRect.y = y;
		destRect.w = 1;
		destRect.h = 1;

		SDL_RenderCopy(renderer, floorTexture, &srcRect, &destRect);
	}
}

void renderCeil(int wallTopPixel, color_t *texelColor, int x)
{
	int y;
	SDL_Rect srcRect, destRect;
	for (y = 0; y < wallTopPixel; y++)
	{
		float distance = (player.height / (y - SCREEN_HEIGHT / 2))
			* PROJ_PLANE;
		int textureX = (int)(distance * cos(rays[x].rayAngle))
			% ceilingTextureWidth;
		int textureY = (int)(distance * sin(rays[x].rayAngle))
			% ceilingTextureHeight;

		srcRect.x = textureX;
		srcRect.y = textureY;
		srcRect.w = 1;
		srcRect.h = 1;
		destRect.x = x;
		destRect.y = y;
		destRect.w = 1;
		destRect.h = 1;

		SDL_RenderCopy(renderer, ceilingTexture, &srcRect, &destRect);
	}
}

void renderWall(void)
{
	int x, y;
	SDL_Rect srcRect, destRect;

	for (x = 0; x < NUM_RAYS; x++)
	{
		float perpDistance = rays[x].distance * cos(rays[x].rayAngle - player.rotationAngle);
		int wallStripHeight = (TILE_SIZE / perpDistance) * PROJ_PLANE;
		int wallTopPixel = (SCREEN_HEIGHT / 2) - (wallStripHeight / 2);
		int wallBottomPixel = (SCREEN_HEIGHT / 2) + (wallStripHeight / 2);

		wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;
		wallBottomPixel = wallBottomPixel > SCREEN_HEIGHT ? SCREEN_HEIGHT : wallBottomPixel;

		renderFloor(wallBottomPixel, NULL, x);
		renderCeil(wallTopPixel, NULL, x);

		for (y = wallTopPixel; y < wallBottomPixel; y++)
		{
			int textureX = (rays[x].wasHitVertical ? (int)rays[x].wallHitY % TILE_SIZE
					: (int)rays[x].wallHitX % TILE_SIZE);
			int distanceFromTop = y + (wallStripHeight / 2)
				- (SCREEN_HEIGHT / 2);
			int textureY = distanceFromTop *
				((float)wallTextureHeight / wallStripHeight);

			srcRect.x = textureX;
			srcRect.y = textureY;
			srcRect.w = 1;
			srcRect.h = 1;
			destRect.x = x;
			destRect.y = y;
			destRect.w = 1;
			destRect.h = 1;

			SDL_RenderCopy(renderer, wallTexture, &srcRect, &destRect);
		}
	}
}

