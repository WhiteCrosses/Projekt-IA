#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"

int main( int argc, char *argv[] ){

    SDL_Init(SDL_INIT_EVERYTHING);

    Screen window(640,480);
    window.SDL_SetRenderDrawColor(255,200,228,1);
    window.clean();

    SDL_Delay(5000);

    window.gameOver();
    SDL_Quit();

    return 0;
}