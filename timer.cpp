#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "timer.h"
#include "constants.hpp"
#include <iostream>

Timer::Timer()
{
    enemySpawnCooldownTimer = 0;
}

int Timer::getEnemySpawnCooldownCounter()
{
    return enemySpawnCooldownTimer;
}

void Timer::incrementEnemySpawnCooldownCounter()
{
    enemySpawnCooldownTimer++;
}