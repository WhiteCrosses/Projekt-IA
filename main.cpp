#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"
#include "Entity.h"
#include "health.h"

#define TARGET_FPS 60
#define DTIME 1000/TARGET_FPS

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

#define FROG_DISTANCE 80
#define HEART_DISTANCE 30
#define HEART_DISTANCE_BOTTOM 90

#define TURRET_POSX WINDOW_WIDTH/2
#define TURRET_POSY WINDOW_HEIGHT-140



int main( int argc, char *argv[] ){

    SDL_Init(SDL_INIT_EVERYTHING);

    Screen window(WINDOW_WIDTH,WINDOW_HEIGHT);
    
    Entity enemy(DTIME, 1, 50, 50, 0);
    Entity turret(DTIME, 2, TURRET_POSX, TURRET_POSY, 0);
    
    Health heart(WINDOW_HEIGHT, HEART_DISTANCE_BOTTOM);


    //Loading textures area:
    SDL_Texture* entityTexture = window.loadTexture("resources/enemy.png");
    SDL_Texture* healthTexture = window.loadTexture("resources/heart.png");
    SDL_Texture* bgTexture = window.loadTexture("resources/bg.png");
    SDL_Texture* turretTexture = window.loadTexture("resources/turretM.png");
    SDL_Texture* projectileTexture = window.loadTexture("resources/heart.png");

    SDL_Rect bgRect;

    //Configure starting sizes and positions of screen elements


    bgRect.x = 0;
    bgRect.y = 0;
    bgRect.w = 648;
    bgRect.h = 480;

    bool newProjectile = false;
    bool projectileExists = false;

    int quit = 0;
    int *quitPtr;
    quitPtr = &quit;

    int hpLeft = 5;
    int *hpPtr;
    hpPtr = &hpLeft;

    //Track time / FPS
    double start = 0;
    double end = 0;
    int turretAngle = 0;

    uint32_t lastFrameTime = 0;
    uint32_t startTime = SDL_GetTicks();
    uint32_t currTime = 1;
    uint32_t damageTime = 0;


    //Window opening config

    window.clean();                 
    window.update();


    //add damage on touching something
    //add cooldown of getting damaged
    //variable (bool damagable?)

    int xMove = 0;
    int yMove = 0;
    int direction = 1;

    int entityAngle = 0;
    Entity projectile(DTIME, 3, TURRET_POSX, TURRET_POSY, turretAngle);

    while(quit != 1){
        lastFrameTime = SDL_GetTicks();
        
        //Heavy-on-time stuff here
        SDL_SetRenderDrawColor(window.renderer, 158,132,146,1);
        window.clean();
        window.keyState(quitPtr, hpPtr, &xMove, &yMove, &turretAngle, &newProjectile);

        


        if(newProjectile){
            projectileExists = true;
            projectile.constAngle = turretAngle;
            newProjectile = false;
        }

        if(projectileExists){
            projectile.render(*window.renderer, healthTexture, 0);
            projectile.move(&projectileExists);
        }

        if(direction == 1) xMove = 5;
        if(direction == 0) xMove = -5;

        enemy.rect.x += xMove;
        enemy.rect.y += yMove;
        entityAngle += 3;


        if(enemy.rect.x >= (WINDOW_WIDTH - FROG_DISTANCE)) direction = 0;
        if(enemy.rect.x <= FROG_DISTANCE) direction = 1;
        
        SDL_RenderCopy(window.renderer, bgTexture, NULL, &bgRect);
        enemy.render(*window.renderer, entityTexture, entityAngle);
        turret.render(*window.renderer, turretTexture, turretAngle);
        
        for(int i=0; i<hpLeft; i++){
            SDL_RenderCopy(window.renderer, healthTexture, NULL, &heart.rect);
            heart.rect.x += HEART_DISTANCE;
        }

        window.update();
        xMove = 0;
        yMove = 0;
        heart.reset();
        //Calculate elapsed time
        window.timestep(currTime, startTime, lastFrameTime, DTIME);
    }
    window.gameOver();
    SDL_Quit();

    return 0;
}