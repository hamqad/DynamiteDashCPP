#pragma once
#include "Tile.h"
class StoneWallTile :
    public Tile
{
public:
    StoneWallTile(int x, int y) :
        Tile(x, y)
    {
        value = 2;
        image = ImageManager::loadImage("res/textures/sprites/stone.png", true);
    }
};

