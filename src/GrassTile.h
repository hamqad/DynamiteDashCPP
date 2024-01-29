#pragma once
#include "Tile.h"
class GrassTile :
    public Tile
{
public:
    GrassTile(int x, int y) :
        Tile(x, y)
    {
        image = ImageManager::loadImage("res/textures/sprites/grass.png", true);
        value = 1;
    }
};

