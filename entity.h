#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Entity
{
public:
    Entity(int enemyType, int posX, int posY, float dangle);
    Entity();
    SDL_Rect rect;

    double dtime;
    int linSpeed;   //px per sec
    int angSpeed;   //deg per sec
    double deltaTime;
    float angle;
    float constAngle;
    int startX;
    int startY;
    bool inUse;


    void setVariables(int posX, int posY, int angle);
    void setVariables(int posX, int posY, int angle, int linSpeedE);
    void setX(int x);
    void setY(int y);
    void incrementX(int x);
    void incrementY(int y);
    void move();
    void explosion(int posX, int posY);
    void render(SDL_Renderer& renderer,SDL_Texture* entityTexture);
    bool collisionCheck(SDL_Rect targetRect);

    int getX();
    int getY();

};