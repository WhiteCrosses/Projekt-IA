#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


class Counter{
    public:
        int tickCounter;
        int iteration;
        bool passable;
        bool cooldownSatisfied;
};