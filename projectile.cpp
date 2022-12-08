#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "projectile.h"
#include "entity.h"
#include "constants.hpp"
#include <cmath>


Projectile::Projectile()
{
    setVariables(WindowConstants::Width/2, WindowConstants::Height/2, 0, 50);
    rect.w = 20;
    rect.h = 20;
    
}