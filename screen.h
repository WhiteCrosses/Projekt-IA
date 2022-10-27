#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Screen{
public:
    Screen(int width, int height);
    SDL_Texture* loadTexture(const char* path);
    void loadEntity();
    void gameOver();
    void update();
    void keyState(int *quitPtr, int *xMove, int *yMove);
    void clean();
    void delay(int delay);

    SDL_Window* window;             //Unsafe, but needs to stay in public for easy access.
    SDL_Renderer* renderer;         //Might fix later :)
};