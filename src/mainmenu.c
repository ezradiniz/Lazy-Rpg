#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "mainmenu.h"
#include "util.h"

SDL_Event e;
int quit = 0;
t_menu *menu;
SDL_Texture *img;

void load_img1(){
	menu->img = game_loadTexture("img/easyselect.bmp");
}

void load_img2(){
	menu->img = game_loadTexture("img/exitselect");
}

t_menu* init_menu(){
	
	menu = (t_menu*)malloc(sizeof(t_menu));
	menu->img = game_loadTexture("img/playselect.bmp");
	menu->menu_option = 1;
	
	while(!quit){
		while(SDL_PollEvent(&e) != 0){
			if(e.type == SDL_QUIT){
				quit = 1;
			}else if(e.type == SDL_KEYDOWN){
				switch(e.key.keysym.sym){
					case SDLK_DOWN:
						load_img1();
						menu->menu_option = 2;
						break;
					case SDLK_UP:
						load_img2();
						break;
				}
			}
		}
		quit = 1;
	}
	
	return menu;	
}



