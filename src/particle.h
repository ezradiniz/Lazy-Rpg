#ifndef PARTICLE_H
#define PARTICLE_H


#include <SDL2/SDL.h>

typedef struct particle particle_t;
struct particle {
	int x;
	int y;
	long int startTime;
	SDL_Texture *texture;
	void (*update)(particle_t *);
};

particle_t *init_particle();

#endif