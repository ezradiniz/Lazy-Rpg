<<<<<<< HEAD
#ifndef ARROW_H
#define ARROW_H
=======
#ifndef ARROW_H_
#define ARROW_H_
>>>>>>> 8bc4d871827535d672b36dee4650f4069904f077

#include "SDL2/SDL.h"

#define ARROW_FRAMES 1
#define MAX_ARROWS 100
#define ARROW_SPEED 2


typedef struct arrow arrow_t;
struct arrow {
    int x;
    int y;
    int direction;
    long int startTime;
    SDL_Texture *texture;
    SDL_Rect spriteClips[ARROW_FRAMES];
    void (*update)(arrow_t *);
};

arrow_t *init_arrow();
void free_arrow(void *data);

#endif
