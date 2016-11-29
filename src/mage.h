#ifndef MAGE_H_
#define MAGE_H_


#include "fireball.h"
#include <SDL2/SDL.h>

#define WALKING_FRAMES 7
#define JUMPING_FRAMES 4
#define CASTING_FRAMES 6

typedef struct mage mage_t;

struct mage {
    int x, y, h;
    int speed;
    short int jumping;
    int direction;
    int frame;
    int attack;
    int casting;
    long int startTime;
    SDL_Texture *texture;
    SDL_Rect walkSpriteClips[WALKING_FRAMES];
    SDL_Rect jumpSpriteClips[JUMPING_FRAMES];
    SDL_Rect castSpriteClips[CASTING_FRAMES];
    fireball_t **fireballs;
    void (*update)(mage_t*);
};

mage_t *init_mage();


#endif
