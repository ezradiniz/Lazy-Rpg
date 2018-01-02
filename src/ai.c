#include "ai.h"
#include "SDL2/SDL.h"

void archerIA(mage_t *mage, archer_t *archer)
{
   
    if(archer->x > mage->x){
            archer->direction=-1;
        }else{
            archer->direction=1;
        }
   
    if(archer->direction == -1){
        if(archer->x - mage->x < 400){
            archer->speed = 1;
            archer->direction=1;
        }else if(archer->x - mage->x > 650){
            archer->speed= 1;
            archer->direction = -1;
        }else{
            archer->speed = 0;
            archer->startTime = SDL_GetTicks();
            archer->attack = 1;        
        }
    }else{
        if(mage->x - archer->x < 400){
            archer->speed = 0;
            archer->direction= -1;
        }else if(mage->x - archer->x > 650){
            archer->speed = 1;
            archer->direction = 1;
        }else{
            archer->speed = 0;
            archer->startTime = SDL_GetTicks();
            archer->attack = 1;
        }
    }
}


void blueDragonIA(mage_t *mage,bluedragon_t *bluedragon){
    
        if(bluedragon->x > mage->x){
            bluedragon->direction=-1;
        }else{
                bluedragon->direction=1;
        }
        
    if(bluedragon->direction == -1){

        if(bluedragon->x - mage->x < 200){
            
            bluedragon->speed = 2;
            
            bluedragon->direction=1;
            
        }else if(bluedragon->x - mage->x > 650){
            
            bluedragon->speed= 2;
            
            bluedragon->direction = -1;
            
        }else{
            
            bluedragon->speed = 0;

            if(bluedragon->x - mage->x < 400){
            bluedragon->startTime = SDL_GetTicks();
            bluedragon->attack = 2;
            
            }else{
            bluedragon->startTime = SDL_GetTicks(); 
            bluedragon->attack = 1; 
            }
            
        }
                  
    }else{
        if(mage->x - bluedragon->x < 200){
            bluedragon->speed = 2;
            bluedragon->direction= -1;
        }else if(mage->x - bluedragon->x > 650){
            bluedragon->speed = 2;
            bluedragon->direction = 1;
        }else{
            bluedragon->speed = 0;
            bluedragon->startTime = SDL_GetTicks();
            bluedragon->attack = 2;
        }
    }

}
