#pragma once
#include "Tile.h"
class ButtonTile :
    public Tile
{
public:
    ButtonTile(int x, int y) :
        Tile(x, y)
    {
        value = 6;
        image = ImageManager::loadImage("res/textures/sprites/button.png", true);
    }
};

