#include "arrow.h"
#include "util.h"
#include <stdlib.h>



static void _loadMedia(arrow_t *arrow)
{

    arrow->texture = game_loadTexture("img/archer.png",255,33,211);

    arrow->spriteClips[0].x = 127;
    arrow->spriteClips[0].y = 146;
    arrow->spriteClips[0].w = 48;
    arrow->spriteClips[0].h = 20;

}

static void _update(arrow_t *arrow)
{
    int frame = game_animation_frame(arrow->startTime, 1, 500, ARROW_FRAMES);
    SDL_Rect *current = &arrow->spriteClips[frame];

    if (arrow->direction == 1) {

     arrow->x += ARROW_SPEED;

    } else {

     arrow->x -= ARROW_SPEED;

    }
    game_renderTexture(arrow->x,
                       arrow->y,
                       48,
                       20,
                       current,
                       360,
                       NULL,
                       (arrow->direction == 1) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE,
                       arrow->texture);

}

void free_arrow(void *data)
{

}



arrow_t *init_arrow()
{
    arrow_t *arrow = malloc(sizeof(arrow_t));
    arrow->x = 0;
    arrow->y = 0;
    arrow->direction = 1;
    arrow->startTime = SDL_GetTicks();
    _loadMedia(arrow);
    arrow->update = _update;

    return arrow;
}
