#include <SDL2/SDL_image.h>
#include "util.h"

void game_init()
{
    SDL_Init(SDL_INIT_VIDEO);

    wGame = SDL_CreateWindow("MageBotRpg",
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            SCREEN_WIDTH,
                            SCREEN_HEIGHT,
                            0);

    wRenderer = SDL_CreateRenderer(wGame,
                                        -1,
                                        SDL_RENDERER_ACCELERATED);

    IMG_Init(IMG_INIT_PNG);
}

SDL_Texture *game_loadTexture(const char *path)
{
    SDL_Texture *texture = NULL;
    SDL_Surface *surface = IMG_Load(path);

    SDL_SetColorKey(surface,
                    SDL_TRUE,
                    SDL_MapRGB(surface->format, 128, 128, 128));

    texture = SDL_CreateTextureFromSurface(wRenderer, surface);
    SDL_FreeSurface(surface);

    return texture;
}

void game_renderTexture(int x, int y,
                        int w, int h,
                        SDL_Rect *clip,
                        double angle,
                        SDL_Point *center,
                        SDL_RendererFlip flip,
                        SDL_Texture *texture)
{
    SDL_Rect render = {x, y, w, h};
    if (clip != NULL) {
        render.w = clip->w;
        render.h = clip->h;
    }

    SDL_RenderCopyEx(wRenderer, texture, clip, &render, angle, center, flip);
}

void game_close()
{
    SDL_DestroyRenderer(wRenderer);
    SDL_DestroyWindow(wGame);

    IMG_Quit();
    SDL_Quit();
}
