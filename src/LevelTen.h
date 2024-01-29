#pragma once
#include "PsyhqTileManager.h"
class LevelTen :
    public PsyhqTileManager
{
public:
    LevelTen(BaseEngine* engine, DrawingSurface* surface)
        : PsyhqTileManager(62, 35, engine, surface, "res/saves/levelten.txt")
    {
        map = ImageManager::loadImage("res/levels/levelten.png", true);
        load();
    }
};

