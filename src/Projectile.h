#pragma once
#include "Entity.h"
class Projectile :
    public Entity
{
public:
    Projectile(BaseEngine* pEngine, int x, int y, double dir, PsyhqTileManager* manager)
        :Entity(pEngine, x, y, manager)
    {
        xOrigin = x;
        yOrigin = y;
        angle = dir;
        m_iCurrentScreenX = x;
        m_iCurrentScreenY = y;
    }

protected:
    double xOrigin, yOrigin;  // Holds the coordinates of where the projectile is spawned
    double angle;  // Holds the angle of the direction of projectile
    SimpleImage image; // Sprite of projectile 
    double nx, ny; // Holds the x and y axis location of the angle the projectile needs to be moved
    double distance; // Distance from the origin of projectile
    double speed, range, damage; // Basic attributes of the projectile
    void move();
};

