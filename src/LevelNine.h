#pragma once
#include "PsyhqTileManager.h"
class LevelNine :
    public PsyhqTileManager
{
public:
    LevelNine(BaseEngine* engine, DrawingSurface* surface)
        : PsyhqTileManager(36, 34, engine, surface, "res/saves/levelnine.txt")
    {
        map = ImageManager::loadImage("res/levels/levelnine.png", true);
        load();
    }
};

