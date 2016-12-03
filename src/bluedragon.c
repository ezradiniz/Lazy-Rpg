#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "bluedragon.h"


static void _bluedragonLoadMedia(bluedragon_t *bluedragon)
{
    bluedragon->texture = game_loadTexture("img/bluedragon.png", 0, 0, 0);

    // walk

    bluedragon->walkSpriteClips[0].x = 16;
    bluedragon->walkSpriteClips[0].y = 756;
    bluedragon->walkSpriteClips[0].w = 129;
    bluedragon->walkSpriteClips[0].h = 96;

    bluedragon->walkSpriteClips[1].x = 144;
    bluedragon->walkSpriteClips[1].y = 751;
    bluedragon->walkSpriteClips[1].w = 127;
    bluedragon->walkSpriteClips[1].h = 98;

    bluedragon->walkSpriteClips[2].x = 270;
    bluedragon->walkSpriteClips[2].y = 752;
    bluedragon->walkSpriteClips[2].w = 131;
    bluedragon->walkSpriteClips[2].h = 94;

    bluedragon->walkSpriteClips[3].x = 144;
    bluedragon->walkSpriteClips[3].y = 751;
    bluedragon->walkSpriteClips[3].w = 127;
    bluedragon->walkSpriteClips[3].h = 98;

    // jump

    bluedragon->jumpSpriteClips[0].x = 17;
    bluedragon->jumpSpriteClips[0].y = 854;
    bluedragon->jumpSpriteClips[0].w = 157;
    bluedragon->jumpSpriteClips[0].h = 90;

    bluedragon->jumpSpriteClips[1].x = 173;
    bluedragon->jumpSpriteClips[1].y = 853;
    bluedragon->jumpSpriteClips[1].w = 161;
    bluedragon->jumpSpriteClips[1].h = 94;


    //casting

    bluedragon->castSpriteClips[0].x = 43;
    bluedragon->castSpriteClips[0].y = 140;
    bluedragon->castSpriteClips[0].w = 116;
    bluedragon->castSpriteClips[0].h = 96;

    bluedragon->castSpriteClips[1].x = 159;
    bluedragon->castSpriteClips[1].y = 140;
    bluedragon->castSpriteClips[1].w = 105;
    bluedragon->castSpriteClips[1].h = 94;

    bluedragon->castSpriteClips[2].x = 263;
    bluedragon->castSpriteClips[2].y = 139;
    bluedragon->castSpriteClips[2].w = 116;
    bluedragon->castSpriteClips[2].h = 94;

    bluedragon->castSpriteClips[3].x = 379;
    bluedragon->castSpriteClips[3].y = 138;
    bluedragon->castSpriteClips[3].w = 113;
    bluedragon->castSpriteClips[3].h = 96;



    //stoped
    bluedragon->stopSpriteClips[0].x = 2;
    bluedragon->stopSpriteClips[0].y = 41;
    bluedragon->stopSpriteClips[0].w = 95;
    bluedragon->stopSpriteClips[0].h = 97;

    bluedragon->stopSpriteClips[1].x = 96;
    bluedragon->stopSpriteClips[1].y = 39;
    bluedragon->stopSpriteClips[1].w = 96;
    bluedragon->stopSpriteClips[1].h = 100;

    bluedragon->stopSpriteClips[2].x = 192;
    bluedragon->stopSpriteClips[2].y = 35;
    bluedragon->stopSpriteClips[2].w = 94;
    bluedragon->stopSpriteClips[2].h = 102;
    
    bluedragon->stopSpriteClips[3].x = 286;
    bluedragon->stopSpriteClips[3].y = 33;
    bluedragon->stopSpriteClips[3].w = 94;
    bluedragon->stopSpriteClips[3].h = 102;
    
    //special
    /*
    bluedragon->specialSpriteClips[0].x = 4;
    bluedragon->specialSpriteClips[0].y = 622;
    bluedragon->specialSpriteClips[0].w = 101;
    bluedragon->specialSpriteClips[0].h = 114;
    
    bluedragon->specialSpriteClips[1].x = 3;
    bluedragon->specialSpriteClips[1].y = 304;
    bluedragon->specialSpriteClips[1].w = 104;
    bluedragon->specialSpriteClips[1].h = 110;
    
    bluedragon->specialSpriteClips[2].x = 106;
    bluedragon->specialSpriteClips[2].y = 302;
    bluedragon->specialSpriteClips[2].w = 104;
    bluedragon->specialSpriteClips[2].h = 110;
	
    bluedragon->specialSpriteClips[3].x = 104;
    bluedragon->specialSpriteClips[3].y = 632;
    bluedragon->specialSpriteClips[3].w = 124;
    bluedragon->specialSpriteClips[3].h = 107;
    */
	
}

static void _update(bluedragon_t *bluedragon)
{

    if (bluedragon->attack == 1) {
         bluedragon->frame = game_animation_frame(bluedragon->startTime, 12, 1300, CASTING_FRAMES);

         game_renderTexture(bluedragon->x,
                        bluedragon->y,
                        116,
                        96,
                        &bluedragon->castSpriteClips[bluedragon->frame],
                        360,
                        NULL,
                        (bluedragon->direction == 1) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE,
                        bluedragon->texture);
         if (bluedragon->frame != CASTING_FRAMES-1) {
             bluedragon->attack = 1;
         }else {
            waterb_t *waterb = init_waterb();
            waterb->x = bluedragon->x + 0;
            waterb->y = bluedragon->y + 17;
            waterb->direction = bluedragon->direction;

            enqueue(bluedragon->waterbs, waterb);

            bluedragon->attack = 0;
            bluedragon->frame = 0;
            bluedragon->casting = 0;
         }

    } else if(bluedragon->attack == 2){
    	
    	 bluedragon->frame = game_animation_frame(bluedragon->startTime, 12, 1300, CASTING_FRAMES);

         game_renderTexture(bluedragon->x,
                        bluedragon->y,
                        101,
                        114,
                        &bluedragon->castSpriteClips[bluedragon->frame],
                        360,
                        NULL,
                        (bluedragon->direction == 1) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE,
                        bluedragon->texture);
         if (bluedragon->frame != CASTING_FRAMES-1) {
             bluedragon->attack = 2;
         }else {
            waterblast_t *waterblast = init_waterblast();
            waterblast->x = bluedragon->x + 28;
            waterblast->y = bluedragon->y + 14;
            waterblast->direction = bluedragon->direction;

            enqueue(bluedragon->waterblasts, waterblast);

            bluedragon->attack = 0;
            bluedragon->frame = 0;
            bluedragon->casting = 0;
         }
    	
    	
	} else if (bluedragon->speed != 0){

        bluedragon->frame = game_animation_frame(bluedragon->startTime, 4, 500, WALKING_FRAMES);

        SDL_Rect * current = &bluedragon->walkSpriteClips[bluedragon->frame];

        if (bluedragon->direction == 1) {
             bluedragon->x += bluedragon->speed;
        } else if (bluedragon->direction == -1){
             bluedragon->x -= bluedragon->speed;
        }

        if (bluedragon->jumping == 1 && bluedragon->y > bluedragon->h-35) {
            bluedragon->y -= 1;
            bluedragon->frame = game_animation_frame(bluedragon->startTime, 4, 500 * GRAVITY, JUMPING_FRAMES);
            current = &bluedragon->jumpSpriteClips[bluedragon->frame];
        }else if (bluedragon->y < bluedragon->h+35){
            bluedragon->jumping = 0;
            bluedragon->y += 1;
            bluedragon->frame = game_animation_frame(bluedragon->startTime, 4, 500 * GRAVITY, JUMPING_FRAMES);
            current = &bluedragon->jumpSpriteClips[bluedragon->frame];
        }

        game_renderTexture(bluedragon->x,
                            bluedragon->y,
                            129,
                            96,
                            current,
                            360,
                            NULL,
                            (bluedragon->direction == 1) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE,
                            bluedragon->texture);

    } else {

        bluedragon->frame = game_animation_frame(bluedragon->startTime, 3, 1500, STOPPING_FRAMES);
        SDL_Rect * current = &bluedragon->stopSpriteClips[bluedragon->frame];

        if (bluedragon->jumping == 1 && bluedragon->y > bluedragon->h-35) {
            bluedragon->y -= 1;
            bluedragon->frame = game_animation_frame(bluedragon->startTime, 4, 500 * GRAVITY, JUMPING_FRAMES);
            current = &bluedragon->jumpSpriteClips[bluedragon->frame];
        }else if (bluedragon->y < bluedragon->h+35){
            bluedragon->jumping = 0;
            bluedragon->y += 1;
            bluedragon->frame = game_animation_frame(bluedragon->startTime, 4, 500 * GRAVITY, JUMPING_FRAMES);
            current = &bluedragon->jumpSpriteClips[bluedragon->frame];
        }

        game_renderTexture(bluedragon->x,
                        bluedragon->y,
                        157,
                        90,
                        current,
                        360,
                        NULL,
                        (bluedragon->direction == 1) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE,
                        bluedragon->texture);
    }
}

bluedragon_t *init_bluedragon()
{
    bluedragon_t *bluedragon = malloc(sizeof(bluedragon_t));
    bluedragon->frame = 0;
    bluedragon->x = 300;
    bluedragon->y = bluedragon->h = 380;
    bluedragon->jumping = 0;
    bluedragon->startTime = SDL_GetTicks();
    bluedragon->speed = 0;
    bluedragon->direction = -1;
    bluedragon->attack = 0;
    bluedragon->casting = 0;
    bluedragon->waterbs = init_queue(free_waterb);
    bluedragon->waterblasts = init_queue(free_waterblast);
    bluedragon->update = _update;
    _bluedragonLoadMedia(bluedragon);

    return bluedragon;
}


