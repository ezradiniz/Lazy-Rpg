#ifndef AMMO_H_
#define AMMO_H_

#include "SDL2/SDL.h"
#include "queue.h"

#define FIREBALL_FRAMES 4
#define MAX_FIREBALLS 100
#define FIREBALL_SPEED 2


typedef struct fireball fireball_t;
struct fireball {
    int x;
    int y;
    int direction;
    int is_alive;
    long int startTime;
    SDL_Texture *texture;
    SDL_Rect spriteClips[FIREBALL_FRAMES];
    void (*update)(fireball_t *);
};

fireball_t *init_fireball();
void free_fireball(void *data);
void update_queue_fireball(queue_t *queue);
int hasIntersectionFireball(queue_t *queue, int x, int y, int w, int h);


#endif
