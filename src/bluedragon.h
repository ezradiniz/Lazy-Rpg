#ifndef BLUEDRAGON_H_
#define BLUEDRAGON_H_


#include "waterblade.h"
#include "waterblast.h"
#include "queue.h"
#include "SDL2/SDL.h"

#define WALKING_FRAMES 4
#define JUMPING_FRAMES 2
#define CASTING_FRAMES 4
#define STOPPING_FRAMES 4
//#define SPECIAL_FRAMES 4

typedef struct bluedragon bluedragon_t;

struct bluedragon {
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
    //SDL_Rect specialSpriteClips[SPECIAL_FRAMES];
    queue_t *waterbs;
    queue_t *waterblasts;
    void (*update)(bluedragon_t*);
};

bluedragon_t *init_bluedragon();


#endif
