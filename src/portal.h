#ifndef PORTAL_H_
#define PORTAL_H_

#include "SDL2/SDL.h"

#define PORTAL_FRAMES 32

typedef struct portal portal_t;
struct portal {
	int x, y;
	int w, h;
	int is_alive;
	int startTime;
	SDL_Texture *texture;
	SDL_Rect spriteClips[PORTAL_FRAMES];
	void (*update)(portal_t *);
};

portal_t *init_portal();
void destroy_portal(portal_t *);
int hasIntersectionPortal(portal_t *, int x2, int y2, int w2, int h2);

#endif
