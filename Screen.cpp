#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_tf.h>
#include "Screen.h"

Screen::Screen(int width, int height)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow("test",
                        SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED,
                        width,
                        height,
                        SDL_WINDOW_SHOW);
    if(window == NULL)
        std::cout<<"Failed to load! Error: "<<SDL_GetError()<<std::endl;

    renderer = SDL_CreateRenderer(window,
                        -1,
                        SDL_RENDERER_ACCELERATED);
}

Screen::clean()
{
    SDL_RenderClear(renderer);
}

Screen::gameOver()
{
    SDL_DestroyWindow(window);
}