#ifndef MAINMENU_H_
#define MAINMENU_H_
#include <stdbool.h>
#include "SDL2/SDL.h"
#define MENU_COORD_WIDTH 1070
#define MENU_COORD_HEIGHT 600

typedef struct main_menu t_menu;

struct main_menu{
	int x,y,w,h;
//	SDL_Rect background_rect;
//	SDL_Rect background_rect;
	SDL_Texture *background;
	SDL_Texture *play;
	SDL_Texture *exit;
	SDL_Texture *easy;
	SDL_Texture *medium;
	SDL_Texture *hard;
	int menu_option;
	SDL_Surface *menu_options;
};

t_menu* init_menu();
bool mouse_getPos();


#endif
