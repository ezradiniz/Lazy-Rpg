#include "katon.h"
#include "util.h"
#include <stdlib.h>



static void _loadMedia(katon_t *katon)
{

    katon->texture = game_loadTexture("img/itachi.png", 0, 64, 128);

    katon->spriteClips[0].x = 179;
    katon->spriteClips[0].y = 2435;
    katon->spriteClips[0].w = 74;
    katon->spriteClips[0].h = 52;

    katon->spriteClips[1].x = 255;
    katon->spriteClips[1].y = 2436;
    katon->spriteClips[1].w = 77;
    katon->spriteClips[1].h = 52;
    
    katon->spriteClips[2].x = 332;
    katon->spriteClips[2].y = 2435;
    katon->spriteClips[2].w = 72;
    katon->spriteClips[2].h = 56;
    
    katon->spriteClips[3].x = 407;
    katon->spriteClips[3].y = 2438;
    katon->spriteClips[3].w = 68;
    katon->spriteClips[3].h = 47;


}

static void _update(katon_t *katon)
{
    int frame = game_animation_frame(katon->startTime, 4, 500, KATON_FRAMES);
    SDL_Rect *current = &katon->spriteClips[frame];

    if (katon->direction == 1) {
     katon->x += KATON_SPEED;
    } else {
     katon->x -= KATON_SPEED;
    }
    
    game_renderTexture(katon->x,
                       katon->y,
                       74,
                       52,
                       current,
                       360,
                       NULL,
                       (katon->direction == 1) ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL,
                       katon->texture);

}

void free_katon(void *data)
{

}



katon_t *init_katon()
{
    katon_t *katon = malloc(sizeof(katon_t));
    katon->x = 0;
    katon->y = 0;
    katon->direction = 1;
    katon->startTime = SDL_GetTicks();
    _loadMedia(katon);
    katon->update = _update;

    return katon;
}
