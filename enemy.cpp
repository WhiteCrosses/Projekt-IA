#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "enemy.h"
#include "entity.h"
#include <cmath>


//Init of game
Enemy::Enemy() : Entity(1, 20, 20, 0)
{
    setVariables(20, 20, 0);
    rect.w = 20;
    rect.h = 20;
    linSpeed = 0;
    linAcceleration = 0.5;
    health = 100;
    inUse = true;

}