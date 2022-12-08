#include <iostream>
#include <SDL2/SDL.h>
#include <cstdlib>
#include "Screen.h"
#include "Entity.h"
#include "health.h"
#include "enemy.h"
#include "projectile.h"
#include "timer.h"
#include "constants.hpp"
#include <random>
#include <vector>
#include <algorithm>


#define FROG_DISTANCE 80
#define HEART_DISTANCE 30
#define HEART_DISTANCE_BOTTOM 90
#define PARTICLE_COUNT 10

#define TURRET_POSX WindowConstants::Width/2
#define TURRET_POSY WindowConstants::Height-140


using namespace std;


int getRandom(){
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 12); // define the range

    return 55*distr(gen);
}

int main( int argc, char *argv[] ){

    int i;

    SDL_Init(SDL_INIT_EVERYTHING);

    Screen window(WindowConstants::Width,WindowConstants::Height);
    Health heart(WindowConstants::Height, HEART_DISTANCE_BOTTOM);
    Entity turret(2, TURRET_POSX, TURRET_POSY, 0);

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
    int hpLeft = 5;

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


    vector<Enemy> enemies;
    vector<Projectile> projectiles;

    while(quit != 1){
        lastFrameTime = SDL_GetTicks();
        
        //Heavy-on-time stuff here
        SDL_SetRenderDrawColor(window.renderer, 158,132,146,1);
        window.clean();
        float modTurretAngle;
        window.keyState(&quit, &hpLeft, &xMove, &yMove, &turret.angle, &newProjectile, &turret, TimeConstants::DTIME, &modTurretAngle);
        turret.angle = modTurretAngle;

        if(enemySpawnTickCounter == EntityLimits::EnemySpawnCooldown){
            
            
            
            enemySpawnCooldown = 120;
            enemySpawnTickCounter = 0;

            int enemyDistance = dist;
            
            //================================================
            //          New way of creating objects
            //                using vectors
            //================================================

            Enemy enemy_tmp;
            int displacement = 100+getRandom();
            int passable = false;
            int iteration = 0;
            while(!passable){
                passable = true;
                for (auto &enems : enemies){
                    if(enems.rect.x == displacement){
                        displacement = 100+getRandom();
                        passable = false;
                    }
                }
                if(iteration >= 10){
                    passable = true;
                }
                iteration++;
            }

            enemy_tmp.rect.x = displacement;
            
            enemies.push_back(enemy_tmp);
            std::cout<<"enemy spawned!\n"<<enemies.back().rect.x<<"\n";
            
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

            Projectile projectile_tmp;
            projectile_tmp.constAngle = turret.angle;
            projectile_tmp.angle = turret.angle;
            
            projectiles.push_back(projectile_tmp);

            cooldownSatisfied = false;
            newProjectile = false;
            std::cout<<"Projectile produced!\n";
        }

        entityAngle += 3;


        int projs_idx=0;

        SDL_RenderCopy(window.renderer, bgTexture, NULL, &bgRect);
        turret.render(*window.renderer, turretTexture);

        for (auto &projs : projectiles){

            projs.move();

            int enems_idx = 0;
            //for (auto &enems : enemies){
                
                /*if(projs.collisionCheck(enems.rect))
                    std::cout<<"Collided!\n";

                    enemies.erase(enemies.begin()+enems_idx)+1;
                    projectiles.erase(projectiles.begin()+projs_idx+1);

                    enems_idx++;
                    break;
            }*/
            projs_idx++;
        }

        //*********************************
        //      Rendering all stuff
        //*********************************

        for(i=0;i<PARTICLE_COUNT;i++){
            if(particle[i]->inUse){
                particle[i]->move();
                particle[i]->render(*window.renderer, explosionTexture);
            }
        }

        /*
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
        }*/

        //================================================
        //          New way of rendering using vectors
        //================================================

        

        for (auto &enems : enemies){
            enems.render(*window.renderer, entityTexture);
        }

        for(int i=0; i<hpLeft; i++){
            SDL_RenderCopy(window.renderer, healthTexture, NULL, &heart.rect);
            heart.rect.x += HEART_DISTANCE;
        }

        for (auto &projs : projectiles){
            projs.render(*window.renderer, healthTexture);
        }


        window.update();
        xMove = 0;
        yMove = 0;
        heart.reset();
        std::cout<<turret.angle<<"\n";
        window.timestep(currTime, startTime, lastFrameTime, TimeConstants::DTIME);
    }

    std::cout<<"quitting!\n";

    window.gameOver();
    SDL_Quit();

    return 0;
}