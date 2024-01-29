#include "header.h"
#include "MyTileManager.h"

void MyTileManager::virtDrawTileAt(
	BaseEngine* pEngine, // We don't need this but maybe a student will so it is here to use if needed
	DrawingSurface* pSurface,
	int iMapX, int iMapY,
	int iStartPositionScreenX, int iStartPositionScreenY) const
{
	int iMapValue = getMapValue(iMapX, iMapY);
	unsigned int iColour = 0x101010 * ((iMapX + iMapY + iMapValue) % 16);
	pSurface->drawRectangle(
	iStartPositionScreenX,	// Left
	iStartPositionScreenY,	// Top
	iStartPositionScreenX + getTileWidth() - 1,		// Right
	iStartPositionScreenY + getTileHeight() - 1,	// Bottom
	iColour);	// Pixel colour
} 