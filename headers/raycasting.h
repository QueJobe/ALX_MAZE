#ifndef RAYCASTING_H
#define RAYCASTING_H

#include <SDL2/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define MAP_W 10
#define MAP_H 10
#define FOV 60
#define MOVE_SPEED 0.1f
#define ROTATE_SPEED 0.1f

typedef struct {
    float x;
    float y;
    float angle;
} Player;

void init_sdl(SDL_Window **window, SDL_Renderer **renderer);
void close_sdl(SDL_Window *window, SDL_Renderer *renderer);
void render_scene(SDL_Renderer *renderer, Player *player, int map[MAP_W][MAP_H]);
void handle_input(Player *player, int map[MAP_W][MAP_H]);
int check_collision(float x, float y, int map[MAP_W][MAP_H]);
int load_map(const char *filename, int map[MAP_W][MAP_H]);

#endif // RAYCASTING_H
