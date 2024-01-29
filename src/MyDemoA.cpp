#include "header.h"
#include "MyDemoA.h"
#include "MyTileManager.h"
#include "ImageManager.h"
#include "MyObjectB.h" // This is the new line!

void MyDemoA::virtSetupBackgroundBuffer() {

	fillBackground(0xff66ff);
	// get size of window given
	for (int iX = 0; iX < getWindowWidth(); iX++)
		for (int iY = 0; iY < this->getWindowHeight(); iY++)

			// take random number 
			switch (rand() % 100) {

				// for each pixel, do one of the 5 cases and fill the pixel that colour
			case 0: setBackgroundPixel(iX, iY, 0xFF0000); break;
			case 1: setBackgroundPixel(iX, iY, 0x00FF00); break;
			case 2: setBackgroundPixel(iX, iY, 0x0000FF); break;
			case 3: setBackgroundPixel(iX, iY, 0xFFFF00); break;
			case 4: setBackgroundPixel(iX, iY, 0x00FFFF); break;
			case 5: setBackgroundPixel(iX, iY, 0xFF00FF); break;
			}

	SimpleImage image = ImageManager::loadImage("./box.png", true);
	image.renderImage(getBackgroundSurface(), 0, 0, 10, 10,
		image.getWidth(), image.getHeight());

	// where we draw the background
	// displaying the tiles 

	/*
	* sets the tiles to random values
	  then it tells the tile manager where the top left corner of the tiles is (so it knows where to draw them).
	  i.e. you can provide a border before getting to the tiles.

	  then we draw all the tiles
	*/

	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
			tm.setMapValue(i, j, rand());

	// where to start drawing from
	tm.setTopLeftPositionOnScreen(50, 50);
	tm.drawAllTiles(this, getBackgroundSurface());


}


void MyDemoA::virtMouseDown(int iButton, int iX, int iY) {

	//The first line will cause some debug info to go to the output, so you can see what the x and y coordinates were for he click
	printf("Mouse clicked at %d %d\n", iX, iY);

	//Then the if statement verifies that it was the left mouse button that was clicked.
	if (iButton == SDL_BUTTON_LEFT)
	{
		//lockBackgroundForDrawing();
		//drawBackgroundRectangle(iX - 10, iY - 10, iX + 10, iY + 10, 0xff0000);

		// The redrawDisplay() function is important because it is the way that you tell SDL that something changed.
		//unlockBackgroundForDrawing();
		//redrawDisplay(); // Force background to be redrawn to foreground

		if (tm.isValidTilePosition(iX, iY)) // Clicked within tiles?
		{
			int mapX = tm.getMapXForScreenX(iX); // Which column?
			int mapY = tm.getMapYForScreenY(iY); // Which row?
			int value = tm.getMapValue(mapX, mapY); // Current value?
			tm.setAndRedrawMapValueAt(mapX, mapY, value + rand(), this, getBackgroundSurface());
			redrawDisplay(); // Force background to be redrawn to foreground
		}

	}
	else if (iButton == SDL_BUTTON_RIGHT) {

		//lockBackgroundForDrawing();
		//drawBackgroundOval(iX - 10, iY - 10, iX + 10, iY + 10, 0x0000ff);
		//unlockBackgroundForDrawing();
		//redrawDisplay(); // Force background to be redrawn to foreground

		if (tm.isValidTilePosition(iX, iY)) // Clicked within tiles?
		{
			int mapX = tm.getMapXForScreenX(iX); // Which column?
			int mapY = tm.getMapYForScreenY(iY); // Which row?
			int value = tm.getMapValue(mapX, mapY); // Current value?
			tm.setAndRedrawMapValueAt(mapX, mapY, value + rand(), this, getBackgroundSurface());
			redrawDisplay(); // Force background to be redrawn to foreground
		}

	}
}

void MyDemoA::virtKeyDown(int iKeyCode)
{
	switch (iKeyCode)
	{
	case SDLK_SPACE:
		lockBackgroundForDrawing();
		virtSetupBackgroundBuffer();
		unlockBackgroundForDrawing();
		redrawDisplay();
		break;
	}
}

//void ArmanDemoA::MyTileManager()
//{

//}

// If you do not put objects in the array, they will not be asked to update
// themselves and will not be drawn!

// records you have changed the drawable objects array
// then checks current objects in array and deletes them
// sets elements to point ot nerw objects of correct type 
// finally sets all objects to visible
int MyDemoA::virtInitialiseObjects()
{
	// Record the fact that we are about to change the array
	// so it doesn't get used elsewhere without reloading it
	drawableObjectsChanged();
	// Destroy any existing objects
	destroyOldObjects(true);
	// Creates static sized array big enough for the number of objects that you want.
	createObjectArray(1);
	// You MUST set the array entry after the last one that you create to NULL,
	// so that the system knows when to stop.
	storeObjectInArray(0, new MyObjectB(this));
	// NOTE: We also need to destroy the objects, but the method at the
	// top of this function will destroy all objects pointed at by the
	// array elements so we can ignore that here.
	setAllObjectsVisible(true);
	return 0;
}