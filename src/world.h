#ifndef _WORLD_H_
#define _WORLD_H_

#include <SDL2/SDL.h>

typedef struct world world_t;
struct world {
    int x;
    int y;
    SDL_Texture *texture;
    void (*update)(world_t *);
};

world_t *init_world();

#endif
