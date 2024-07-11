#ifndef RAYCASTING_H
#define RAYCASTING_H

#include <SDL2/SDL.h>
#include <math.h>

#define WINDOW_W 800
#define WINDOW_H 600
#define MAP_W 10
#define MAP_H 10
#define FOV 60
#define MOVE_SPEED 0.1f
#define ROTATE_SPEED 0.1f

// Define M_PI if it is not defined
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Define M_PI_2 if it is not defined
#ifndef M_PI_2
#define M_PI_2 (M_PI / 2.0)
#endif

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
