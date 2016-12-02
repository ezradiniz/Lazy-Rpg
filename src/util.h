#ifndef UTIL_H_
#define UTIL_H_

#include <SDL2/SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define GRAVITY 4

SDL_Renderer *wRenderer;
SDL_Window *wGame;

void game_init();
SDL_Texture *game_loadTexture(const char *path, int r, int g, int b);
void game_renderTexture(int x, int y,
                        int w, int h,
                        SDL_Rect *clip,
                        double angle,
                        SDL_Point *center,
                        SDL_RendererFlip flip,
                        SDL_Texture *texture);
Uint32 game_animation_frame(Uint32 oldTime, int animation, int game, int max);
void game_close();

#endif
