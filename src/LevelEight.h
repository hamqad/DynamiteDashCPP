#pragma once
#include "PsyhqTileManager.h"
class LevelEight :
    public PsyhqTileManager
{
public:
    LevelEight(BaseEngine* engine, DrawingSurface* surface)
        : PsyhqTileManager(32, 30, engine, surface, "res/saves/leveleight.txt")
    {
        map = ImageManager::loadImage("res/levels/leveleight.png", true);
        load();
    }
};

