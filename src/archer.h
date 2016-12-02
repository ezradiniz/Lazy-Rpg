#ifndef ARCHER_H_
#define ARCHER_H_


#include "arrow.h"
#include "queue.h"
#include "SDL2/SDL.h"

#define WALK_FRAMES 6
#define SHOOTING_FRAMES 6
#define STOPPING_FRAMES 3

typedef struct archer archer_t;

struct archer {
    int x, y, h;
    int speed;
    short int jumping;
    short int direction;
    short int frame;
    short int attack;
    short int shooting;
    long int startTime;
    SDL_Texture *texture;
    SDL_Rect walkSpriteClips[WALK_FRAMES];
    SDL_Rect shootSpriteClips[SHOOTING_FRAMES];
    SDL_Rect stopSpriteClips[STOPPING_FRAMES];
    queue_t *arrows;
    void (*update)(archer_t*);
};

archer_t *init_archer();


#endif
