#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Entity
{
public:
    Entity(double dtime, int enemyType, int posX, int posY, int angle);
    SDL_Rect rect;

    int linSpeed;   //px per sec
    int angSpeed;   //deg per sec
    double deltaTime;
    int angle;
    int constAngle;
    int startX;
    int startY;

    void setX(int x);
    void setY(int y);
    void incrementX(int x);
    void incrementY(int y);
    void move();
    void render(SDL_Renderer& renderer,SDL_Texture* entityTexture,int entityAngle);

    int getX();
    int getY();

};