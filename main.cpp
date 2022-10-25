#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"

#define TARGET_FPS 30

int main( int argc, char *argv[] ){

    SDL_Init(SDL_INIT_EVERYTHING);

    Screen window(640,480);
    bool quit = false;
    int r = 0;

    double start = 0;
    double end = 0;
    double dTime = 0.0;
    double milliSecs = (1000.0 / TARGET_FPS) / 1000.0;
    uint32_t startTime = SDL_GetTicks();
    uint32_t currTime = 1;

    while(!quit){
        start = SDL_GetTicks();
        window.fillPink(r,0);
        r++;
        currTime = SDL_GetTicks();
        double elapsedTime = (currTime - startTime)/1000.0;
        if(elapsedTime>=5){
            quit=true;
        }
    }
    window.gameOver();
    SDL_Quit();

    return 0;
}