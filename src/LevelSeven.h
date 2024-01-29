#pragma once
#include "PsyhqTileManager.h"
class LevelSeven :
    public PsyhqTileManager
{
public:
    LevelSeven(BaseEngine* engine, DrawingSurface* surface)
        : PsyhqTileManager(30, 28, engine, surface, "res/saves/levelseven.txt")
    {
        map = ImageManager::loadImage("res/levels/levelseven.png", true);
        load();
    }
};

