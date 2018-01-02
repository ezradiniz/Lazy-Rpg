#include <stdlib.h>
#include "SDL2/SDL.h"
#include "util.h"
#include "queue.h"
#include "fireball.h"
#include "mage.h"
#include "world.h"
#include "arrow.h"
#include "archer.h"
#include "collision.h"
#include "bigfireball.h"
#include "bluedragon.h"
#include "mainmenu.h"
#include "particle.h"
#include "portal.h"
#include "shield.h"
#include "ai.h"

int main(int argc, char *argv[])
{
    SDL_Event e;

    int quit = 0;
    int option = 0;

    game_init();
    
    long int startTimeIA = SDL_GetTicks();
    world_t *world = init_world();
    mage_t *mage = init_mage();
    archer_t *archer = init_archer();
    bluedragon_t *bluedragon = init_bluedragon();
    portal_t *portal = init_portal();
    menu_t *menu = init_menu();
    shield_t *shield = init_shield();

    option = menu->update(menu);
    if (option != 0 && option != 2) {
        // start npcs /pcs
        mage->y = mage->h = world->y;
        archer->y = archer->h = 425+13;
        bluedragon->y = bluedragon->h = 335-20;

        queue_t *queue_particle = init_queue(free_particle);
        queue_t *queue_fireball = mage->fireballs;
        queue_t *queue_bigfireball = mage->bigfireballs;
        queue_t *queue_arrow = archer->arrows;
        queue_t *queue_waterblast = bluedragon->waterblasts;
        queue_t *queue_waterblade = bluedragon->waterbs;

        while (!quit) {
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT)
                    quit = 1;
                else if( e.type == SDL_KEYDOWN ) {
                    switch( e.key.keysym.sym ) {
                        case SDLK_RIGHT:
                            mage->speed = 1;
                            mage->direction = 1;
                            break;

                        case SDLK_LEFT:
                            mage->speed = 1;
                            mage->direction = -1;
                            break;

                        case SDLK_SPACE:
                        	
                            if (mage->attack != 1)
                                mage->startTime = SDL_GetTicks();
                            mage->attack = 1;
                            break;

                        case SDLK_UP:
                            if (mage->y-35 == mage->h)
                        	{    
                        		mage->startTime = SDL_GetTicks();
								mage->jumping = 1;
 							}

                            break;
                        case SDLK_z:
                            if (mage->attack != 2)
                                mage->startTime = SDL_GetTicks();
                            mage->attack = 2;

                            break;
                         case SDLK_x:
                            if (!shield->is_alive)
                                shield->startTime = SDL_GetTicks();
                            shield->y = mage->y-15;
                            shield->x = mage->x-43;
                            
                            if (mage->is_alive)
                                shield->is_alive = 1;

                            if (mage->attack != 3)
                                mage->startTime = SDL_GetTicks();
                            mage->attack = 3;

                            break;
                                       }
                }else if (e.type == SDL_KEYUP) {
                    switch (e.key.keysym.sym) {
                        case SDLK_RIGHT:
                            mage->frame = 0;
                            mage->speed = 0;
                            break;

                         case SDLK_LEFT:
                            mage->frame = 0;
                            mage->speed = 0;
                            break;

                         case SDLK_UP:
                            // mage->jumping = 0;
                            break;

                    }
                }
            }
            SDL_SetRenderDrawColor(wRenderer, 0, 0, 0, 0);
            SDL_RenderClear(wRenderer);

            world->update(world);
            mage->update(mage);
            shield->update(shield);
            portal->update(portal);        


            if (world->frame == 0) {
                 if (game_animation_frame(startTimeIA, 3, 800, 4) == 3)
                    archerIA(mage, archer);
                archer->update(archer);

                if (archer->is_alive) {
                    if (hasIntersectionFireball(queue_fireball, archer->x, archer->y, 33, 46)) {
                        //do something ..
                        enqueue(queue_particle, init_particle(archer->x, archer->y));
                        archer->hit = 1;
                    }
                    if (hasIntersectionBigFireball(queue_bigfireball, archer->x, archer->y , 33, 46)) {
                        // do something ...
                        enqueue(queue_particle, init_particle(archer->x, archer->y));
                        archer->hit = 1;
                    }
                }

                if (shield->blocked) {
                    if (hasIntersectionArrow(queue_arrow, shield->x, shield->y, 95, 93)) {
                        // do something ...
                    } 
                } else {
                    if (hasIntersectionArrow(queue_arrow, mage->x, mage->y, 33, 64)) {
                        // do something ...
                        enqueue(queue_particle, init_particle(mage->x+25, mage->y+15));
                    }
                }

                if (!archer->is_alive) {
                    portal->x = archer->x;
                    portal->y = archer->y;
                    portal->is_alive = 1;
                    if (portal->x >= SCREEN_WIDTH-100) {
                        portal->x = 500;
                    }
                    startTimeIA = SDL_GetTicks();
                }

            } else if (world->frame == 1) {
                if (game_animation_frame(startTimeIA, 3, 800, 4) == 3)
                    blueDragonIA(mage, bluedragon);
                
                bluedragon->update(bluedragon);

                if (bluedragon->is_alive) {
                    if (hasIntersectionFireball(queue_fireball, bluedragon->x, bluedragon->y, 33, 46)) {
                        //do something ...
                        enqueue(queue_particle, init_particle(bluedragon->x, bluedragon->y));
                        bluedragon->hit = 1;
                    }
                    if (hasIntersectionBigFireball(queue_bigfireball, bluedragon->x, bluedragon->y , 33, 46)) {
                        // do something ...
                        enqueue(queue_particle, init_particle(bluedragon->x, bluedragon->y));
                        bluedragon->hit = 1;
                    }

                }

                if (shield->blocked) {
                    if (hasIntersectionArrow(queue_waterblast, shield->x, shield->y, 95, 93)) {
                        // do something ...
                    } 
                } else {
                    if (hasIntersectionWaterblast(queue_waterblast, mage->x+25, mage->y+15, 33, 64)) {
                        // do something ...
                        enqueue(queue_particle, init_particle(mage->x+25, mage->y+15));
                    }
                }

                if (shield->blocked) {
                    if (hasIntersectionArrow(queue_waterblade, shield->x, shield->y, 95, 93)) {
                        // do something ...
                    } 
                } else {
                    if (hasIntersectionWaterblade(queue_waterblade, mage->x, mage->y, 33, 64)) {
                        // do something ...
                        enqueue(queue_particle, init_particle(mage->x+25, mage->y+15));
                    }
                }

                

                if (!bluedragon->is_alive) {
                    portal->x = bluedragon->x;
                    portal->y = bluedragon->y+38;
                    portal->is_alive = 1;
                    if (portal->x >= SCREEN_WIDTH-100) {
                        portal->x = 500;
                    }
                }
            }


            if (portal->is_alive) {
                if (hasIntersectionPortal(portal, mage->x, mage->y, 33, 64)) {
                    if (game_animation_frame(mage->startTime, 3, 800, 4) == 3 && world->frame == 0) {
                        portal->is_alive = 0;
                        world->frame += 1;
                        mage->x = 100;
                        mage->direction = 1;
                        mage->y = mage->h = 335;
                    } else if (game_animation_frame(mage->startTime, 3, 800, 4) == 3 && world->frame == 1) {
                        portal->is_alive = 0;
                        world->frame += 1;
                        mage->is_alive = 0;
                    }
                } 
            }

            update_queue_fireball(queue_fireball);
            update_queue_arrow(queue_arrow);
            update_queue_bigfireball(queue_bigfireball);
            update_queue_waterblast(queue_waterblast);
            update_queue_waterblade(queue_waterblade);
            update_queue_particle(queue_particle);

            SDL_Delay(4);
            SDL_RenderPresent(wRenderer);
        }

        free_queue(queue_particle);
        free(queue_particle);
    }

    destroy_portal(portal);
    destroy_world(world);
    destroy_mage(mage);
    destroy_shield(shield);
    destroy_archer(archer);
    destroy_bluedragon(bluedragon);
    destroy_menu(menu);

    game_close();

    return 0;
}
