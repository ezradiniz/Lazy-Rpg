#include "waterblade.h"
#include "util.h"
#include <stdlib.h>



static void _loadMedia(waterb_t *waterb)
{

    waterb->texture = game_loadTexture("img/bluedragon.png",0,0,0);

    waterb->spriteClips[0].x = 176;
    waterb->spriteClips[0].y = 237;
    waterb->spriteClips[0].w = 55;
    waterb->spriteClips[0].h = 63;



}

static void _update(waterb_t *waterb)
{
    int frame = game_animation_frame(waterb->startTime, 1, 500, WATERB_FRAMES);
    SDL_Rect *current = &waterb->spriteClips[frame];

    if (waterb->direction == 1) {

     waterb->x += WATERB_SPEED;

    } else {

     waterb->x -= WATERB_SPEED;

    }
    game_renderTexture(waterb->x,
                       waterb->y,
                       55,
                       63,
                       current,
                       360,
                       NULL,
                       (waterb->direction == 1) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE,
                       waterb->texture);

}

void free_waterb(void *data)
{

}



waterb_t *init_waterb()
{
    waterb_t *waterb = malloc(sizeof(waterb_t));
    waterb->x = 0;
    waterb->y = 0;
    waterb->direction = 1;
    waterb->startTime = SDL_GetTicks();
    _loadMedia(waterb);
    waterb->update = _update;

    return waterb;
}
