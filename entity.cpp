#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "entity.h"
#include "constants.hpp"
#include <iostream>
#include <cmath>

#define PI 3.14


//Init of game
Entity::Entity(){
}


Entity::Entity(int enemyType, int posX, int posY, int angle)
{
    dtime = TimeConstants::DTIME;
    deltaTime = dtime/1000;
    rect.x = posX;
    rect.y = posY;
    startX = posX;
    startY = posY;
    constAngle = angle;
    inUse = false;

    switch(enemyType){
        
        //basic enemy
        case 1:
            rect.w = 20;
            rect.h = 20;
            linSpeed = 100;
            inUse = false;
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
            linSpeed = 300;
            break;
        
        case 4:
            rect.w = 10;
            rect.h = 10;
            linSpeed = 100;
            inUse = false;

        default:
            rect.x = 20;
            rect.y = 20;
            rect.w = 20;
            rect.h = 20;
            break;
    }
}

void Entity::setVariables(int posX, int posY, int angle)
{
    deltaTime = dtime/1000;
    rect.x = posX;
    rect.y = posY;
    startX = posX;
    startY = posY;
    constAngle = angle;
    inUse = false;
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

void Entity::move()
{
    if(rect.x > 640 || rect.x < 0 || rect.y < 0 || rect.y > 480){
            rect.x = startX;
            rect.y = startY;
            inUse = false;
        }
    double radAngle = (constAngle+90)*PI/180;
    incrementX(-cos(radAngle)*linSpeed*deltaTime);
    incrementY(-sin(radAngle)*linSpeed*deltaTime);
}

void Entity::render(SDL_Renderer& renderer,SDL_Texture* entityTexture)
{
    SDL_Renderer* m_renderer = &renderer;
    SDL_RenderCopyEx(m_renderer, entityTexture, NULL, &rect, angle, NULL, SDL_FLIP_HORIZONTAL);
}

bool Entity::collisionCheck(SDL_Rect targetRect){
    // a1 = rect
    //b1 = targetRect

    std::cout<<"entered collisionCheck\n";
    std::cout<<(rect.x > (targetRect.x + targetRect.w))<<", ";
    std::cout<<(targetRect.x > (rect.x + rect.w))<<"\n";
    std::cout<<((rect.y + rect.h) > targetRect.y)<<", ";
    std::cout<<(rect.x > (targetRect.y + targetRect.h))<<"\n";

    if(rect.x == (rect.x + rect.w) && rect.y == (rect.y + rect.h)){
        return false;
    }

    if(rect.x > (targetRect.x + targetRect.w) && targetRect.x < (rect.x + rect.w)){
        return false;
    }

    if((rect.y + rect.h) > targetRect.y && (targetRect.y + targetRect.h) < rect.y){
        return false;
    }

    return true;
}