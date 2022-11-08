#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"
#include "Entity.h"
#include "projectile.h"

#define TARGET_FPS 50

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

#define HEART_DISTANCE 20

#define TURRET_POSX WINDOW_WIDTH/2
#define TURRET_POSY WINDOW_HEIGHT-140



int main( int argc, char *argv[] ){

    SDL_Init(SDL_INIT_EVERYTHING);

    Screen window(WINDOW_WIDTH,WINDOW_HEIGHT);
    Entity entity(1);


    //Loading textures area:
    SDL_Texture* entityTexture = window.loadTexture("resources/frog.png");
    SDL_Texture* healthTexture = window.loadTexture("resources/hardcore-heart.png");
    SDL_Texture* bgTexture = window.loadTexture("resources/bg.png");
    SDL_Texture* turretTexture = window.loadTexture("resources/turretM.png");

    SDL_Rect turretRect;
    SDL_Rect healthRect;
    SDL_Rect frogRect;
    SDL_Rect bgRect;

    //Configure starting sizes and positions of screen elements
    frogRect.x = 50;
    frogRect.y = 50;
    frogRect.w = 100;
    frogRect.h = 100;

    healthRect.x = 20;
    healthRect.y = WINDOW_HEIGHT - 90;
    healthRect.w = 40;
    healthRect.h = 40;

    bgRect.x = 0;
    bgRect.y = 0;
    bgRect.w = 648;
    bgRect.h = 480;

    turretRect.x = TURRET_POSX;
    turretRect.y = TURRET_POSY;
    turretRect.w = 50;
    turretRect.h = 50;


    int quit = 0;
    int *quitPtr;
    quitPtr = &quit;

    int xMove = 0;
    int yMove = 0;

    int hpLeft = 5;
    int *hpPtr;
    hpPtr = &hpLeft;

    //Track time / FPS
    double start = 0;
    double end = 0;
    double dtime = 0;
    int turretAngle = 0;

    uint32_t lastFrameTime = 0;
    uint32_t startTime = SDL_GetTicks();
    uint32_t currTime = 1;
    uint32_t damageTime = 0;

    dtime = 1000/TARGET_FPS; //set time between each frame

    Projectile kula(NULL, )


    //Window opening config
    SDL_SetRenderDrawColor(window.renderer, 105, 124, 104, 0.8);  //set color to the (255,0,0,1)
    window.clean();                 
    window.update();

    //window.delay(1000);


    //add damage on touching something
    //add cooldown of getting damaged
    //variable (bool damagable?)




    while(quit != 1){
        lastFrameTime = SDL_GetTicks();
        
        //Heavy-on-time stuff here
        window.clean();
        window.keyState(quitPtr, hpPtr, &xMove, &yMove, &turretAngle);
        frogRect.x += xMove;
        frogRect.y += yMove;
        
        SDL_RenderCopy(window.renderer, bgTexture, NULL, &bgRect);
        SDL_RenderCopy(window.renderer, entityTexture, NULL, &frogRect);
        SDL_RenderCopyEx(window.renderer, turretTexture, NULL, &turretRect, turretAngle, NULL, SDL_FLIP_HORIZONTAL);
        for(int i=0; i<hpLeft; i++){
            SDL_RenderCopy(window.renderer, healthTexture, NULL, &healthRect);
            healthRect.x += HEART_DISTANCE;
        }

        window.update();
        xMove = 0;
        yMove = 0;
        healthRect.x = 20;

        //Calculate elapsed time
        window.timestep(currTime, startTime, lastFrameTime, dtime);
    }
    window.gameOver();
    SDL_Quit();

    return 0;
}