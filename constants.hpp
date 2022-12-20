#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdio.h>
#include <stdlib.h>


namespace TimeConstants
{
  const float FPS = 60;
  const float DTIME = 1000/FPS;
}

namespace WindowConstants
{
    const int Width = 640;
    const int Height = 480;
}

namespace EntityLimits
{
    const int MaxEnemies = 5;
    const int MaxProjectiles = 10;
    const int MaxHearts = 5;
    const int EnemySpawnCooldown = 60;
}

namespace TurretConstants
{
    const int FireRateCooldown = 20;
    const int TurretAngularSpeed = 50;
}
#endif