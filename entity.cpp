#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "entity.h"
#include <iostream>

//Init of game
Entity::Entity(int controller)
{
    struct {
        int width;
        int height;
    } frog;

    frog.width = 50;
    frog.height = 50;
}

SDL_Rect* Entity::frogRect()
{
    
}


