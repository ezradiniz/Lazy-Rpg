#ifndef BIGFIREBALL_H_
#define BIGFIREBALL_H_

#include "queue.h"
#include "SDL2/SDL.h"

#define BIGFIREBALL_FRAMES 5
#define MAX_BIGFIREBALLS 100
#define BIGFIREBALL_SPEED 2


typedef struct bigfireball bigfireball_t;
struct bigfireball {
    int x;
    int y;
    int direction;
    long int startTime;
    SDL_Texture *texture;
    SDL_Rect spriteClips[BIGFIREBALL_FRAMES];
    void (*update)(bigfireball_t *);
};

bigfireball_t *init_bigfireball();
void free_bigfireball(void *data);
void update_queue_bigfireball(queue_t *queue);
int hasIntersectionBigFireball(queue_t *queue, int x, int y, int w, int h);

#endif
