#pragma once
#include "Mob.h"
#include "Player1.h"
#include <math.h>
#include "Fireball.h"
class Shooter :
    public Mob
{
    SimpleImage image = ImageManager::loadImage("res/textures/sprites/ShooterRight.png", true);
public:
    Shooter(BaseEngine* pEngine, int x, int y, PsyhqTileManager* manager)
        : Mob(pEngine, x, y, manager)
    {
        engine = (PsyhqEngine*)pEngine;
        setImage(image);
        m_iDrawWidth = 32; // Width of drawing area
        m_iDrawHeight = 32; // Height of drawing area
    }
private:
    bool reset = false;
    int health = 100;
    double speed = 0.1;
    int fireRate = 100;
    int fireTracker = fireRate;
    int time = 0;
protected:
    void virtDoUpdate(int iCurrentTime);
    void damage(int i);
    void virtDraw();
    Player1* player;
    PsyhqEngine* engine;
};

