#include "world.h"
#include "util.h"
#include <stdlib.h>

static void _loadMedia(world_t *world)
{
    world->texture = game_loadTexture("img/background.png");
}

static void _update(world_t *world)
{
    SDL_RenderCopy(wRenderer, world->texture, NULL, NULL);
}

world_t *init_world()
{
    world_t *world = malloc(sizeof(world_t));

    world->x = 0;
    world->y = 0;
    _loadMedia(world);
    world->update = _update;

    return world;

}
