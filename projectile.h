#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Projectile
{
public:
    Proectile(int controller, int startX, int startY, int turrAngle);
    int angle;
    double angleRad;
    int positionX;
    int positionY;
    double dtime;

    int deltaX;
    int deltaY;

    int targetX;
    int targetY;

    void Displacement();

};