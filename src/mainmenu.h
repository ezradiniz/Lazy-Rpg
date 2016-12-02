#ifndef MAINMENU_H_
#define MAINMENU_H_
#include <stdbool.h>
#include "SDL2/SDL.h"

typedef struct main_menu t_menu;

struct main_menu{
	SDL_Rect menu_rect;
	SDL_Texture *img;
	int menu_option;
};

t_menu* init_menu();


#endif
