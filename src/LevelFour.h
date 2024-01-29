#pragma once
#include "PsyhqTileManager.h"
class LevelFour :
    public PsyhqTileManager
{
public:
    LevelFour(BaseEngine* engine, DrawingSurface* surface)
        : PsyhqTileManager(18, 17, engine, surface, "res/saves/levelfour.txt")
    {
        map = ImageManager::loadImage("res/levels/levelfour.png", true);
        load();
    }
};

