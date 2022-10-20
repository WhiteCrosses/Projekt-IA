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
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Rect bg;
    bg.x=50;
    bg.y=50;
    bg.w=50;
    bg.h=50;
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &bg);
    SDL_RenderPresent(renderer;)


    SDL_SetRenderDrawColor(renderer,0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);
}