#include "shuriken.h"
#include "util.h"
#include <stdlib.h>



static void _loadMedia(shuriken_t *shuriken)
{

    shuriken->texture = game_loadTexture("img/itachi.png", 0, 64, 128);

    shuriken->spriteClips[0].x = 381;
    shuriken->spriteClips[0].y = 1822;
    shuriken->spriteClips[0].w = 43;
    shuriken->spriteClips[0].h = 49;

    shuriken->spriteClips[1].x = 423;
    shuriken->spriteClips[1].y = 1820;
    shuriken->spriteClips[1].w = 35;
    shuriken->spriteClips[1].h = 50;


}

static void _update(shuriken_t *shuriken)
{
    int frame = game_animation_frame(shuriken->startTime, 4, 500, SHURIKEN_FRAMES);
    SDL_Rect *current = &shuriken->spriteClips[frame];

    if (shuriken->direction == 1) {
     shuriken->x += SHURIKEN_SPEED;
    } else {
     shuriken->x -= SHURIKEN_SPEED;
    }
    
    game_renderTexture(shuriken->x,
                       shuriken->y,
                       43,
                       49,
                       current,
                       360,
                       NULL,
                       (shuriken->direction == 1) ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL,
                       shuriken->texture);

}

void free_shuriken(void *data)
{

}



shuriken_t *init_shuriken()
{
    shuriken_t *shuriken = malloc(sizeof(shuriken_t));
    shuriken->x = 0;
    shuriken->y = 0;
    shuriken->direction = 1;
    shuriken->startTime = SDL_GetTicks();
    _loadMedia(shuriken);
    shuriken->update = _update;

    return shuriken;
}
