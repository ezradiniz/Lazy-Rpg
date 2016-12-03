#ifndef ITACHI_H_
#define ITACHI_H_


#include "shuriken.h"
#include "katon.h"
#include "queue.h"
#include "SDL2/SDL.h"

#define WALKING_FRAMES 6
#define JUMPING_FRAMES 3
#define SHURIKEN_FRAMES 7
#define KATON_FRAMES 7
#define STOPPING_FRAMES 7

typedef struct itachi itachi_t;

struct itachi {
    int x, y, h;
    int speed;
    short int jumping;
    short int direction;
    short int frame;
    short int attack;
    short int casting;
    long int startTime;
    SDL_Texture *texture;
    SDL_Rect walkSpriteClips[WALKING_FRAMES];
    SDL_Rect jumpSpriteClips[JUMPING_FRAMES];
    SDL_Rect shurikenSpriteClips[SHURIKEN_FRAMES];
    SDL_Rect stopSpriteClips[STOPPING_FRAMES];
    SDL_Rect katonSpriteClips[KATON_FRAMES];
    queue_t *shurikens;
    queue_t *katons;  
    void (*update)(itachi_t*);
};

itachi_t *init_itachi();


#endif
