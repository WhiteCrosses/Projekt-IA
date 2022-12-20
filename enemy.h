#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "entity.h"

class Enemy : public Entity
{
public:
    Enemy();
    int health;

};