#include <stdlib.h>
#include <SDL2/SDL.h>
#include "util.h"
#include "fireball.h"
#include "mage.h"
#include "world.h"
#include "arrow.h"
#include "archer.h"

void update_queue_arrow(queue_t *queue);
void update_queue_fireball(queue_t *queue);

int main(int argc, char *argv[])
{
    SDL_Event e;

    int quit = 0;

    game_init();
    
    world_t *world = init_world();
    mage_t *mage = init_mage();
    archer_t *archer = init_archer();

    queue_t *queue_fireball = mage->fireballs;
    queue_t *queue_arrow = archer->arrows;


    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT)
                quit = 1;
            else if( e.type == SDL_KEYDOWN ) {
                switch( e.key.keysym.sym ) {
                    case SDLK_RIGHT:
                        archer->speed = 1;
                        archer->direction = -1;

                        mage->speed = 1;
                        mage->direction = 1;
                        break;
                    case SDLK_LEFT:
                        archer->speed = 1;
                        archer->direction = 1;

                        mage->speed = 1;
                        mage->direction = -1;
                        break;
                    case SDLK_SPACE:
                        if (archer->attack != 1)
                            archer->startTime = SDL_GetTicks();
                        archer->attack = 1;

                        if (mage->attack != 1)
                            mage->startTime = SDL_GetTicks();
                        mage->attack = 1;
                        break;
                    case SDLK_UP:
                        mage->startTime = SDL_GetTicks();
                        mage->jumping = 1;
                        break;
                                   }
            }else if (e.type == SDL_KEYUP) {
                switch (e.key.keysym.sym) {
                    case SDLK_RIGHT:
                        archer->speed = 0;
                        archer->frame = 0;

                        mage->frame = 0;
                        mage->speed = 0;
                        break;
                     case SDLK_LEFT:
                        archer->speed = 0;
                        archer->frame = 0;

                        mage->frame = 0;
                        mage->speed = 0;
                        break;
                     case SDLK_UP:
                        // mage->startTime = SDL_GetTicks();
                        // mage->jumping = 1;
                        break;

                }
            }
        }
        SDL_SetRenderDrawColor(wRenderer, 0, 0, 0, 0);
        SDL_RenderClear(wRenderer);

        world->update(world);

        mage->update(mage);
        archer->update(archer);

        update_queue_fireball(queue_fireball);
        update_queue_arrow(queue_arrow);

        SDL_Delay(4);
        SDL_RenderPresent(wRenderer);
    }

    game_close();

    return 0;
}

void update_queue_fireball(queue_t *queue)
{
    fireball_t *fireball;
    node_t *node = queue->head;
    while (node != NULL) {
        fireball = node->data;
        fireball->update(fireball);
        node = node->next;
    }
}

void update_queue_arrow(queue_t *queue)
{
    arrow_t *arrow;
    node_t *node = queue->head;
    while (node != NULL) {
        arrow = node->data;
        arrow->update(arrow);
        node = node->next;
    }
}