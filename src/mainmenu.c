#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "mainmenu.h"
#include "util.h"
#include "world.h"
#include <stdio.h>
#include <stdbool.h>

int mouse_x = 0;
int mouse_y = 0;
bool play = false;
SDL_Rect bg_rect;
SDL_Rect play_rect;
SDL_Rect exit_rect;	
t_menu *menu;

t_menu* load_menu_media(t_menu *menu){
	
	menu->background = game_loadTexture("img/backgroundMenu.png",-1,-1,-1);
	menu->play = game_loadTexture("img/playselect.bmp",-1,-1,-1);
	menu->exit = game_loadTexture("img/exitselect.bmp",-1,-1,-1);
	return menu;
}

void update_menu_play(t_menu *menu){
	int flag = SDL_RenderCopy(wRenderer,menu->play,NULL,NULL);
	if(flag < 0){
		printf("Failed to load menu media SDL ERROR: %s",SDL_GetError());
	}
	
}

void update_menu_exit(t_menu *menu){
	int flag = SDL_RenderCopy(wRenderer,menu->exit,NULL,NULL);
	if(flag < 0){
		printf("Failed to load menu media SDL ERROR: %s",SDL_GetError());
	}
}

t_menu* init_menu(){	

	menu = malloc(sizeof(t_menu));

	//bg rect
	bg_rect.x = 0;
	bg_rect.y = 0;
	bg_rect.w = 1070;
	bg_rect.h = 600;
	
	
	//play rect
	play_rect.x = 427;
	play_rect.y = 332;
	play_rect.w = 226;
	play_rect.h = 45;
	
	
	//exit rect
	exit_rect.x = 427;
	exit_rect.y = 426;
	exit_rect.w = 226;
	exit_rect.h = 45;	
	
	//easy rect
	
	//medium rect
	
	//hard rect
	
	menu = load_menu_media(menu);
	update_menu_play(menu);
	
	return menu;
}

bool mouse_getPos(SDL_Event event,t_menu *menu){
	bool flag = false;
	//update_menu_play(menu);
	SDL_GetMouseState(&mouse_x,&mouse_y);
		
	while(!flag){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				flag = true;
			}else if(event.type == SDL_MOUSEMOTION){
				if(mouse_x >= play_rect.x && mouse_x <= play_rect.x + play_rect.w && mouse_y >= play_rect.y && mouse_y <= play_rect.y + play_rect.h){
					update_menu_play(menu);
				}else if(mouse_x >= exit_rect.x && mouse_x <= exit_rect.x + exit_rect.w && mouse_y >= exit_rect.y && mouse_y <= exit_rect.y + exit_rect.h){
					update_menu_exit(menu);
				}
			}
		}
	}
	return flag;		
}
