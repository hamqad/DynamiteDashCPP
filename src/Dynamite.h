#pragma once
#include "Entity.h"
#include "PsyhqTileManager.h"
#include "Player.h"
#include "PsyhqEngine.h"
#include <math.h>  
class Dynamite :
    public Entity
{
public:
    Dynamite(BaseEngine* pEngine, int x, int y, int iDetonateTime, int iRange, PsyhqTileManager* pManager, Player* iPlayer)
        : Entity(pEngine, x, y, manager)
    {
        manager = pManager;
        player = iPlayer;
        detonateTime = iDetonateTime;
        range = iRange;
        setImage(ImageManager::loadImage("res/textures/sprites/Dynamite1.png", true));
        engine = (PsyhqEngine*)getEngine();
        m_iCurrentScreenX = ((pManager->getMapXForScreenX(x + 16)) * 32) + pManager->getStartX();
        m_iCurrentScreenY = ((pManager->getMapYForScreenY(y - 16)) * 32) + 32 + pManager->getStartY();
    }

private:
    SimpleImage dynamite1 = ImageManager::loadImage("res/textures/sprites/Dynamite1.png", true);
    SimpleImage dynamite2 = ImageManager::loadImage("res/textures/sprites/Dynamite2.png", true);
    SimpleImage dynamite3 = ImageManager::loadImage("res/textures/sprites/Dynamite3.png", true);
    SimpleImage dynamite4 = ImageManager::loadImage("res/textures/sprites/Dynamite4.png", true);
    SimpleImage dynamite5 = ImageManager::loadImage("res/textures/sprites/Dynamite5.png", true);

    AnimatedSprite* dynamiteSprite = new AnimatedSprite(dynamite1, dynamite2, dynamite1);
    AnimatedSprite* exploadSprite = new AnimatedSprite(dynamite3, dynamite4, dynamite5);
    
    AnimatedSprite* currentSprite = dynamiteSprite;
    SimpleImage currentImage;

    PsyhqEngine* engine;
    PsyhqTileManager* manager;
    Player* player;
    int detonateTime;
    int realTime = 0;
    int time = 0;
    bool frameTracker = true;
    bool detonateCheck = false;
    int frame = 0;
    int range;
    bool collideX0, collideX1, collideY0, collideY1;
    bool exploded = false;

public:
    void expload();
    void finishAnimation();
protected:
    void virtDoUpdate(int iCurrentTime);
    void virtDraw();
    int getTile(int x, int y);
    void setBox(int x, int y);
};

