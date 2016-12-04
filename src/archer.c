#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "archer.h"


static void _archerLoadMedia(archer_t *archer)
{
    archer->texture = game_loadTexture("img/archer.png",255,33,211);

    // walk
//
    archer->walkSpriteClips[0].x = 191;
    archer->walkSpriteClips[0].y = 74;
    archer->walkSpriteClips[0].w = 64;
    archer->walkSpriteClips[0].h = 67;

    archer->walkSpriteClips[1].x = 258;
    archer->walkSpriteClips[1].y = 72;
    archer->walkSpriteClips[1].w = 62;
    archer->walkSpriteClips[1].h = 67;

    archer->walkSpriteClips[2].x = 321;
    archer->walkSpriteClips[2].y = 73;
    archer->walkSpriteClips[2].w = 65;
    archer->walkSpriteClips[2].h = 67;

    archer->walkSpriteClips[3].x = 389;
    archer->walkSpriteClips[3].y = 72;
    archer->walkSpriteClips[3].w = 68;
    archer->walkSpriteClips[3].h = 67;

    archer->walkSpriteClips[4].x = 459;
    archer->walkSpriteClips[4].y = 71;
    archer->walkSpriteClips[4].w = 50;
    archer->walkSpriteClips[4].h = 67;

    archer->walkSpriteClips[5].x = 510;
    archer->walkSpriteClips[5].y = 71;
    archer->walkSpriteClips[5].w = 70;
    archer->walkSpriteClips[5].h = 67;


    //shooting

    archer->shootSpriteClips[0].x = 170;
    archer->shootSpriteClips[0].y = 6;
    archer->shootSpriteClips[0].w = 69;
    archer->shootSpriteClips[0].h = 67;

    archer->shootSpriteClips[1].x = 241;
    archer->shootSpriteClips[1].y = 6;
    archer->shootSpriteClips[1].w = 66;
    archer->shootSpriteClips[1].h = 67;

    archer->shootSpriteClips[2].x = 309;
    archer->shootSpriteClips[2].y = 6;
    archer->shootSpriteClips[2].w = 65;
    archer->shootSpriteClips[2].h = 67;

    archer->shootSpriteClips[3].x = 375;
    archer->shootSpriteClips[3].y = 6;
    archer->shootSpriteClips[3].w = 66;
    archer->shootSpriteClips[3].h = 67;

    archer->shootSpriteClips[4].x = 442;
    archer->shootSpriteClips[4].y = 6;
    archer->shootSpriteClips[4].w = 65;
    archer->shootSpriteClips[4].h = 67;

    archer->shootSpriteClips[5].x = 509;
    archer->shootSpriteClips[5].y = 6;
    archer->shootSpriteClips[5].w = 69;
    archer->shootSpriteClips[5].h = 67;


    //stoped
    archer->stopSpriteClips[0].x = 12;
    archer->stopSpriteClips[0].y = 8;
    archer->stopSpriteClips[0].w = 50;
    archer->stopSpriteClips[0].h = 67;

    archer->stopSpriteClips[1].x = 64;
    archer->stopSpriteClips[1].y = 6;
    archer->stopSpriteClips[1].w = 53;
    archer->stopSpriteClips[1].h = 67;

    archer->stopSpriteClips[2].x = 117;
    archer->stopSpriteClips[2].y = 6;
    archer->stopSpriteClips[2].w = 52;
    archer->stopSpriteClips[2].h = 67;

}

static void _update(archer_t *archer)
{

    if (archer->attack == 1) {
         archer->frame = game_animation_frame(archer->startTime, 12, 1300, SHOOTING_FRAMES);

         game_renderTexture(archer->x,
                        archer->y,
                        69,
                        67,
                        &archer->shootSpriteClips[archer->frame],
                        360,
                        NULL,
                        (archer->direction == 1) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE,
                        archer->texture);
         if (archer->frame != SHOOTING_FRAMES-1) {
             archer->attack = 1;
         }else {
            arrow_t *arrow = init_arrow();
            arrow->x = archer->x + 28;
            arrow->y = archer->y + 17;
            arrow->direction = archer->direction;

            enqueue(archer->arrows, arrow);
            

            archer->attack = 0;
            archer->frame = 0;
            archer->shooting = 0;
         }

    } else if (archer->speed != 0){

        archer->frame = game_animation_frame(archer->startTime, 6, 500, WALK_FRAMES);

        SDL_Rect * current = &archer->walkSpriteClips[archer->frame];

        if (archer->direction == 1) {
             archer->x += archer->speed;
        } else if (archer->direction == -1){
             archer->x -= archer->speed;
        }

        if (archer->jumping == 1 && archer->y > archer->h-35) {
            archer->y -= 1;
            archer->frame = game_animation_frame(archer->startTime, 3, 500 * GRAVITY, STOPPING_FRAMES);
            current = &archer->stopSpriteClips[archer->frame];
        }else if (archer->y < archer->h+35){
            archer->jumping = 0;
            archer->y += 1;
            archer->frame = game_animation_frame(archer->startTime, 3, 500 * GRAVITY, STOPPING_FRAMES);
            current = &archer->stopSpriteClips[archer->frame];
        }

        game_renderTexture(archer->x,
                            archer->y,
                            52,
                            67,
                            current,
                            360,
                            NULL,
                            (archer->direction == 1) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE,
                            archer->texture);

    } else {

        archer->frame = game_animation_frame(archer->startTime, 3, 1500, STOPPING_FRAMES);
        SDL_Rect * current = &archer->stopSpriteClips[archer->frame];

        if (archer->jumping == 1 && archer->y > archer->h-35) {
            archer->y -= 1;
            archer->frame = game_animation_frame(archer->startTime, 3, 500 * GRAVITY, STOPPING_FRAMES);
            current = &archer->stopSpriteClips[archer->frame];
        }else if (archer->y < archer->h+35){
            archer->jumping = 0;
            archer->y += 1;
            archer->frame = game_animation_frame(archer->startTime, 3, 500 * GRAVITY, STOPPING_FRAMES);
            current = &archer->stopSpriteClips[archer->frame];
        }

        game_renderTexture(archer->x,
                        archer->y,
                        52,
                        67,
                        current,
                        360,
                        NULL,
                        (archer->direction == 1) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE,
                        archer->texture);
    }
}

archer_t *init_archer()
{
    archer_t *archer = malloc(sizeof(archer_t));
    archer->frame = 0;
    archer->x = 550;
    archer->y = archer->h = 415;
    archer->jumping = 0;
    archer->startTime = SDL_GetTicks();
    archer->speed = 0;
    archer->direction = -1;
    archer->attack = 0;
    archer->shooting = 0;
    archer->arrows = init_queue(free_arrow);
    archer->update = _update;
    _archerLoadMedia(archer);

    return archer;
}


