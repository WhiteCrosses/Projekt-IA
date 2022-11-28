#include <iostream>
#include <SDL2/SDL.h>
#include <cstdlib>
#include "Screen.h"
#include "Entity.h"
#include "health.h"
#include "enemy.h"
#include "timer.h"
#include "constants.hpp"
#include <random>


#define FROG_DISTANCE 80
#define HEART_DISTANCE 30
#define HEART_DISTANCE_BOTTOM 90
#define PARTICLE_COUNT 10

#define TURRET_POSX WindowConstants::Width/2
#define TURRET_POSY WindowConstants::Height-140




int main( int argc, char *argv[] ){

    int i;


    SDL_Init(SDL_INIT_EVERYTHING);

    Screen window(WindowConstants::Width,WindowConstants::Height);
    Health heart(WindowConstants::Height, HEART_DISTANCE_BOTTOM);
    Entity turret(2, TURRET_POSX, TURRET_POSY, 0);

    Entity** enemy = new Entity*[EntityLimits::MaxEnemies];
    for(i=0;i<EntityLimits::MaxProjectiles;i++) enemy[i] = new Entity (1, 50, 50, 0);

    Entity** projectile = new Entity*[EntityLimits::MaxProjectiles];
    for(i=0;i<EntityLimits::MaxProjectiles;i++) projectile[i] = new Entity(3, TURRET_POSX, TURRET_POSY, 0);

    Entity** particle = new Entity*[PARTICLE_COUNT];
    for(i=0;i<PARTICLE_COUNT;i++) particle[i] = new Entity(4, 0, 0, 0);



    //Loading textures area:
    SDL_Texture* entityTexture = window.loadTexture("resources/enemy.png");
    SDL_Texture* healthTexture = window.loadTexture("resources/heart.png");
    SDL_Texture* bgTexture = window.loadTexture("resources/bg.png");
    SDL_Texture* turretTexture = window.loadTexture("resources/turretM.png");
    SDL_Texture* projectileTexture = window.loadTexture("resources/heart.png");
    SDL_Texture* explosionTexture = window.loadTexture("resources/particle.png");

    SDL_Rect bgRect;

    //Configure starting sizes and positions of screen elements

    bgRect.x = 0;
    bgRect.y = 0;
    bgRect.w = 648;
    bgRect.h = 480;

    bool newProjectile = false;
    bool projectileExists = false;

    int quit = 0;
    int *quitPtr;
    quitPtr = &quit;

    int hpLeft = 5;
    int *hpPtr;
    hpPtr = &hpLeft;

    double start = 0;
    double end = 0;
    int turretAngle = 0;

    uint32_t lastFrameTime = 0;
    uint32_t startTime = SDL_GetTicks();
    uint32_t currTime = 1;
    uint32_t damageTime = 0;

    window.clean();                 
    window.update();

    int xMove = 0;
    int yMove = 0;
    int dist = 0;


    int entityAngle = 0;
    bool cooldownSatisfied = false;
    

    int tickCounter = 0;
    int enemySpawnTickCounter = 0;
    int enemySpawnCooldown = 120;
    bool entityCooldownSatisfied = false;


    while(quit != 1){
        lastFrameTime = SDL_GetTicks();
        
        //Heavy-on-time stuff here
        SDL_SetRenderDrawColor(window.renderer, 158,132,146,1);
        window.clean();
        window.keyState(quitPtr, hpPtr, &xMove, &yMove, &turretAngle, &newProjectile, &turret, TimeConstants::DTIME);


        if(enemySpawnTickCounter == EntityLimits::EnemySpawnCooldown){
            
            std::random_device rd; // obtain a random number from hardware
            std::mt19937 gen(rd()); // seed the generator
            std::uniform_int_distribution<> distr(0, 12); // define the range



            enemySpawnCooldown = 120;
            enemySpawnTickCounter = 0;
            int m = 0;
            while(enemy[m]->inUse == true && m <= EntityLimits::MaxEnemies){
                m++;
            }
            

            int enemyDistance = dist;
            enemy[m]->rect.x = 100+(55*distr(gen));
            enemy[m]->inUse = true;
            std::cout<<"enemy spawned!\n"<<enemy[m]->rect.x<<"\n";
            
            dist++;
            if(dist>4) dist = 0;
        }
        
        enemySpawnTickCounter++;
        tickCounter++;
        
        if(tickCounter == 60){
            cooldownSatisfied = true;
            tickCounter = 0;
        }

        if(newProjectile && !cooldownSatisfied){
            newProjectile=false;
        }
        if(newProjectile && cooldownSatisfied){
            int m;
            for(m=0;m<EntityLimits::MaxEnemies;m++){
                if(projectile[m]->inUse == false){
                    projectile[m]->inUse = true;
                    cooldownSatisfied = false;
                    projectile[m]->constAngle = turret.angle;
                    projectile[m]->angle = turret.angle;
                    break;
                }
            }
            newProjectile = false;
        }

        entityAngle += 3;

        //*********************************
        //      Rendering all stuff
        //*********************************

        //Particles
        for(i=0;i<PARTICLE_COUNT;i++){
            if(particle[i]->inUse){
                particle[i]->move();
                particle[i]->render(*window.renderer, explosionTexture);
            }
        }

        //Projectiles
        for(int n = 0; n < EntityLimits::MaxProjectiles; n++){
            for(int m = 0; m < EntityLimits::MaxEnemies; m++){
                if(projectile[n]->inUse && enemy[m]->inUse){
                
                    projectile[n]->render(*window.renderer, healthTexture);
                    projectile[n]->move();
                    
                    if(projectile[n]->collisionCheck(enemy[m]->rect)){
                        std::cout<<"Collided!\n";
                        enemy[m]->inUse = false;
            

                    

                        int i;
                        for(i=0;i<PARTICLE_COUNT;i++){
                            particle[i]->rect.x = projectile[n]->rect.x;
                            particle[i]->rect.y = projectile[n]->rect.y;
                            particle[i]->inUse = true;
                            particle[i]->constAngle = (i*40);
                        }

                        projectile[n]->inUse = false;
                        projectile[n]->rect.x = TURRET_POSX;
                        projectile[n]->rect.y = TURRET_POSY;
                    }
                }
            }
        }

        //Enemies
        for(int m=0; m<=EntityLimits::MaxEnemies; m++){
            if(enemy[m]->inUse == true){
                enemy[m]->render(*window.renderer, entityTexture);
            }
        }
        
        //Health hearts
        for(int i=0; i<hpLeft; i++){
            SDL_RenderCopy(window.renderer, healthTexture, NULL, &heart.rect);
            heart.rect.x += HEART_DISTANCE;
        }

        SDL_RenderCopy(window.renderer, bgTexture, NULL, &bgRect);
        turret.render(*window.renderer, turretTexture);
        




        window.update();
        xMove = 0;
        yMove = 0;
        heart.reset();
        //Calculate elapsed time
        window.timestep(currTime, startTime, lastFrameTime, TimeConstants::DTIME);
    }
    window.gameOver();
    SDL_Quit();

    return 0;
}