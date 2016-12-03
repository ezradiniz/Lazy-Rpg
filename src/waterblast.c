#include "waterblast.h"
#include "util.h"
#include <stdlib.h>



static void _loadMedia(waterblast_t *waterblast)
{

    waterblast->texture = game_loadTexture("img/bluedragon.png",0,0,0);

    waterblast->spriteClips[0].x = 403;
    waterblast->spriteClips[0].y = 687;
    waterblast->spriteClips[0].w = 47;
    waterblast->spriteClips[0].h = 64;
    
    waterblast->spriteClips[1].x = 352;
    waterblast->spriteClips[1].y = 691;
    waterblast->spriteClips[1].w = 54;
    waterblast->spriteClips[1].h = 61;



}

static void _update(waterblast_t *waterblast)
{
    int frame = game_animation_frame(waterblast->startTime, 2, 500, WATERBLAST_FRAMES);
    SDL_Rect *current = &waterblast->spriteClips[frame];

    if (waterblast->direction == 1) {

     waterblast->x += WATERBLAST_SPEED;

    } else {

     waterblast->x -= WATERBLAST_SPEED;

    }
    game_renderTexture(waterblast->x,
                       waterblast->y,
                       47,
                       64,
                       current,
                       360,
                       NULL,
                       (waterblast->direction == 1) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE,
                       waterblast->texture);

}

void free_waterblast(void *data)
{

}



waterblast_t *init_waterblast()
{
    waterblast_t *waterblast = malloc(sizeof(waterblast_t));
    waterblast->x = 0;
    waterblast->y = 0;
    waterblast->direction = 1;
    waterblast->startTime = SDL_GetTicks();
    _loadMedia(waterblast);
    waterblast->update = _update;

    return waterblast;
}
