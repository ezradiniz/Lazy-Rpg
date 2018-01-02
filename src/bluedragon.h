#ifndef BLUEDRAGON_H_
#define BLUEDRAGON_H_


#include "waterblade.h"
#include "waterblast.h"
#include "queue.h"
#include "SDL2/SDL.h"

#define BLUE_WALKING_FRAMES 4
#define BLUE_JUMPING_FRAMES 2
#define BLUE_CASTING_FRAMES 4
#define BLUE_STOPPING_FRAMES 4
#define BLUE_MAX_LIFE 50
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
    int is_alive;
    int hit;
    int life;
    SDL_Texture *texture;
    SDL_Rect walkSpriteClips[BLUE_WALKING_FRAMES];
    SDL_Rect jumpSpriteClips[BLUE_JUMPING_FRAMES];
    SDL_Rect castSpriteClips[BLUE_CASTING_FRAMES];
    SDL_Rect stopSpriteClips[BLUE_STOPPING_FRAMES];
    //SDL_Rect specialSpriteClips[SPECIAL_FRAMES];
    queue_t *waterbs;
    queue_t *waterblasts;
    void (*update)(bluedragon_t*);
};

bluedragon_t *init_bluedragon();
void destroy_bluedragon(bluedragon_t *);


#endif
