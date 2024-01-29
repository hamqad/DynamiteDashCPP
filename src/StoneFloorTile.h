#pragma once
#include "Tile.h"
class StoneFloorTile :
    public Tile
{
public:
    StoneFloorTile(int x, int y) :
        Tile(x, y)
    {
        value = 4;
        image = ImageManager::loadImage("res/textures/sprites/stonefloor.png", true);
    }
};

