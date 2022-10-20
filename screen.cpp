#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "screen.h"
#include <iostream>

Screen::Screen(int width, int height)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow("test",
                        SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED,
                        width,
                        height,
                        SDL_WINDOW_SHOWN);
    if(window == NULL)
        std::cout<<"Failed to load! Error: "<<SDL_GetError()<<std::endl;

    renderer = SDL_CreateRenderer(window,
                        -1,
                        SDL_RENDERER_ACCELERATED);
}

void Screen::clean()
{
    SDL_RenderClear(renderer);
}

void Screen::gameOver()
{
    SDL_DestroyWindow(window);
}

void Screen::fillPink()
{
    SDL_SetRenderDrawColor(255,200,228,1);
}