#include "header.h"
#include "PsyhqTileManager.h"


//Draws a tile at the specified position on the screen
void PsyhqTileManager::virtDrawTileAt(
	BaseEngine* pEngine,
	DrawingSurface* pSurface,
	int iMapX, int iMapY,
	int iStartPositionScreenX, int iStartPositionScreenY) const
{
	SimpleImage currentTile; // Current tile for the loop

	//Gets the value of the tile at current position
	int iMapValue = getMapValue(iMapX, iMapY);
	
	//Sets the image of the tile depending on the tiles value
	switch (iMapValue) {
		case 1: currentTile = grass; break;
		case 2: currentTile = stoneWall; break;
		case 3: currentTile = box; break;
		case 4: currentTile = stoneFloor; break;
		case 5: currentTile = door; break;
		case 6: currentTile = button; break;
		
		default: currentTile = grass;
	}
	
	// Draws the tile to the screen at the correct position
	currentTile.renderImageWithMask(pEngine->getBackgroundSurface(), 0, 0, iStartPositionScreenX, iStartPositionScreenY,
		currentTile.getWidth(), currentTile.getHeight(), 16711896);
		
}

// Loads a level from an image by looping through the images pixels, and depending on the colour of the pixel, sets the tiles value
void PsyhqTileManager::load() {
	
	for (int w = 0; w < map.getWidth(); w++) {
		for (int h = 0; h < map.getHeight(); h++) {
			switch (map.getPixelColour(w, h)){
				case 9013122: 
					currentTile = new StoneWallTile(w,h); 
					setMapValue(w, h, currentTile->getValue()); 
					break;
				case 4950826:
					currentTile = new GrassTile(w,h);
					setMapValue(w, h, currentTile->getValue()); 
					break;
				case 11500342: 
					currentTile = new BoxTile(w,h);
					setMapValue(w, h, currentTile->getValue()); 
					break;
				case 10526360:
					currentTile = new StoneFloorTile(w,h);
					setMapValue(w, h, currentTile->getValue()); 
					break;
				case 16771899:
					currentTile = new ButtonTile(w,h);
					setMapValue(w, h, currentTile->getValue());
					break;
				case 7951688:
					currentTile = new GrassTile(w,h);
					setMapValue(w, h, currentTile->getValue());
					doorX = w;
					doorY = h;
					break;
			    default:	   
					currentTile = new GrassTile(w,h);
					setMapValue(w, h, currentTile->getValue());
					break;
			}
		}
	}
}

// Changes a grass tile to a door tile depending on the preset door position
void PsyhqTileManager::spawnDoor() {
	surface->mySDLLockSurface();
	if (!spawned) {
		
		currentTile = new DoorTile(doorX, doorY);
		setMapValue(doorX, doorY, currentTile->getValue());
		drawAllTiles(engine, engine->getBackgroundSurface());
		spawned = true;
		
	}
	surface->mySDLUnlockSurface();
}

int PsyhqTileManager::getStartX() {
	return m_iBaseScreenX;
}

int PsyhqTileManager::getStartY() {
	return m_iBaseScreenY;
}

// Loops through the current levels map and saves the values to a file
void PsyhqTileManager::saveLevel() {
	//printf(path);
	std::ofstream file(path);
	for (int y = 0; y < width; y++) {
		for (int x = 0; x < height; x++)
		{
			file << getMapValue(y, x) << " ";
		}
	}
	file.close();
}

// Loops through the current values in a file and draws the tiles in the corresponding places
void PsyhqTileManager::loadLevel() {
	printf(path);
	std::ifstream file(path);
	int value;

	if (!file.is_open()) {
		return;
	}
		
	for (int y = 0; y < width; y++) {
		for (int x = 0; x < height; x++)
		{
			file >> value;
			setMapValue(y, x, value);
		}
	}

	file.close();
	drawAllTiles(engine, engine->getBackgroundSurface());
}

void PsyhqTileManager::setPath(char* iPath) {
	path = iPath;
}



