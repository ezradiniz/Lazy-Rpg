#include "mainmenu.h"
#include "util.h"
#include <stdio.h>
 
static void _loadMedia(menu_t *menu){
    menu->texture[0] = game_loadTexture("img/defaultmenu.png", -1, -1, -1);
    menu->texture[1] = game_loadTexture("img/playselect.png", -1, -1, -1);
    menu->texture[2] = game_loadTexture("img/easyselect.png",-1,-1,-1);
    menu->texture[3] = game_loadTexture("img/exitselect.png",-1,-1,-1);
}

static int _update(menu_t *menu){
    SDL_Event event;
    int flag = -1;
    while(flag < 0){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                flag = 1;
            }else if(event.type == SDL_MOUSEMOTION){
                if(event.button.x >= 427 && event.button.x <= 653 && event.button.y >= 332 && event.button.y <= 383){
                    menu->frame = 1;
                }else if(event.button.x >= 427 && event.button.x <= 653 && event.button.y >= 384 && event.button.y <= 422){
                	menu->frame = 2;
				} else if(event.button.x >= 427 && event.button.x <= 653 && event.button.y >= 423 && event.button.y <= 475){
                    menu->frame = 3;
                }else{
                	menu->frame = 0;
				}
            }else if(event.type == SDL_MOUSEBUTTONDOWN){
            	if(menu->frame == 3){
            		flag = 99;
				}else if(menu->frame == 1){
					return menu->frame;
				}
			}
        }
        SDL_SetRenderDrawColor(wRenderer, 0, 0, 0, 0);
        SDL_RenderClear(wRenderer);
        SDL_RenderCopy(wRenderer, menu->texture[menu->frame], NULL, NULL);
        SDL_Delay(10);
        SDL_RenderPresent(wRenderer);
    }  
    return flag;       
}

menu_t* init_menu()
{   
 
    menu_t *menu = malloc(sizeof(menu_t));
    menu->frame = 0;
    _loadMedia(menu);
    menu->update = _update;

    return menu;
}
