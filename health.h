#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Health
{
public:
    Health(int windowHeight, int healthHeight);
    int basicPosX;
    SDL_Rect rect;
    void reset();
};