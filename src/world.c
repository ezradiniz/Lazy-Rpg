#include "world.h"
#include "util.h"
#include <stdlib.h>

static void _loadMedia(world_t *world)
{
    world->texture[0] = game_loadTexture("img/map1.png", -1, -1, -1); //335
    world->texture[1] = game_loadTexture("img/map2.png", -1, -1, -1); //425
    world->texture[2] = game_loadTexture("img/end.png", -1, -1, -1); //425
}

static void _update(world_t *world)
{
    SDL_RenderCopy(wRenderer, world->texture[world->frame], NULL, NULL);
}

void destroy_world(world_t *world)
{
	SDL_DestroyTexture(world->texture[0]);
	SDL_DestroyTexture(world->texture[1]);
	SDL_DestroyTexture(world->texture[2]);
	free(world);
}

world_t *init_world()
{
    world_t *world = malloc(sizeof(world_t));

    world->y = 425;
    world->frame = 0;
    world->update = _update;
    _loadMedia(world);

    return world;

}
