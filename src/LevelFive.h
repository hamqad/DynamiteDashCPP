#pragma once
#include "PsyhqTileManager.h"
class LevelFive :
    public PsyhqTileManager
{
public:
    LevelFive(BaseEngine* engine, DrawingSurface* surface)
        : PsyhqTileManager(22, 20, engine, surface, "res/saves/levelfive.txt")
    {
        map = ImageManager::loadImage("res/levels/levelfive.png", true);
        load();
    }
};

