#include "particle.h"
#include "util.h"

static void _loadMedia(particle_t *particle)
{
	particle->texture = game_loadTexture("img/effect.png");

}

static void _update(particle_t *particle)
{

}

particle_t *init_particle()
{
	particle_t *particle = malloc(sizeof(particle_t));

	particle->x = 0;
	particle->y = 0;
	particle->startTime = SDL_GetTicks();
	particle->update = _update;
	_loadMedia(particle);

	return particle;
}