#pragma once
#include "Projectile.h"
#include <math.h>
#include "Mob.h"
#include "Player1.h"

class Fireball :
    public Projectile
{
public:
    Fireball(BaseEngine* pEngine, int x, int y, double dir, Mob* iMob, PsyhqTileManager* manager)
        : Projectile(pEngine, x, y, dir, manager)
    {
        mob = iMob;
        range = 1000;
        speed = 3;
        setImage(image); 
        nx =  speed * cos(angle);
        ny =  speed * sin(angle);
        engine = (PsyhqEngine*)pEngine;

    }

protected:
    Mob* mob; 
	int playerX, playerY, enemyX, enemyY, fireballX, fireballY; //Holds the x and y coordinates of the required entites
    
    bool deductedPlayerHealth = false; // Weather or not the fire ball has caused a decrease in the players health 
	bool deductedEnemyHealth = false; // Weather or not the fire ball has caused a decrease in the enemies health 

	int FIRE_RATE = 10;  // The time interval between each fire ball shot 
    SimpleImage image = ImageManager::loadImage("res/textures/sprites/fireball.png", true);
    PsyhqEngine* engine;
    void virtDoUpdate(int iCurrentTime);
    void virtDraw();
    void deductHealth();
    void move();
    double distance();
};

