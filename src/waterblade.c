#include "waterblade.h"
#include "util.h"
#include "collision.h"
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
    if (waterb->is_alive) {
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
}

void free_waterb(void *data)
{
    node_t *node = data;
    waterb_t *waterblade = node->data;
    SDL_DestroyTexture(waterblade->texture);
    free(waterblade);
}

void update_queue_waterblade(queue_t *queue)
{
    waterb_t *waterb;
    node_t *node = queue->head;
    while (node != NULL) {
        waterb = node->data;
        waterb->update(waterb);
        node = node->next;
        if (waterb->x <= 0 || waterb->x >= SCREEN_WIDTH)
            dequeue(queue);
    }
}

int hasIntersectionWaterblade(queue_t *queue, int x, int y, int w, int h)
{
    waterb_t *waterb;
    node_t *node = queue->head;
    while (node != NULL) {
        waterb = node->data;
        if (hasCollision(waterb->x, waterb->y, 52, 57, x, y, w, h)) {
            waterb->is_alive = 0;
            return 1;
        }
        node = node->next;
    }

    return 0;
}

waterb_t *init_waterb()
{
    waterb_t *waterb = malloc(sizeof(waterb_t));
    waterb->x = 20;
    waterb->y = 20;
    waterb->direction = 1;
    waterb->is_alive = 1;
    waterb->startTime = SDL_GetTicks();
    _loadMedia(waterb);
    waterb->update = _update;

    return waterb;
}
