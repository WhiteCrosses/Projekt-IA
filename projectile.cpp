#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "projectile.h"
#include <iostream>
#include <cmath>

#define PI 3.14

//Init of game

// delta x = cos(ang)*speed*dtime
// dleta y = sin(ang)*speed*dtime



Projectile::Projectile(int controller, int startX, int startY, int turrAngle)
{
    positionX = startX;
    positionY = startY;
    dtime = 1000/50;
    angle = turrAngle;
    angleRad = angle*PI/180;

    deltaX = 0;
    deltaY = 0;
}

void Projectile::Displacement(){
    deltaX = cos(angleRad)*100*dtime;
}



