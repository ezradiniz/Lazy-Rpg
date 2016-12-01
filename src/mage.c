#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "mage.h"


static void _mageLoadMedia(mage_t *mage)
{
    mage->texture = game_loadTexture("img/mage.png");

    // walk

    mage->walkSpriteClips[0].x = 26;
    mage->walkSpriteClips[0].y = 104;
    mage->walkSpriteClips[0].w = 71;
    mage->walkSpriteClips[0].h = 71;

    mage->walkSpriteClips[1].x = 106;
    mage->walkSpriteClips[1].y = 104;
    mage->walkSpriteClips[1].w = 71;
    mage->walkSpriteClips[1].h = 71;

    mage->walkSpriteClips[2].x = 187;
    mage->walkSpriteClips[2].y = 104;
    mage->walkSpriteClips[2].w = 71;
    mage->walkSpriteClips[2].h = 71;

    mage->walkSpriteClips[3].x = 265;
    mage->walkSpriteClips[3].y = 104;
    mage->walkSpriteClips[3].w = 71;
    mage->walkSpriteClips[3].h = 71;

    // jump

    mage->jumpSpriteClips[0].x = 94;
    mage->jumpSpriteClips[0].y = 196;
    mage->jumpSpriteClips[0].w = 71;
    mage->jumpSpriteClips[0].h = 75;

    mage->jumpSpriteClips[1].x = 154;
    mage->jumpSpriteClips[1].y = 190;
    mage->jumpSpriteClips[1].w = 71;
    mage->jumpSpriteClips[1].h = 71;

    mage->jumpSpriteClips[2].x = 227;
    mage->jumpSpriteClips[2].y = 190;
    mage->jumpSpriteClips[2].w = 71;
    mage->jumpSpriteClips[2].h = 71;


    //casting

    mage->castSpriteClips[0].x = 5;
    mage->castSpriteClips[0].y = 551;
    mage->castSpriteClips[0].w = 71;
    mage->castSpriteClips[0].h = 71;

    mage->castSpriteClips[1].x = 72;
    mage->castSpriteClips[1].y = 552;
    mage->castSpriteClips[1].w = 71;
    mage->castSpriteClips[1].h = 71;

    mage->castSpriteClips[2].x = 139;
    mage->castSpriteClips[2].y = 553;
    mage->castSpriteClips[2].w = 71;
    mage->castSpriteClips[2].h = 71;

    mage->castSpriteClips[3].x = 218;
    mage->castSpriteClips[3].y = 554;
    mage->castSpriteClips[3].w = 71;
    mage->castSpriteClips[3].h = 71;

    mage->castSpriteClips[4].x = 299;
    mage->castSpriteClips[4].y = 555;
    mage->castSpriteClips[4].w = 71;
    mage->castSpriteClips[4].h = 71;

    mage->castSpriteClips[5].x = 372;
    mage->castSpriteClips[5].y = 556;
    mage->castSpriteClips[5].w = 71;
    mage->castSpriteClips[5].h = 71;


    //stoped
    mage->stopSpriteClips[0].x = 48;
    mage->stopSpriteClips[0].y = 14;
    mage->stopSpriteClips[0].w = 71;
    mage->stopSpriteClips[0].h = 71;

    mage->stopSpriteClips[1].x = 124;
    mage->stopSpriteClips[1].y = 14;
    mage->stopSpriteClips[1].w = 71;
    mage->stopSpriteClips[1].h = 71;

    mage->stopSpriteClips[2].x = 200;
    mage->stopSpriteClips[2].y = 14;
    mage->stopSpriteClips[2].w = 71;
    mage->stopSpriteClips[2].h = 71;

}

void _update(mage_t *mage)
{

    if (mage->attack == 1) {
         mage->frame = game_animation_frame(mage->startTime, 12, 1300, CASTING_FRAMES);

         game_renderTexture(mage->x,
                        mage->y,
                        71,
                        71,
                        &mage->castSpriteClips[mage->frame],
                        360,
                        NULL,
                        (mage->direction == 1) ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL,
                        mage->texture);
         if (mage->frame != CASTING_FRAMES-1) {
             mage->attack = 1;
         }else {
            int i;
             for (i=0; i<MAX_FIREBALLS; i++) {
                 if (mage->fireballs[i] == NULL) {
                     mage->fireballs[i] = init_fireball();
                     mage->fireballs[i]->x = mage->x + 28;
                     mage->fireballs[i]->y = mage->y + 17;
                     mage->fireballs[i]->direction = mage->direction;
                     break;
                }
            }
             mage->attack = 0;
             mage->frame = 0;
             mage->casting = 0;
         }

    } else if (mage->speed != 0){

        mage->frame = game_animation_frame(mage->startTime, 4, 500, WALKING_FRAMES);

        SDL_Rect * current = &mage->walkSpriteClips[mage->frame];

        if (mage->direction == 1) {
             mage->x += mage->speed;
        } else if (mage->direction == -1){
             mage->x -= mage->speed;
        }

        if (mage->jumping == 1 && mage->y > mage->h-35) {
            mage->y -= 1;
            mage->frame = game_animation_frame(mage->startTime, 4, 500 * GRAVITY, JUMPING_FRAMES);
            current = &mage->jumpSpriteClips[mage->frame];
        }else if (mage->y < mage->h+35){
            mage->jumping = 0;
            mage->y += 1;
            mage->frame = game_animation_frame(mage->startTime, 4, 500 * GRAVITY, JUMPING_FRAMES);
            current = &mage->jumpSpriteClips[mage->frame];
        }

        game_renderTexture(mage->x,
                            mage->y,
                            71,
                            71,
                            current,
                            360,
                            NULL,
                            (mage->direction == 1) ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL,
                            mage->texture);

    } else {

        mage->frame = game_animation_frame(mage->startTime, 5, 800, STOPPING_FRAMES);
        SDL_Rect * current = &mage->stopSpriteClips[mage->frame];

        if (mage->jumping == 1 && mage->y > mage->h-35) {
            mage->y -= 1;
            mage->frame = game_animation_frame(mage->startTime, 4, 500 * GRAVITY, JUMPING_FRAMES);
            current = &mage->jumpSpriteClips[mage->frame];
        }else if (mage->y < mage->h+35){
            mage->jumping = 0;
            mage->y += 1;
            mage->frame = game_animation_frame(mage->startTime, 4, 500 * GRAVITY, JUMPING_FRAMES);
            current = &mage->jumpSpriteClips[mage->frame];
        }

        game_renderTexture(mage->x,
                        mage->y,
                        71,
                        71,
                        current,
                        360,
                        NULL,
                        (mage->direction == 1) ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL,
                        mage->texture);
    }
}

mage_t *init_mage()
{
    mage_t *mage = malloc(sizeof(mage_t));
    mage->frame = 0;
    mage->x = 200;
    mage->y = mage->h = 420;
    mage->jumping = 0;
    mage->startTime = SDL_GetTicks();
    mage->speed = 0;
    mage->direction = 1;
    mage->attack = 0;
    mage->casting = 0;
    mage->fireballs = calloc(MAX_FIREBALLS, sizeof(fireball_t*));
    mage->update = _update;
    _mageLoadMedia(mage);

    return mage;
}


