#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "counter.h"
#include <cmath>

Counter::Counter()
{
    tickCounter = 0;
    iteration = 0;
    passable = false;
    cooldownSatisfied = false;
    
}