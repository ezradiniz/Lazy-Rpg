#include <stdlib.h>
#include "SDL2/SDL.h"
#include "util.h"
#include "fireball.h"
#include "bigfireball.h"
#include "mage.h"
#include "arrow.h"
#include "archer.h"
#include "world.h"
#include "waterblade.h"
#include "bluedragon.h"
#include "waterblast.h"
#include "katon.h"
#include "shuriken.h"
#include "itachi.h"
#include "mainmenu.h"

void update_queue_fireball(queue_t *queue);
void update_queue_arrow(queue_t *queue);
void update_queue_waterb(queue_t *queue);
void update_queue_waterblast(queue_t *queue);
void update_queue_bigfireball(queue_t *queue);
void update_queue_shuriken(queue_t *queue);
void update_queue_katon(queue_t *queue);

int main(int argc, char *argv[])
{
    SDL_Event e;

    int quit = 0,menu_f = 0;
	
    game_init();

    world_t *world = init_world();
    mage_t *mage = init_mage();
    queue_t *queue_fireball = mage->fireballs;
    queue_t *queue_bigfireball = mage->bigfireballs;
    archer_t *archer = init_archer();
    queue_t *queue_arrow = archer->arrows;
    bluedragon_t *bluedragon = init_bluedragon();
    queue_t *queue_waterb = bluedragon->waterbs;
    queue_t *queue_waterblast = bluedragon->waterblasts;
    itachi_t *itachi = init_itachi();
    queue_t *queue_shuriken = itachi->shurikens;
    queue_t *queue_katon = itachi->katons;

	menu_t *menu = init_menu();
if(menu->update(menu) == 1){ 
		while (!quit) {		
        	while (SDL_PollEvent(&e) != 0) {
        			if (e.type == SDL_QUIT){
	               		 quit = 1;
	            		}else if( e.type == SDL_KEYDOWN ) {
	               	 		switch( e.key.keysym.sym ) {
		                    	case SDLK_RIGHT:
		                    	mage->speed = 1;
		                        mage->direction = 1;
		                        
		                        archer->speed = 1;
		                        archer->direction = 1;
		                        
		                        bluedragon->speed = 1;
		                        bluedragon->direction = 1;
		                        
		                        itachi->speed = 1;
		                        itachi->direction = 1;
		                        break;
		                    case SDLK_LEFT:
		                    	mage->speed = 1;
		                        mage->direction = -1;
		                        
		                        archer->speed = 1;
		                        archer->direction = -1;
		                        
		                        bluedragon->speed = 1;
		                        bluedragon->direction = -1;
		                        
		                        itachi->speed = 1;
		                        itachi->direction = -1;
		                        break;
		                    case SDLK_SPACE:
		                    	if (mage->attack != 1)
		                            mage->startTime = SDL_GetTicks();
		                        mage->attack = 1;
		                        
		                        if (archer->attack != 1)
		                            archer->startTime = SDL_GetTicks();
		                        archer->attack = 1;
		                        
		                        if (bluedragon->attack != 1)
		                            bluedragon->startTime = SDL_GetTicks();
		                        bluedragon->attack = 1;
		                        
		                        if (itachi->attack != 1)
		                            itachi->startTime = SDL_GetTicks();
		                        itachi->attack = 1;
		                        break;
		                    case SDLK_UP:
		                    	if (mage->y-35 == mage->h)
		                            mage->jumping = 1;
		                        else
		                            mage->jumping = 0;;
		                        
		                        archer->startTime = SDL_GetTicks();
		                        archer->jumping = 1;
		                        
		                        bluedragon->startTime = SDL_GetTicks();
		                        bluedragon->jumping = 1;
		                        
		                        itachi->startTime = SDL_GetTicks();
		                        itachi->jumping = 1;
		                        break;
		                    case SDLK_z:
		                    	if (mage->attack != 2)
		                            mage->startTime = SDL_GetTicks();
		                        mage->attack = 2;
		                        
		                        if (bluedragon->attack != 2)
		                            bluedragon->startTime = SDL_GetTicks();
		                        bluedragon->attack = 2;
		                        
		                        if (itachi->attack != 2)
		                            itachi->startTime = SDL_GetTicks();
		                        itachi->attack = 2;
		                        break;
		                    }
		                    if(e.key.keysym.sym == SDLK_ESCAPE){
	                			if(menu->update(menu) == 1) continue;
								else quit = 1;	
							}
	            }else if (e.type == SDL_KEYUP) {
	                switch (e.key.keysym.sym) {
	                    case SDLK_RIGHT:
	                    	mage->frame = 0;
	                        mage->speed = 0;
	                        
	                        archer->frame = 0;
	                        archer->speed = 0;
	                        
	                        bluedragon->frame = 0;
	                        bluedragon->speed = 0;
	                        
	                        itachi->frame = 0;
	                        itachi->speed = 0;
	                        break;
	                     case SDLK_LEFT:
	                     	mage->frame = 0;
	                        mage->speed = 0;
	                        
	                        archer->frame = 0;
	                        archer->speed = 0;
	                        
	                        bluedragon->frame = 0;
	                        bluedragon->speed = 0;
	                        
	                        itachi->frame = 0;
	                        itachi->speed = 0;
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

        update_queue_fireball(queue_fireball);
        
        update_queue_bigfireball(queue_bigfireball);
        
        archer->update(archer);

        update_queue_arrow(queue_arrow);
        
        bluedragon->update(bluedragon);
        
        update_queue_waterb(queue_waterb);
        
        update_queue_waterblast(queue_waterblast);
        
        itachi->update(itachi);
        
        update_queue_shuriken(queue_shuriken);
        
        update_queue_katon(queue_katon);

        SDL_Delay(4);
        SDL_RenderPresent(wRenderer);  
	}
}else{
	game_close();
    return 0;
}

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

void update_queue_bigfireball(queue_t *queue)
{
    bigfireball_t *bigfireball;
    node_t *node = queue->head;
    while (node != NULL) {
        bigfireball = node->data;
        bigfireball->update(bigfireball);
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

void update_queue_waterb(queue_t *queue)
{
    waterb_t *waterb;
    node_t *node = queue->head;
    while (node != NULL) {
        waterb = node->data;
        waterb->update(waterb);
        node = node->next;
    }
}

void update_queue_waterblast(queue_t *queue)
{
    waterblast_t *waterblast;
    node_t *node = queue->head;
    while (node != NULL) {
        waterblast = node->data;
        waterblast->update(waterblast);
        node = node->next;
    }
}

void update_queue_shuriken(queue_t *queue)
{
    shuriken_t *shuriken;
    node_t *node = queue->head;
    while (node != NULL) {
        shuriken = node->data;
        shuriken->update(shuriken);
        node = node->next;
    }
}

void update_queue_katon(queue_t *queue)
{
    katon_t *katon;
    node_t *node = queue->head;
    while (node != NULL) {
        katon = node->data;
        katon->update(katon);
        node = node->next;
    }
}
