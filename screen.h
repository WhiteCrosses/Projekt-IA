#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Screen{
public:
    Screen(int width, int height);
    
    bool damagable = true;
    
    SDL_Texture* loadTexture(const char* path);
    void loadEntity();
    void gameOver();
    void update();
    void keyState(int *quitPtr, int *hpPtr, int *xMove, int *yMove, int *turretAngle, bool *newProjectile);
    void clean();
    void delay(int delay);
    void timestep(uint32_t currTime, uint32_t startTime, uint32_t lastFrameTime, double dtime);
    void resetDamagable();

    SDL_Window* window;             //Unsafe, but needs to stay in public for easy access.
    SDL_Renderer* renderer;         //Might fix later :)
};