#pragma once
#include "Mob.h"
#include <list>
#include "Node.h"
#include "Player1.h"
class ChaserPro :
    public Mob
{
    SimpleImage image = ImageManager::loadImage("res/textures/sprites/chaser.png", true);
public:
    ChaserPro(BaseEngine* pEngine, int x, int y, PsyhqTileManager* manager)
        : Mob(pEngine, x, y, manager)
    {
        setImage(image);
        m_iDrawWidth = 32; // Width of drawing area
        m_iDrawHeight = 32; // Height of drawing area
    }
private:
    int health = 100;
    int frame = 0;
    bool reset = false;
    double xa = 0;
    double ya = 0;
    std::list<Node> path;
protected:
    void virtDoUpdate(int iCurrentTime);
    void damage(int i);
    void virtDraw();
    Player1* player;
};

