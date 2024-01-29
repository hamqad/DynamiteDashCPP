#pragma once
#include "PsyhqTileManager.h"
class LevelOne 
	: public PsyhqTileManager
{
public:
    LevelOne(BaseEngine* engine, DrawingSurface* surface)
        : PsyhqTileManager(16, 5, engine, surface, "res/saves/levelone.txt")
    {
		map = ImageManager::loadImage("res/levels/levelone.png", true);
        load();
    }
};

