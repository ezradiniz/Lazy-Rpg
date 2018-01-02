#ifndef SHILED_H_
#define SHILED_H_

#include "SDL2/SDL.h"

#define SHIELD_FRAMES 6

typedef struct shield shield_t;

struct shield {
	int x, y;
	long int startTime;
	int is_alive;
	int blocked;
	SDL_Texture *texture;
	SDL_Rect spriteClips[SHIELD_FRAMES];
	void (*update)(shield_t *);
};

int hasIntersectionShield(shield_t *shield, int x, int y, int w, int h);
shield_t *init_shield();
void destroy_shield(shield_t *);

#endif
