#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Screen
{
public:
    Screen(int width, int height);
    void clean();
    void gameOver();
    void fillPink();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};