#include "particle.h"
#include "util.h"
#include <time.h>

static void _loadMedia(particle_t *particle)
{
	particle->texture = game_loadTexture("img/particle.gif", -1, -1, -1);

	particle->spriteClips[0].x = 0;
	particle->spriteClips[0].y = 0;
	particle->spriteClips[0].w = 15;
	particle->spriteClips[0].h = 15;
}

static void _update(particle_t *particle)
{
	particle->x += particle->dx;
	particle->y += particle->dy;
	game_renderTexture(particle->x,
						   particle->y,
						   15,
						   15,
						   &particle->spriteClips[0],
						   306,
						   NULL,
						   SDL_FLIP_HORIZONTAL,
						   particle->texture);
}

void update_queue_particle(queue_t *queue)
{
	node_t *node = queue->head;
	while (node != NULL) {
		particle_t *p = node->data;
		p->update(p);
		node = node->next;
	}

	if (queue->length >= 50)
        free_queue(queue);
}

void free_particle(void *data)
{	
	node_t *node = data;
	particle_t *particle = node->data;
	SDL_DestroyTexture(particle->texture);
	free(particle);
}

particle_t *init_particle(int x, int y)
{
	particle_t *particle = malloc(sizeof(particle_t));

	particle->x = x;
	particle->y = y;
	particle->startTime = SDL_GetTicks();
	particle->dx = (((float) rand() / RAND_MAX) - 0.5f) * 15;
	particle->dy = (((float) rand() / RAND_MAX) - 0.5f) * 15;
	particle->update = _update;
	_loadMedia(particle);

	return particle;
}
