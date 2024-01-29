#pragma once
#include "Mob.h"
#include "PsyhqTileManager.h"
#include "Player1.h"

class Zombie :
    public Mob
{
public:
    Zombie(BaseEngine* pEngine, int x, int y, PsyhqTileManager* manager)
        : Mob(pEngine, x, y, manager)
    {
        engine = (PsyhqEngine*)pEngine;
        direction = -1;
        speed = 1;
        setImage(currentImage);
        m_iDrawWidth = 32; // Width of drawing area
        m_iDrawHeight = 32; // Height of drawing area
    }
public:
    SimpleImage zombieUpOne = ImageManager::loadImage("res/textures/sprites/zombieupone.png", true);
    SimpleImage zombieUpTwo = ImageManager::loadImage("res/textures/sprites/zombieuptwo.png", true);
    SimpleImage zombieUpThree = ImageManager::loadImage("res/textures/sprites/zombieupthree.png", true);
    AnimatedSprite* zombieUp = new AnimatedSprite(zombieUpOne, zombieUpTwo, zombieUpThree);

    SimpleImage zombieDownOne = ImageManager::loadImage("res/textures/sprites/zombiedownone.png", true);
    SimpleImage zombieDownTwo = ImageManager::loadImage("res/textures/sprites/zombiedowntwo.png", true);
    SimpleImage zombieDownThree = ImageManager::loadImage("res/textures/sprites/zombiedownthree.png", true);
    AnimatedSprite* zombieDown = new AnimatedSprite(zombieDownOne, zombieDownTwo, zombieDownThree);

    AnimatedSprite* currentSprite = zombieUp;
    SimpleImage currentImage = currentSprite->getSprite();

    void virtDraw();
    void virtDoUpdate(int iCurrentTime);
    void damage(int i);
    void move();
    int direction = 1;
    bool zombieCollision = true;
protected:
    PsyhqEngine* engine;
    Player1* player;


};

