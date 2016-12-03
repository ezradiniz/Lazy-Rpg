#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "itachi.h"


static void _itachiLoadMedia(itachi_t *itachi)
{
    itachi->texture = game_loadTexture("img/itachi.png", 0, 64, 128);

    // walk

    itachi->walkSpriteClips[0].x = 4;
    itachi->walkSpriteClips[0].y = 130;
    itachi->walkSpriteClips[0].w = 66;
    itachi->walkSpriteClips[0].h = 63;

    itachi->walkSpriteClips[1].x = 69;
    itachi->walkSpriteClips[1].y = 128;
    itachi->walkSpriteClips[1].w = 64;
    itachi->walkSpriteClips[1].h = 72;

    itachi->walkSpriteClips[2].x = 134;
    itachi->walkSpriteClips[2].y = 130;
    itachi->walkSpriteClips[2].w = 66;
    itachi->walkSpriteClips[2].h = 67;

    itachi->walkSpriteClips[3].x = 200;
    itachi->walkSpriteClips[3].y = 129;
    itachi->walkSpriteClips[3].w = 64;
    itachi->walkSpriteClips[3].h = 66;
    
    itachi->walkSpriteClips[4].x = 265;
    itachi->walkSpriteClips[4].y = 127;
    itachi->walkSpriteClips[4].w = 68;
    itachi->walkSpriteClips[4].h = 71;
    
    itachi->walkSpriteClips[5].x = 333;
    itachi->walkSpriteClips[5].y = 123;
    itachi->walkSpriteClips[5].w = 67;
    itachi->walkSpriteClips[5].h = 72;


    // jump

    itachi->jumpSpriteClips[0].x = 6;
    itachi->jumpSpriteClips[0].y = 362;
    itachi->jumpSpriteClips[0].w = 50;
    itachi->jumpSpriteClips[0].h = 59;

    itachi->jumpSpriteClips[1].x = 55;
    itachi->jumpSpriteClips[1].y = 337;
    itachi->jumpSpriteClips[1].w = 50;
    itachi->jumpSpriteClips[1].h = 84;

    itachi->jumpSpriteClips[2].x = 103;
    itachi->jumpSpriteClips[2].y = 340;
    itachi->jumpSpriteClips[2].w = 62;
    itachi->jumpSpriteClips[2].h = 83;


    //shuriken

    itachi->shurikenSpriteClips[0].x = 5;
    itachi->shurikenSpriteClips[0].y = 1797;
    itachi->shurikenSpriteClips[0].w = 41;
    itachi->shurikenSpriteClips[0].h = 93;

    itachi->shurikenSpriteClips[1].x = 46;
    itachi->shurikenSpriteClips[1].y = 1796;
    itachi->shurikenSpriteClips[1].w = 36;
    itachi->shurikenSpriteClips[1].h = 89;

    itachi->shurikenSpriteClips[2].x = 81;
    itachi->shurikenSpriteClips[2].y = 1798;
    itachi->shurikenSpriteClips[2].w = 44;
    itachi->shurikenSpriteClips[2].h = 86;

    itachi->shurikenSpriteClips[3].x = 126;
    itachi->shurikenSpriteClips[3].y = 1796;
    itachi->shurikenSpriteClips[3].w = 50;
    itachi->shurikenSpriteClips[3].h = 89;

    itachi->shurikenSpriteClips[4].x = 179;
    itachi->shurikenSpriteClips[4].y = 1804;
    itachi->shurikenSpriteClips[4].w = 49;
    itachi->shurikenSpriteClips[4].h = 83;

    itachi->shurikenSpriteClips[5].x = 228;
    itachi->shurikenSpriteClips[5].y = 1802;
    itachi->shurikenSpriteClips[5].w = 61;
    itachi->shurikenSpriteClips[5].h = 83;
    
    itachi->shurikenSpriteClips[6].x = 289;
    itachi->shurikenSpriteClips[6].y = 1802;
    itachi->shurikenSpriteClips[6].w = 59;
    itachi->shurikenSpriteClips[6].h = 84;
    
    //katon

    itachi->katonSpriteClips[0].x = 6;
    itachi->katonSpriteClips[0].y = 2341;
    itachi->katonSpriteClips[0].w = 40;
    itachi->katonSpriteClips[0].h = 85;

    itachi->katonSpriteClips[1].x = 48;
    itachi->katonSpriteClips[1].y = 2335;
    itachi->katonSpriteClips[1].w = 33;
    itachi->katonSpriteClips[1].h = 93;

    itachi->katonSpriteClips[2].x = 80;
    itachi->katonSpriteClips[2].y = 2339;
    itachi->katonSpriteClips[2].w = 47;
    itachi->katonSpriteClips[2].h = 88;

    itachi->katonSpriteClips[3].x = 128;
    itachi->katonSpriteClips[3].y = 2342;
    itachi->katonSpriteClips[3].w = 41;
    itachi->katonSpriteClips[3].h = 82;

    itachi->katonSpriteClips[4].x = 168;
    itachi->katonSpriteClips[4].y = 2347;
    itachi->katonSpriteClips[4].w = 65;
    itachi->katonSpriteClips[4].h = 78;

    itachi->katonSpriteClips[5].x = 234;
    itachi->katonSpriteClips[5].y = 2349;
    itachi->katonSpriteClips[5].w = 65;
    itachi->katonSpriteClips[5].h = 77;
    
    itachi->katonSpriteClips[6].x = 299;
    itachi->katonSpriteClips[6].y = 2339;
    itachi->katonSpriteClips[6].w = 49;
    itachi->katonSpriteClips[6].h = 87;


    //stoped
    itachi->stopSpriteClips[0].x = 3;
    itachi->stopSpriteClips[0].y = 19;
    itachi->stopSpriteClips[0].w = 40;
    itachi->stopSpriteClips[0].h = 89;

    itachi->stopSpriteClips[1].x = 42;
    itachi->stopSpriteClips[1].y = 17;
    itachi->stopSpriteClips[1].w = 41;
    itachi->stopSpriteClips[1].h = 95;

    itachi->stopSpriteClips[2].x = 81;
    itachi->stopSpriteClips[2].y = 14;
    itachi->stopSpriteClips[2].w = 41;
    itachi->stopSpriteClips[2].h = 97;

    itachi->stopSpriteClips[3].x = 122;
    itachi->stopSpriteClips[3].y = 15;
    itachi->stopSpriteClips[3].w = 41;
    itachi->stopSpriteClips[3].h = 93;
    
    itachi->stopSpriteClips[4].x = 162;
    itachi->stopSpriteClips[4].y = 15;
    itachi->stopSpriteClips[4].w = 39;
    itachi->stopSpriteClips[4].h = 94;
    
    itachi->stopSpriteClips[5].x = 201;
    itachi->stopSpriteClips[5].y = 11;
    itachi->stopSpriteClips[5].w = 41;
    itachi->stopSpriteClips[5].h = 99;
    
    itachi->stopSpriteClips[6].x = 239;
    itachi->stopSpriteClips[6].y = 16;
    itachi->stopSpriteClips[6].w = 45;
    itachi->stopSpriteClips[6].h = 92;

}

static void _update(itachi_t *itachi)
{

    if (itachi->attack == 1) {
         itachi->frame = game_animation_frame(itachi->startTime, 12, 1300, SHURIKEN_FRAMES);

         game_renderTexture(itachi->x,
                        itachi->y,
                        41,
                        93,
                        &itachi->shurikenSpriteClips[itachi->frame],
                        360,
                        NULL,
                        (itachi->direction == 1) ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL,
                        itachi->texture);
         if (itachi->frame != SHURIKEN_FRAMES-1) {
             itachi->attack = 1;
         }else {
            shuriken_t *shuriken = init_shuriken();
            shuriken->x = itachi->x + 28;
            shuriken->y = itachi->y + 17;
            shuriken->direction = itachi->direction;

            enqueue(itachi->shurikens, shuriken);

            itachi->attack = 0;
            itachi->frame = 0;
            itachi->casting = 0;
         }
		//work in progress (attack 2)
    } else if(itachi->attack == 2){
    	
    	 itachi->frame = game_animation_frame(itachi->startTime, 12, 1300, KATON_FRAMES);

         game_renderTexture(itachi->x,
                        itachi->y,
                        40,
                        85,
                        &itachi->katonSpriteClips[itachi->frame],
                        360,
                        NULL,
                        (itachi->direction == 1) ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL,
                        itachi->texture);
         if (itachi->frame != KATON_FRAMES-1) {
             itachi->attack = 2;
         }else {
            katon_t *katon = init_katon();
            katon->x = itachi->x + -20;
            katon->y = itachi->y + 0;
            katon->direction = itachi->direction;

            enqueue(itachi->katons, katon);

            itachi->attack = 0;
            itachi->frame = 0;
            itachi->casting = 0;
         }
    	
    	
	} else if (itachi->speed != 0){

        itachi->frame = game_animation_frame(itachi->startTime, 4, 500, WALKING_FRAMES);

        SDL_Rect * current = &itachi->walkSpriteClips[itachi->frame];

        if (itachi->direction == 1) {
             itachi->x += itachi->speed;
        } else if (itachi->direction == -1){
             itachi->x -= itachi->speed;
        }

        if (itachi->jumping == 1 && itachi->y > itachi->h-35) {
            itachi->y -= 1;
            itachi->frame = game_animation_frame(itachi->startTime, 4, 500 * GRAVITY, JUMPING_FRAMES);
            current = &itachi->jumpSpriteClips[itachi->frame];
        }else if (itachi->y < itachi->h+35){
            itachi->jumping = 0;
            itachi->y += 1;
            itachi->frame = game_animation_frame(itachi->startTime, 4, 500 * GRAVITY, JUMPING_FRAMES);
            current = &itachi->jumpSpriteClips[itachi->frame];
        }

        game_renderTexture(itachi->x,
                            itachi->y,
                            66,
                            63,
                            current,
                            360,
                            NULL,
                            (itachi->direction == 1) ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL,
                            itachi->texture);

    } else {

        itachi->frame = game_animation_frame(itachi->startTime, 3, 1500, STOPPING_FRAMES);
        SDL_Rect * current = &itachi->stopSpriteClips[itachi->frame];

        if (itachi->jumping == 1 && itachi->y > itachi->h-35) {
            itachi->y -= 1;
            itachi->frame = game_animation_frame(itachi->startTime, 4, 500 * GRAVITY, JUMPING_FRAMES);
            current = &itachi->jumpSpriteClips[itachi->frame];
        }else if (itachi->y < itachi->h+35){
            itachi->jumping = 0;
            itachi->y += 1;
            itachi->frame = game_animation_frame(itachi->startTime, 4, 500 * GRAVITY, JUMPING_FRAMES);
            current = &itachi->jumpSpriteClips[itachi->frame];
        }

        game_renderTexture(itachi->x,
                        itachi->y,
                        66,
                        63,
                        current,
                        360,
                        NULL,
                        (itachi->direction == 1) ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL,
                        itachi->texture);
    }
}

itachi_t *init_itachi()
{
    itachi_t *itachi = malloc(sizeof(itachi_t));
    itachi->frame = 0;
    itachi->x = 500;
    itachi->y = itachi->h = 390;
    itachi->jumping = 0;
    itachi->startTime = SDL_GetTicks();
    itachi->speed = 0;
    itachi->direction = -1;
    itachi->attack = 0;
    itachi->casting = 0;
    itachi->katons = init_queue(free_katon);
    itachi->shurikens = init_queue(free_shuriken);
    itachi->update = _update;
    _itachiLoadMedia(itachi);

    return itachi;
}


