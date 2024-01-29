#pragma once
#include "Mob.h"
//#include "Dynamite.h"
class Player :
    public Mob
{

public:
    int health = 100;
    int speed = 1;
    bool reset = false;
    double xa, ya;
    int range;
    int dynamiteNumber;
    int placeRate;
    int currentPlace;
    int detonateTime;
    int time;

    Player(BaseEngine* pEngine, int x, int y, PsyhqTileManager* manager)
        : Mob(pEngine, x, y, manager)
    {
        range = 2;
        dynamiteNumber = 1;
        placeRate = 100;
        currentPlace = placeRate;
        detonateTime = 2;

    }

protected:
    void virtDoUpdate(int iCurrentTime);
    void damage(int i);
    void virtDraw();
public:
    void deductPlayerHealth(int x, int y);
    void addHealth(int h);
};




