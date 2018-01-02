#ifndef PARTICLE_H
#define PARTICLE_H

#include "queue.h"
#include "SDL2/SDL.h"

#define PARTICLE_FRAMES 1

typedef struct particle particle_t;
struct particle {
	int x, y;
	int t;
	int dx, dy;
	long int startTime;
	SDL_Rect spriteClips[PARTICLE_FRAMES];
	SDL_Texture *texture;
	void (*update)(particle_t *);
};

void update_queue_particle(queue_t *queue);
void free_particle(void *data);
particle_t *init_particle(int x, int y);

#endif
