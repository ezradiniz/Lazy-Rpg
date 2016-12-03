#ifndef KATON_H_
#define KATON_H_

#include "SDL2/SDL.h"

#define KATON_FRAMES 4
#define MAX_KATONS 100
#define KATON_SPEED 2


typedef struct katon katon_t;
struct katon {
    int x;
    int y;
    int direction;
    long int startTime;
    SDL_Texture *texture;
    SDL_Rect spriteClips[KATON_FRAMES];
    void (*update)(katon_t *);
};

katon_t *init_katon();
void free_katon(void *data);

#endif
