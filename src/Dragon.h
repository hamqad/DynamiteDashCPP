#pragma once
#include "Mob.h"
#include "Player1.h"
#include "Fireball.h"
class Dragon :
    public Mob
{
    
public:
    Dragon(BaseEngine* pEngine, int x, int y, PsyhqTileManager* manager)
        : Mob(pEngine, x, y, manager)
    {
        engine = (PsyhqEngine*)pEngine;
        setImage(image);
        m_iDrawWidth = 192; // Width of drawing area
        m_iDrawHeight = 144; // Height of drawing area
    }
private:
    SimpleImage wingUp = ImageManager::loadImage("res/textures/sprites/wingUp.png", true);
    SimpleImage wingDown = ImageManager::loadImage("res/textures/sprites/wingDown.png", true);
    SimpleImage shoot = ImageManager::loadImage("res/textures/sprites/shoot.png", true);
    AnimatedSprite* sprite = new AnimatedSprite(wingUp, wingDown, wingUp);

    SimpleImage currentImage = wingUp;
    
    int time = 0;
    int health = 300; // Dragons health
    int fireRate = 5; // Fire rate of the dragon
    int fireTracker = fireRate; // This tracks the current value of the fire delay
    int shots = 50; // How many shots the dragon shoots
    bool fire = false; // If the dragon has fired its shots
    bool move = false; // If the dragon still needs to move
    bool hurt = false; // If the dragon has been hurt
    bool firtHit = false, secondHit = false, thirdHit = false; // Holds weather the dragon has been hit and how many times
    int tileX; // The x tile position of the  dragon 
    int playerX, playerY; // The players positions in tiles
    // Each tile that the player will be hurt when the player enters:
    int x1 = 53, x2 = 54, x3 = 55;
    int y1 = 16, y2 = 17, y3 = 18;
    // The position of the dragons rendering:
    int xx = 1040;
    int yy = 272;
protected:
    void virtDoUpdate(int iCurrentTime);
    void damage(int i);
    void virtDraw();
    Player1* player;
    PsyhqEngine* engine;
};

