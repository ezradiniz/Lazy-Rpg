#ifndef MAGE_H_
#define MAGE_H_


#include "fireball.h"
#include "queue.h"
#include <SDL2/SDL.h>

#define WALKING_FRAMES 4
#define JUMPING_FRAMES 3
#define CASTING_FRAMES 6
#define STOPPING_FRAMES 3

typedef struct mage mage_t;

struct mage {
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
    SDL_Rect castSpriteClips[CASTING_FRAMES];
    SDL_Rect stopSpriteClips[STOPPING_FRAMES];
    queue_t *fireballs;
    void (*update)(mage_t*);
};

mage_t *init_mage();


#endif
