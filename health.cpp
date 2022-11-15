#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "health.h"
#include <iostream>




//Init of game
Health::Health(int windowHeight, int healthHeight)
{
    basicPosX = 20;

    rect.x = basicPosX;
    rect.y = windowHeight-healthHeight;
    rect.w = 20;
    rect.h = 20;
}

void Health::reset()
{
    rect.x = basicPosX;
}

