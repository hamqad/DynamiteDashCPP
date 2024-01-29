#pragma once
#include "Player.h"
#include "Dynamite.h"
#include "PsyhqTileManager.h"
#include "LevelOne.h"
#include "PsyhqEngine.h"

class Player1 :
    public Player
{
public:
    Player1(BaseEngine* pEngine, int x, int y, PsyhqTileManager* manager)
        : Player(pEngine, x, y, manager)
    {
        engine = (PsyhqEngine*)pEngine;
        setImage(currentImage);
        m_iCurrentScreenX = x; // Starting position on the screen
        m_iCurrentScreenY = y;
        m_iDrawWidth = 32; // Width of drawing area
        m_iDrawHeight = 32; // Height ob drawing area
    }
public:
    SimpleImage playerUpOne = ImageManager::loadImage("res/textures/sprites/player1upone.png", true);
    SimpleImage playerUpTwo = ImageManager::loadImage("res/textures/sprites/player1uptwo.png", true);
    SimpleImage playerUpThree = ImageManager::loadImage("res/textures/sprites/player1upthree.png", true);
    AnimatedSprite* playerUp = new AnimatedSprite(playerUpOne, playerUpTwo, playerUpThree);

    SimpleImage playerDownOne = ImageManager::loadImage("res/textures/sprites/player1downone.png", true);
    SimpleImage playerDownTwo = ImageManager::loadImage("res/textures/sprites/player1downtwo.png", true);
    SimpleImage playerDownThree = ImageManager::loadImage("res/textures/sprites/player1downthree.png", true);
    AnimatedSprite* playerDown = new AnimatedSprite(playerDownOne, playerDownTwo, playerDownThree);

    SimpleImage playerLeftOne = ImageManager::loadImage("res/textures/sprites/player1leftone.png", true);
    SimpleImage playerLeftTwo = ImageManager::loadImage("res/textures/sprites/player1lefttwo.png", true);
    SimpleImage playerLeftThree = ImageManager::loadImage("res/textures/sprites/player1leftthree.png", true);
    AnimatedSprite* playerLeft = new AnimatedSprite(playerLeftOne, playerLeftTwo, playerLeftThree);

    SimpleImage playerRightOne = ImageManager::loadImage("res/textures/sprites/player1rightone.png", true);
    SimpleImage playerRightTwo = ImageManager::loadImage("res/textures/sprites/player1righttwo.png", true);
    SimpleImage playerRightThree = ImageManager::loadImage("res/textures/sprites/player1rightthree.png", true);
    AnimatedSprite* playerRight = new AnimatedSprite(playerRightOne, playerRightTwo, playerRightThree);

    SimpleImage playerHurt = ImageManager::loadImage("res/textures/sprites/player1death.png", true);
    AnimatedSprite* hurt= new AnimatedSprite(playerHurt, playerHurt, playerHurt);

    AnimatedSprite* currentSprite = playerUp;
    SimpleImage currentImage = currentSprite->getSprite();

    bool playerCollision = false;
    bool placed = false;
    int time = 0;
    void damage(int d);
    void virtDraw();
    void virtDoUpdate(int iCurrentTime);
    void virtMouseDown(int iButton, int iX, int iY);
    void deductPlayerHealth(int x, int y, int damage);
    void updateDynamite();
protected:
    PsyhqEngine* engine;

};

