#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_tf.h>

class Screen
{
public:
    Screen(int width, int height);
    void clean();
    void gameOver();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};