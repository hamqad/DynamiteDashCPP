#pragma once
#include "PsyhqTileManager.h"
class LevelSix :
    public PsyhqTileManager
{
public:
    LevelSix(BaseEngine* engine, DrawingSurface* surface)
        : PsyhqTileManager(26, 24, engine, surface, "res/saves/levelsix.txt")
    {
        map = ImageManager::loadImage("res/levels/levelsix.png", true);
        load();
    }
};

