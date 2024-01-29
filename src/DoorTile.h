#pragma once
#include "Tile.h"
class DoorTile :
    public Tile
{
public:
    DoorTile(int x, int y) :
        Tile(x, y)
    {
        value = 5;
        image = ImageManager::loadImage("res/textures/sprites/door.png", true);
    }
};

