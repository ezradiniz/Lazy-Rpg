#ifndef SHURIKEN_H_
#define SHURIKEN_H_

#include "SDL2/SDL.h"

#define SHURIKEN_FRAMES 2
#define MAX_SHURIKENS 100
#define SHURIKEN_SPEED 2


typedef struct shuriken shuriken_t;
struct shuriken {
    int x;
    int y;
    int direction;
    long int startTime;
    SDL_Texture *texture;
    SDL_Rect spriteClips[SHURIKEN_FRAMES];
    void (*update)(shuriken_t *);
};

shuriken_t *init_shuriken();
void free_shuriken(void *data);

#endif
