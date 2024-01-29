#pragma once
#include "TileManager.h"
#include "GrassTile.h"
#include "BoxTile.h"
#include "StoneWallTile.h"
#include "StoneFloorTile.h"
#include "DoorTile.h"
#include "ButtonTile.h"
#include <iostream>
#include <fstream>
#include <iostream>

class PsyhqTileManager :
    public TileManager
{
public:
	PsyhqTileManager(int iWidth, int iHeight, BaseEngine* pEngine, DrawingSurface* pSurface, char* iPath)
		: TileManager(32, 32, iWidth, iHeight)
	{
		path = iPath;
		width = iWidth;
		height = iHeight;
		engine = pEngine;
		surface = pSurface; 
	}

	virtual void virtDrawTileAt(
		BaseEngine* engine,
		DrawingSurface* surface,
		int iMapX, int iMapY,
		int iStartPositionScreenX, int iStartPositionScreenY) const override;

	SimpleImage map;
	void spawnDoor();
	int getStartX();
	int getStartY();
	BaseEngine* engine;
	DrawingSurface* surface;
	void saveLevel();
	void loadLevel();
	void setPath(char* iPath);
	char* path;

protected:
	int width, height;
	int startX, startY;
	int doorX;
	int doorY;
	bool spawned = false;
	void load();

	// The images of each tile
	SimpleImage grass = ImageManager::loadImage("res/textures/sprites/grass.png", true);
	SimpleImage stoneWall = ImageManager::loadImage("res/textures/sprites/stone.png", true);
	SimpleImage box = ImageManager::loadImage("res/textures/sprites/box.png", true);
	SimpleImage stoneFloor = ImageManager::loadImage("res/textures/sprites/stoneFloor.png", true);
	SimpleImage door = ImageManager::loadImage("res/textures/sprites/door.png", true);
	SimpleImage button = ImageManager::loadImage("res/textures/sprites/button.png", true);
	
	Tile* currentTile;
};

