#include "fireball.h"
#include "util.h"
#include "collision.h"
#include <stdlib.h>


static void _loadMedia(fireball_t *fireball)
{

    fireball->texture = game_loadTexture("img/fireball.png", 128, 128, 128);

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
   
    int frame = game_animation_frame(fireball->startTime, 4, 500, FIREBALL_FRAMES);
    SDL_Rect *current = &fireball->spriteClips[frame];

    if (fireball->direction == 1) {
     fireball->x += FIREBALL_SPEED;
    } else {
     fireball->x -= FIREBALL_SPEED;
    }

    if (fireball->is_alive) {
        game_renderTexture(fireball->x,
                           fireball->y,
                           29,
                           35,
                           current,
                           360,
                           NULL,
                           (fireball->direction == 1) ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL,
                           fireball->texture);
    }
}

void free_fireball(void *data)
{
    node_t *node = data;
    fireball_t *fireball = node->data;
    SDL_DestroyTexture(fireball->texture);
    free(fireball);
}

void update_queue_fireball(queue_t *queue)
{
    fireball_t *fireball = NULL;
    node_t *node = queue->head;
    while (node != NULL) {
        fireball = node->data;
        fireball->update(fireball);

        node = node->next;
        if (fireball->x <= 0 || fireball->x >= SCREEN_WIDTH)
            dequeue(queue);
    }
}

// 33, 46
int hasIntersectionFireball(queue_t *queue, int x, int y, int w, int h) 
{
    fireball_t *fireball;
    node_t *node = queue->head;
    while (node != NULL) {
        fireball = node->data;
        if ((fireball->x >= x+w && fireball->direction == 1 && fireball->x <= x+2*w) || 
            (fireball->x <= x-w && fireball->direction == -1 && fireball->x >= x-2*w)) {
            fireball->is_alive = 0;
        }
        if (hasCollision(fireball->x, fireball->y, 20,16, x, y, w, h) && fireball->is_alive) {
            return 1;
        }
        
        node = node->next;
    }
    
    return 0;
}

fireball_t *init_fireball()
{
    fireball_t *fireball = malloc(sizeof(fireball_t));
    fireball->x = 0;
    fireball->y = 0;
    fireball->direction = 1;
    fireball->is_alive = 1;
    fireball->startTime = SDL_GetTicks();
    _loadMedia(fireball);
    fireball->update = _update;

    return fireball;
}
