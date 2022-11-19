#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "entity.h"
#include <iostream>
#include <cmath>

#define PI 3.14


//Init of game
Entity::Entity(double dtime, int enemyType, int posX, int posY, int angle)
{
    deltaTime = dtime/1000;
    rect.x = posX;
    rect.y = posY;
    startX = posX;
    startY = posY;

    switch(enemyType){
        
        //basic enemy
        case 1:
            rect.w = 30;
            rect.h = 30;
            linSpeed = 100;
            break;

        //turret
        case 2:
            rect.w = 20;
            rect.h = 20;
            angSpeed = 10;
            linSpeed = 100;
            angle = 45;
            break;
        
        //projectile
        case 3:
            rect.w = 20;
            rect.h = 20;
            linSpeed = 200;
            break;

        default:
            rect.x = 20;
            rect.y = 20;
            rect.w = 20;
            rect.h = 20;
            break;
    }
}

int Entity::getX()
{
    return rect.x;
}

int Entity::getY()
{
    return rect.y;
}

void Entity::setX(int x)
{
    rect.x = x;
}

void Entity::setY(int y)
{
    rect.y = y;
}

void Entity::incrementX(int x)
{
    rect.x += x;
}

void Entity::incrementY(int y)
{
    rect.y += y;
}

void Entity::move(bool *projectileExists)
{
    if(rect.x > 640 || rect.x < 0 || rect.y < 0 || rect.y > 480){
            rect.x = startX;
            rect.y = startY;
            *projectileExists = false;
        }
    double radAngle = (constAngle+90)*PI/180;
    incrementX(-cos(radAngle)*linSpeed*deltaTime);
    incrementY(-sin(radAngle)*linSpeed*deltaTime);
}

void Entity::render(SDL_Renderer& renderer,SDL_Texture* entityTexture,int entityAngle)
{
    SDL_Renderer* m_renderer = &renderer;
    SDL_RenderCopyEx(m_renderer, entityTexture, NULL, &rect, entityAngle, NULL, SDL_FLIP_HORIZONTAL);
}