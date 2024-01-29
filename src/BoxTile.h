#pragma once
#include "Tile.h"
class BoxTile :
    public Tile
{
public:
    BoxTile(int x, int y) :
        Tile(x, y)
    {
        value = 3;
        image = ImageManager::loadImage("res/textures/sprites/box.png", true);
    }
};

