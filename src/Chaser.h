#pragma once
#include "Mob.h"
#include "Player1.h"
class Chaser :
    public Mob
{
public:
    SimpleImage image = ImageManager::loadImage("res/textures/sprites/Dummy.png", true);
    PsyhqEngine* engine;
    Chaser(BaseEngine* pEngine, int x, int y, PsyhqTileManager* manager)
        : Mob(pEngine, x, y, manager)
    {
        engine = (PsyhqEngine*)getEngine();
        setImage(currentImage);
        m_iDrawWidth = 32; // Width of drawing area
        m_iDrawHeight = 32; // Height of drawing area
    }
protected:
    SimpleImage chaserUpOne = ImageManager::loadImage("res/textures/sprites/dummyupone.png", true);
    SimpleImage chaserUpTwo = ImageManager::loadImage("res/textures/sprites/dummyuptwo.png", true);
    SimpleImage chaserUpThree = ImageManager::loadImage("res/textures/sprites/dummyupthree.png", true);
    AnimatedSprite* chaserUp = new AnimatedSprite(chaserUpOne, chaserUpTwo, chaserUpThree);

    SimpleImage chaserDownOne = ImageManager::loadImage("res/textures/sprites/dummydownone.png", true);
    SimpleImage chaserDownTwo = ImageManager::loadImage("res/textures/sprites/dummydowntwo.png", true);
    SimpleImage chaserDownThree = ImageManager::loadImage("res/textures/sprites/dummydownthree.png", true);
    AnimatedSprite* chaserDown = new AnimatedSprite(chaserDownOne, chaserDownTwo, chaserDownThree);

    SimpleImage chaserLeftOne = ImageManager::loadImage("res/textures/sprites/dummyleftone.png", true);
    SimpleImage chaserLeftTwo = ImageManager::loadImage("res/textures/sprites/dummylefttwo.png", true);
    SimpleImage chaserLeftThree = ImageManager::loadImage("res/textures/sprites/dummyleftthree.png", true);
    AnimatedSprite* chaserLeft = new AnimatedSprite(chaserLeftOne, chaserLeftTwo, chaserLeftThree);

    SimpleImage chaserRightOne = ImageManager::loadImage("res/textures/sprites/dummyrightone.png", true);
    SimpleImage chaserRightTwo = ImageManager::loadImage("res/textures/sprites/dummyrighttwo.png", true);
    SimpleImage chaserRightThree = ImageManager::loadImage("res/textures/sprites/dummyrightthree.png", true);
    AnimatedSprite* chaserRight = new AnimatedSprite(chaserRightOne, chaserRightTwo, chaserRightThree);

    AnimatedSprite* currentSprite = chaserUp;
    SimpleImage currentImage = currentSprite->getSprite();

    void move();
    void virtDoUpdate(int iCurrentTime);
    void damage(int i);
    void virtDraw();
public:
    int health = 100;
private:
    double xa = 0;
    double ya = 0;
    double speed = 1;
    bool reset = false;
};

