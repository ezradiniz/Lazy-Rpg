#include "portal.h"
#include "util.h"
#include "collision.h"
#include <stdlib.h>

static void _loadMedia(portal_t *portal)
{
	portal->texture = game_loadTexture("img/portal.png", -1, -1, -1);

	portal->spriteClips[0].x = 30;
    portal->spriteClips[0].y = 50;
    portal->spriteClips[0].w = 70;
    portal->spriteClips[0].h = 70;
   
    portal->spriteClips[1].x = 165;
    portal->spriteClips[1].y = 50;
    portal->spriteClips[1].w = 70;
    portal->spriteClips[1].h = 70;
   
    portal->spriteClips[2].x = 295;
    portal->spriteClips[2].y = 50;
    portal->spriteClips[2].w = 70;
    portal->spriteClips[2].h = 70;
   
    portal->spriteClips[3].x = 420;
    portal->spriteClips[3].y = 50;
    portal->spriteClips[3].w = 70;
    portal->spriteClips[3].h = 70;
   
    portal->spriteClips[4].x = 550;
    portal->spriteClips[4].y = 50;
    portal->spriteClips[4].w = 70;
    portal->spriteClips[4].h = 70;
   
    portal->spriteClips[5].x = 670;
    portal->spriteClips[5].y = 50;
    portal->spriteClips[5].w = 70;
    portal->spriteClips[5].h = 70;
   
    portal->spriteClips[6].x = 800;
    portal->spriteClips[6].y = 50;
    portal->spriteClips[6].w = 70;
    portal->spriteClips[6].h = 70;
   
    portal->spriteClips[7].x = 930;
    portal->spriteClips[7].y = 50;
    portal->spriteClips[7].w = 70;
    portal->spriteClips[7].h = 70;
   
    portal->spriteClips[8].x = 30;
    portal->spriteClips[8].y = 180;
    portal->spriteClips[8].w = 70;
    portal->spriteClips[8].h = 70;
   
    portal->spriteClips[9].x = 165;
    portal->spriteClips[9].y = 180;
    portal->spriteClips[9].w = 70;
    portal->spriteClips[9].h = 70;
   
    portal->spriteClips[10].x = 295;
    portal->spriteClips[10].y = 180;
    portal->spriteClips[10].w = 70;
    portal->spriteClips[10].h = 70;
   
    portal->spriteClips[11].x = 420;
    portal->spriteClips[11].y = 180;
    portal->spriteClips[11].w = 70;
    portal->spriteClips[11].h = 70;
   
    portal->spriteClips[12].x = 550;
    portal->spriteClips[12].y = 180;
    portal->spriteClips[12].w = 70;
    portal->spriteClips[12].h = 70;
   
    portal->spriteClips[13].x = 670;
    portal->spriteClips[13].y = 180;
    portal->spriteClips[13].w = 70;
    portal->spriteClips[13].h = 70;
   
    portal->spriteClips[14].x = 800;
    portal->spriteClips[14].y = 180;
    portal->spriteClips[14].w = 70;
    portal->spriteClips[14].h = 70;
   
    portal->spriteClips[15].x = 930;
    portal->spriteClips[15].y = 180;
    portal->spriteClips[15].w = 70;
    portal->spriteClips[15].h = 70;
   
    portal->spriteClips[16].x = 30;
    portal->spriteClips[16].y = 300;
    portal->spriteClips[16].w = 70;
    portal->spriteClips[16].h = 70;
   
    portal->spriteClips[17].x = 165;
    portal->spriteClips[17].y = 300;
    portal->spriteClips[17].w = 70;
    portal->spriteClips[17].h = 70;
   
    portal->spriteClips[18].x = 295;
    portal->spriteClips[18].y = 300;
    portal->spriteClips[18].w = 70;
    portal->spriteClips[18].h = 70;
   
    portal->spriteClips[19].x = 420;
    portal->spriteClips[19].y = 300;
    portal->spriteClips[19].w = 70;
    portal->spriteClips[19].h = 70;
   
    portal->spriteClips[20].x = 550;
    portal->spriteClips[20].y = 300;
    portal->spriteClips[20].w = 70;
    portal->spriteClips[20].h = 70;
   
    portal->spriteClips[21].x = 670;
    portal->spriteClips[21].y = 300;
    portal->spriteClips[21].w = 70;
    portal->spriteClips[21].h = 70;
   
    portal->spriteClips[22].x = 800;
    portal->spriteClips[22].y = 300;
    portal->spriteClips[22].w = 70;
    portal->spriteClips[22].h = 70;
   
    portal->spriteClips[23].x = 930;
    portal->spriteClips[23].y = 300;
    portal->spriteClips[23].w = 70;
    portal->spriteClips[23].h = 70;
   
    portal->spriteClips[24].x = 30;
    portal->spriteClips[24].y = 440;
    portal->spriteClips[24].w = 70;
    portal->spriteClips[24].h = 70;
   
    portal->spriteClips[25].x = 165;
    portal->spriteClips[25].y = 440;
    portal->spriteClips[25].w = 70;
    portal->spriteClips[25].h = 70;
   
    portal->spriteClips[26].x = 295;
    portal->spriteClips[26].y = 440;
    portal->spriteClips[26].w = 70;
    portal->spriteClips[26].h = 70;
   
    portal->spriteClips[27].x = 420;
    portal->spriteClips[27].y = 440;
    portal->spriteClips[27].w = 70;
    portal->spriteClips[27].h = 70;
   
    portal->spriteClips[28].x = 550;
    portal->spriteClips[28].y = 440;
    portal->spriteClips[28].w = 70;
    portal->spriteClips[28].h = 70;
   
    portal->spriteClips[29].x = 670;
    portal->spriteClips[29].y = 440;
    portal->spriteClips[29].w = 70;
    portal->spriteClips[29].h = 70;
   
    portal->spriteClips[30].x = 800;
    portal->spriteClips[30].y = 440;
    portal->spriteClips[30].w = 70;
    portal->spriteClips[30].h = 70;
   
    portal->spriteClips[31].x = 930;
    portal->spriteClips[31].y = 440;
    portal->spriteClips[31].w = 70;
    portal->spriteClips[31].h = 70;
}

static void _update(portal_t *portal)
{
	if (portal->is_alive) {
			int frame = game_animation_frame(portal->startTime, 25, 5000, PORTAL_FRAMES);
			game_renderTexture(portal->x,
			                   portal->y,
			                   70,
			                   70,
			                   &portal->spriteClips[frame],
			                   360,
			                   NULL,
			                   SDL_FLIP_NONE,
			                   portal->texture);
	}
}

void destroy_portal(portal_t *portal)
{
	SDL_DestroyTexture(portal->texture);
	free(portal);
}


int hasIntersectionPortal(portal_t *portal,
						  int x2, int y2, int w2, int h2)
{
	return hasCollision(portal->x, portal->y, portal->w, portal->h, x2, y2, w2, h2);
}

portal_t *init_portal()
{
	portal_t *portal = malloc(sizeof(portal_t));
	portal->x = 0;
	portal->y = 0;
	portal->w = 44;
	portal->h = 26;
	portal->startTime = SDL_GetTicks();
	portal->is_alive = 0;
	_loadMedia(portal);
	portal->update = _update;

	return portal;
}