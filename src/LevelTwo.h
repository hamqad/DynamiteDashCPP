#include "PsyhqTileManager.h"
#pragma once
class LevelTwo :
    public PsyhqTileManager
{
public:
    LevelTwo(BaseEngine* engine, DrawingSurface* surface)
        : PsyhqTileManager(16, 5, engine, surface, "res/saves/leveltwo.txt")
    {
        map = ImageManager::loadImage("res/levels/leveltwo.png", true);
        load();
    }
};

