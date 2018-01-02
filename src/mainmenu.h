#ifndef MAINMENU_H_
#define MAINMENU_H_

#include "SDL2/SDL.h"

 
typedef struct menu menu_t;
 
struct menu{
	int frame;
	SDL_Texture *texture[3];
	int (*update)(menu_t *menu);
};
 
menu_t* init_menu();
void destroy_menu(menu_t *menu);
 
#endif
