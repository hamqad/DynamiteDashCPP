#pragma once
#include "Mob.h"
#include "Player1.h"
class Dummy :
    public Mob
{
    SimpleImage image = ImageManager::loadImage("res/textures/sprites/dummy.png", true);
public:
    Dummy(BaseEngine* pEngine, int x, int y, PsyhqTileManager* manager)
        : Mob(pEngine, x, y, manager)
    {
        setImage(image);
        m_iDrawWidth = 32; // Width of drawing area
        m_iDrawHeight = 32; // Height of drawing area
    }

    SimpleImage dummyUpOne = ImageManager::loadImage("res/textures/sprites/dummyupone.png", true);
    SimpleImage dummyUpTwo = ImageManager::loadImage("res/textures/sprites/dummyuptwo.png", true);
    SimpleImage dummyUpThree = ImageManager::loadImage("res/textures/sprites/dummyupthree.png", true);
    AnimatedSprite* dummyUp = new AnimatedSprite(dummyUpOne, dummyUpTwo, dummyUpThree);

    SimpleImage dummyDownOne = ImageManager::loadImage("res/textures/sprites/dummydownone.png", true);
    SimpleImage dummyDownTwo = ImageManager::loadImage("res/textures/sprites/dummydowntwo.png", true);
    SimpleImage dummyDownThree = ImageManager::loadImage("res/textures/sprites/dummydownthree.png", true);
    AnimatedSprite* dummyDown = new AnimatedSprite(dummyDownOne, dummyDownTwo, dummyDownThree);

    SimpleImage dummyLeftOne = ImageManager::loadImage("res/textures/sprites/dummyleftone.png", true);
    SimpleImage dummyLeftTwo = ImageManager::loadImage("res/textures/sprites/dummylefttwo.png", true);
    SimpleImage dummyLeftThree = ImageManager::loadImage("res/textures/sprites/dummyleftthree.png", true);
    AnimatedSprite* dummyLeft = new AnimatedSprite(dummyLeftOne, dummyLeftTwo, dummyLeftThree);

    SimpleImage dummyRightOne = ImageManager::loadImage("res/textures/sprites/dummyrightone.png", true);
    SimpleImage dummyRightTwo = ImageManager::loadImage("res/textures/sprites/dummyrighttwo.png", true);
    SimpleImage dummyRightThree = ImageManager::loadImage("res/textures/sprites/dummyrightthree.png", true);
    AnimatedSprite* dummyRight = new AnimatedSprite(dummyRightOne, dummyRightTwo, dummyRightThree);

    AnimatedSprite* currentSprite = dummyUp;
    SimpleImage currentImage = currentSprite->getSprite();

private:
    int health = 100;
    bool reset = false;
    double xa = 0;
    double ya = 0;
    int time = 0;
protected:
    void virtDoUpdate(int iCurrentTime);
    void damage(int i);
    void virtDraw();
    Player1* player;
};

