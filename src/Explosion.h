#pragma once
#include "Entity.h"
#include "Player1.h"
#include "Dynamite.h"
#include <vector>

class Explosion :
    public Entity
{
public:
    Explosion(BaseEngine* pEngine, int x, int y, PsyhqTileManager* manager)
        : Entity(pEngine, x, y, manager)
    {
        engine = (PsyhqEngine*)pEngine;
        setImage(currentImage);
    }

    SimpleImage currentImage = ImageManager::loadImage("res/textures/sprites/Dynamite5.png", true);
    PsyhqEngine* engine;
    bool exploded = false;
protected:
    void virtDoUpdate(int iCurrentTime);
    void virtDraw();
    bool deductedPlayerHealth = false;
    bool deductedEnemyHealth = false;
    int time = 0;
    Player1* player;

};

