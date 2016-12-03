#ifndef WATERBLAST_H_
#define WATERBLAST_H_

#include "SDL2/SDL.h"

#define WATERBLAST_FRAMES 2
#define MAX_WATERBLASTS 100
#define WATERBLAST_SPEED 2


typedef struct waterblast waterblast_t;
struct waterblast {
    int x;
    int y;
    int direction;
    long int startTime;
    SDL_Texture *texture;
    SDL_Rect spriteClips[WATERBLAST_FRAMES];
    void (*update)(waterblast_t *);
};

waterblast_t *init_waterblast();
void free_waterblast(void *data);

#endif
