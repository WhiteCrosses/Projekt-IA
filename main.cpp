#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"
#include "Entity.h"

#define TARGET_FPS 60

int main( int argc, char *argv[] ){

    SDL_Init(SDL_INIT_EVERYTHING);

    Screen window(640,480);
    Entity entity(1);


    //Loading textures area:
    SDL_Texture* entityTexture = window.loadTexture("resources/frog.bmp");

    SDL_Rect frogRect;
    frogRect.x = 50;
    frogRect.y = 50;
    frogRect.w = 50;
    frogRect.h = 50;


    int quit = 0;
    int *quitPtr;
    int xMove = 0;
    int yMove = 0;

    quitPtr = &quit;

    // To move to separate class which will track time / FPS
    // START
    double start = 0;
    double end = 0;
    double dtime = 0;
    uint32_t lastFrameTime = 0;
    uint32_t startTime = SDL_GetTicks();
    uint32_t currTime = 1;
    dtime = 1000/TARGET_FPS; //set time between each frame
    // END


    SDL_SetRenderDrawColor(window.renderer, 0, 0, 0, 1);  //set color to the (255,0,0,1)
    window.clean();                 
    window.update();
    window.delay(1000);

    while(quit != 1){
        lastFrameTime = SDL_GetTicks();
        
        //Heavy-on-time stuff here
        window.clean();
        window.keyState(quitPtr, &xMove, &yMove);
        frogRect.x += xMove;
        frogRect.y += yMove;
        SDL_RenderCopy(window.renderer, entityTexture, NULL, &frogRect);
        window.update();
        xMove = 0;
        yMove = 0;
        //Calculate elapsed time
        currTime = SDL_GetTicks();
        double elapsedTime = (currTime - startTime)/1000.0;
        double frameTime = (currTime - lastFrameTime);
        
        if(frameTime<dtime) SDL_Delay(dtime - frameTime);
        //if (elapsedTime>=10) quit = 1;
    }
    window.gameOver();
    SDL_Quit();

    return 0;
}