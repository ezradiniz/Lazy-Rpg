#include "fireball.h"
#include "util.h"
#include <stdlib.h>



static void _loadMedia(fireball_t *fireball)
{

    fireball->texture = game_loadTexture("img/fireball.png");

    fireball->spriteClips[0].x = 11;
    fireball->spriteClips[0].y = 12;
    fireball->spriteClips[0].w = 29;
    fireball->spriteClips[0].h = 35;

    fireball->spriteClips[1].x = 45;
    fireball->spriteClips[1].y = 12;
    fireball->spriteClips[1].w = 29;
    fireball->spriteClips[1].h = 35;

    fireball->spriteClips[2].x = 80;
    fireball->spriteClips[2].y = 12;
    fireball->spriteClips[2].w = 29;
    fireball->spriteClips[2].h = 35;

    fireball->spriteClips[3].x = 114;
    fireball->spriteClips[3].y = 12;
    fireball->spriteClips[3].w = 29;
    fireball->spriteClips[3].h = 35;


}

static void _update(fireball_t *fireball)
{
     Uint32 newTime = SDL_GetTicks();
    int frame = ((newTime - fireball->startTime) * 4 /500) % FIREBALL_FRAMES;

    SDL_Rect *current = &fireball->spriteClips[frame];

    if (fireball->direction == 1) {
        game_renderTexture(fireball->x,
                       fireball->y,
                       29,
                       35,
                       current,
                       360,
                       NULL,
                       SDL_FLIP_NONE,
                       fireball->texture);
     fireball->x += FIREBALL_SPEED;

    } else {
        game_renderTexture(fireball->x,
                       fireball->y,
                       29,
                       35,
                       current,
                       360,
                       NULL,
                       SDL_FLIP_HORIZONTAL,
                       fireball->texture);
     fireball->x -= FIREBALL_SPEED;

    }

}

fireball_t *init_fireball()
{
    fireball_t *fireball = malloc(sizeof(fireball_t));
    fireball->x = 0;
    fireball->y = 0;
    fireball->direction = 1;
    fireball->startTime = SDL_GetTicks();
    _loadMedia(fireball);
    fireball->update = _update;

    return fireball;
}
