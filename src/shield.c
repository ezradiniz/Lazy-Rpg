#include "shield.h"
#include "util.h"
#include "collision.h"
#include <stdlib.h>

static void _loadMedia(shield_t *shield)
{
	shield->texture = game_loadTexture("img/shield.png", 86, 136, 169);

	shield->spriteClips[0].x = 39;
	shield->spriteClips[0].y = 36;
	shield->spriteClips[0].w = 119;
	shield->spriteClips[0].h = 112;

	shield->spriteClips[1].x = 166;
	shield->spriteClips[1].y = 38;
	shield->spriteClips[1].w = 119;
	shield->spriteClips[1].h = 112;

	shield->spriteClips[2].x = 330;
	shield->spriteClips[2].y = 32;
	shield->spriteClips[2].w = 119;
	shield->spriteClips[2].h = 112;

	shield->spriteClips[3].x = 472;
	shield->spriteClips[3].y = 33;
	shield->spriteClips[3].w = 119;
	shield->spriteClips[3].h = 112;

	shield->spriteClips[4].x = 610;
	shield->spriteClips[4].y = 34;
	shield->spriteClips[4].w = 119;
	shield->spriteClips[4].h = 112;

	shield->spriteClips[5].x = 757;
	shield->spriteClips[5].y = 31;
	shield->spriteClips[5].w = 119;
	shield->spriteClips[5].h = 112;

}

static void _update(shield_t *shield)
{
	if (shield->is_alive) {
			int frame = game_animation_frame(shield->startTime, SHIELD_FRAMES-1, 800, SHIELD_FRAMES);
			shield->blocked = 1;
			if (frame == SHIELD_FRAMES-1) {
				shield->blocked = 0;
				shield->is_alive = 0;
			}
			game_renderTexture(shield->x,
			                   shield->y,
			                   153,
			                   107,
			                   &shield->spriteClips[frame],
			                   360,
			                   NULL,
			                   SDL_FLIP_NONE,
			                   shield->texture);
	}
}

int hasIntersectionShield(shield_t *shield, int x, int y, int w, int h)
{
	return hasCollision(shield->x, shield->y, 95, 93, x, y, w, h);
}

void destroy_shield(shield_t *shield)
{
	SDL_DestroyTexture(shield->texture);
	free(shield);
}

shield_t *init_shield()
{
	shield_t *shield = malloc(sizeof(shield_t));
	shield->x = 0;
	shield->y = 0;
	shield->blocked = 0;
	shield->is_alive = 0;
	_loadMedia(shield);
	shield->update = _update;

	return shield;
}