#include "raycasting.h"
#include "sdl_utils.h"
#include <SDL2/SDL_image.h>
#include <stdio.h>

SDL_Texture *loadTexture(const char *filePath, SDL_Renderer *renderer)
{
	SDL_Texture *newTexture = NULL;
	SDL_Surface *loadedSurface = IMG_Load(filePath);
	
	if (loadedSurface == NULL)
	{
		fprintf(stderr, "Unable to load image %s! SDL_image Error: %s\n", filePath, IMG_GetError());
		return (NULL);
	}
	
	newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	if (newTexture == NULL)
	{
		fprintf(stderr, "Unable to create texture from %s! SDL Error: %s\n", filePath, SDL_GetError());
	}
	
	SDL_FreeSurface(loadedSurface);
	
	return (newTexture);
}

