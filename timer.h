#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


class Timer
{
    public:
        Timer();

        void incrementEnemySpawnCooldownCounter();


        int getEnemySpawnCooldownCounter();
        int enemySpawnCooldownTimer;
};



