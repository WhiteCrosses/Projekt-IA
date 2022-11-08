#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "screen.h"
#include <iostream>

//Init of game
Screen::Screen(int width, int height)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow("test",
                        SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED,
                        width,
                        height,
                        SDL_WINDOW_SHOWN);
    if(window == NULL)
        std::cout<<"Failed to load! Error: "<<SDL_GetError()<<std::endl;

    renderer = SDL_CreateRenderer(window,
                        -1,
                        SDL_RENDERER_ACCELERATED);

    SDL_Surface* tmpSurface = IMG_Load("assets/frog.bmp");
    //enemyTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
}


SDL_Texture* Screen::loadTexture(const char* path)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, path);

    if(texture == NULL) std::cout<<"Error loading texture: " << SDL_GetError() << std::endl;

    return texture;
}

//Load texture to the renderer
void Screen::loadEntity()
{
    SDL_RenderCopy(renderer, NULL, NULL, NULL);
}

//game over function - later add here closing page
void Screen::gameOver()
{
    SDL_DestroyWindow(window);
}


void Screen::update()
{
    SDL_RenderPresent(renderer);
}


void Screen::keyState(int *quitPtr, int *hpPtr, int *xMove, int *yMove, int *turretAngle)
{
    SDL_Event e;
    while(SDL_PollEvent(&e)) {
        if(e.type == SDL_QUIT) *quitPtr = 1;
    }

    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if(keystates[SDL_SCANCODE_ESCAPE]) *quitPtr = 1;
    if(keystates[SDL_SCANCODE_C]){
        *hpPtr -= 1;
        if(*hpPtr<=0) *quitPtr = 1;
        }
    
    if(keystates[SDL_SCANCODE_RIGHT]) *turretAngle += 1;
    if(keystates[SDL_SCANCODE_LEFT]) *turretAngle -=1;
    if(keystates[SDL_SCANCODE_UP]) *yMove = -1;
    if(keystates[SDL_SCANCODE_DOWN]) *yMove = 1;

}


void Screen::resetDamagable(){
    damagable = true;
}


void Screen::clean()
{
    SDL_RenderClear(renderer);
}


void Screen::timestep(uint32_t currTime, uint32_t startTime, uint32_t lastFrameTime, double dtime)
{
    currTime = SDL_GetTicks();
    double elapsedTime = (currTime - startTime)/1000.0;
    double frameTime = (currTime - lastFrameTime);        

    if(frameTime<dtime) SDL_Delay(dtime - frameTime);
        //if (elapsedTime>=10) quit = 1;
}


void Screen::delay(int delay)
{
    SDL_Delay(delay);
}



/*  To be moved to another class - its test function

void Screen::fillPink(int x, int y)
{
    SDL_SetRenderDrawColor(renderer, 250, 160, 200, 1);
    SDL_RenderClear(renderer);

    SDL_Rect bg;
    bg.x=x;
    bg.y=y;
    bg.w=50;
    bg.h=50;

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &bg);
    SDL_RenderPresent(renderer);


    SDL_SetRenderDrawColor(renderer,0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);
}

░░░░░░░░░░░░░▄▄▀▀▀▀▀▀▄▄
░░░░░░░░░░▄▄▀▄▄▄█████▄▄▀▄
░░░░░░░░▄█▀▒▀▀▀█████████▄█▄
░░░░░░▄██▒▒▒▒▒▒▒▒▀▒▀▒▀▄▒▀▒▀▄
░░░░▄██▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▄
░░░░██▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▌
░░░▐██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐█
░▄▄███▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█
▐▒▄▀██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐▌
▌▒▒▌▒▀▒▒▒▒▒▒▄▀▀▄▄▒▒▒▒▒▒▒▒▒▒▒▒█▌
▐▒▀▒▌▒▒▒▒▒▒▒▄▄▄▄▒▒▒▒▒▒▒▀▀▀▀▄▒▐
░█▒▒▌▒▒▒▒▒▒▒▒▀▀▒▀▒▒▐▒▄▀██▀▒▒▒▌
░░█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐▒▒▒▒▒▒▒▒█
░░░▀▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌▒▒▒▒▒▒▄▀
░░░▐▒▒▒▒▒▒▒▒▒▄▀▐▒▒▒▒▒▐▒▒▒▒▄▀
░░▄▌▒▒▒▒▒▒▒▄▀▒▒▒▀▄▄▒▒▒▌▒▒▒▐▀▀▀▄▄▄
▄▀░▀▄▒▒▒▒▒▒▒▒▀▀▄▄▄▒▄▄▀▌▒▒▒▌░░░░░░
▐▌░░░▀▄▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▀░░░░░░░
░█░░░░░▀▄▄▒▒▒▒▒▒▒▒▒▒▒▒▄▀░█░░░░░░░
░░█░░░░░░░▀▄▄▄▒▒▒▒▒▒▄▀░░░░█░░░░░░
░░░█░░░░░░░░░▌▀▀▀▀▀▀▐░░░░░▐▌░░░░░ 



*/