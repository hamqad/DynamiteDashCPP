#pragma once
#include "PsyhqTileManager.h"
class LevelThree :
    public PsyhqTileManager
{
public:
    LevelThree(BaseEngine* engine, DrawingSurface* surface)
        : PsyhqTileManager(16, 5, engine, surface, "res/saves/levelthree.txt")
    {
        map = ImageManager::loadImage("res/levels/levelthree.png", true);
        load();
    }
};

