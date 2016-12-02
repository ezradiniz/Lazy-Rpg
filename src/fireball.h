#ifndef AMMO_H_
#define AMMO_H_

#include <SDL2/SDL.h>

#define FIREBALL_FRAMES 4
#define MAX_FIREBALLS 100
#define FIREBALL_SPEED 2


typedef struct fireball fireball_t;
struct fireball {
    int x;
    int y;
    int direction;
    long int startTime;
    SDL_Texture *texture;
    SDL_Rect spriteClips[FIREBALL_FRAMES];
    void (*update)(fireball_t *);
};

fireball_t *init_fireball();
void free_fireball(void *data);

#endif
