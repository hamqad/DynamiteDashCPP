#pragma once
#include "Entity.h"
#include "AnimatedSprite.h"
class Mob :
    public Entity
{
public:
    Mob(BaseEngine* pEngine, int x, int y, PsyhqTileManager* manager)
        : Entity(pEngine, x, y, manager)
    {
        
    }

public:
    int dir = 0;
    int health = 100;
protected:
    int speed;
    bool moving = false;
    bool walking = false;

public:
    void virtDoUpdate(int iCurrentTime);
    void moveMe(double xa, double ya);
    int abs(double value);
    void damage(int i);
    bool collision(double xa, double ya);
    void deductHealth(int x, int y, int iDamage);
   
};




