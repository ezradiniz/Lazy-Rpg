#ifndef _WORLD_H_
#define _WORLD_H_

#include "SDL2/SDL.h"

#define WORLD_MAPS 3

typedef struct world world_t;
struct world {
    int y;
    int frame;
    SDL_Texture *texture[WORLD_MAPS];
    void (*update)(world_t *);
};

world_t *init_world();
void destroy_world(world_t *);

#endif
