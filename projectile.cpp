#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "projectile.h"
#include "entity.h"
#include "constants.hpp"
#include <cmath>


Projectile::Projectile() : Entity()
{
    setVariables(WindowConstants::Width/2, (WindowConstants::Height/2)+140, 0, 50);
    rect.w = 20;
    rect.h = 20;
    
}