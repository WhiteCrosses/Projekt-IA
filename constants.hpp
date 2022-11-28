#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdio.h>
#include <stdlib.h>


namespace TimeConstants
{
  const int FPS = 60;
  const int DTIME = 1000/FPS;
}

namespace WindowConstants
{
    const int Width = 480;
    const int Height = 640;
}

namespace EntityLimits
{
    const int MaxEnemies = 5;
    const int MaxProjectiles = 10;
    const int MaxHearts = 5;
    const int EnemySpawnCooldown = 60;
}

namespace EntityConstants
{


}
#endif