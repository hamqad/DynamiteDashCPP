#include "header.h"
#include "Dynamite.h"
#include "Explosion.h"

void Dynamite::virtDoUpdate(int iCurrentTime)
{
	time++; // Increments the time
	if (time % 20 == 0) { // Toggles between the first two frames of the animation 3 times a second
		if (detonateCheck == false) {
			if (frameTracker) {
				dynamiteSprite->setFrame(0);
				frameTracker = false;
			}
			else {
				dynamiteSprite->setFrame(1);
				frameTracker = true;
			}
		}
		finishAnimation(); // Finishes the animation of the dynamite if its time to detonate
	}

	if (time % 60 == 0) {  // Updates the real time in seconds based on the time variable and finishes the dynamite animation if its time to detonate
		realTime++;
	}
	if (realTime >= detonateTime) { // If its time to detonate, set the detonate checker to true
		detonateCheck = true;
	}

}

void Dynamite::finishAnimation()
{
	currentSprite = exploadSprite;
	if(detonateCheck) { // If its time to detonate
		if (frame != 3) {
			frame++; // Go to the next frame if the last frame hasnt been reached
			exploadSprite->setFrame(frame); // Sets the animation to the frame
		}
		if (frame == 3) { // If the last frame has been reached, wait a second and remove the dynamite
			expload(); // Cause an explosion effect
			removed = true;
			engine->removeEntity(this);
		}
	}
}

void Dynamite::virtDraw() 
{
	currentImage = currentSprite->getSprite();
	currentImage.renderImageWithMask(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY,
		currentImage.getWidth(), currentImage.getHeight());
}

void Dynamite::expload() 
{
	int tile;
	// Spawns particles on the dyanmite's explosion location:
	if (!exploded) engine->addEntity(new Explosion(engine, m_iCurrentScreenX, m_iCurrentScreenY, manager));
	if (range == 2) { // If the players dynamite range is 2 

		// One tile to the left of the dynamite:

		// If the tile at the required explosions location is breakable or not solid, create an explosion at that position
		if (!exploded) {
			tile = getTile(m_iCurrentScreenX - 32, m_iCurrentScreenY);
			if (tile != 2 && tile != 3) {
				engine->addEntity(new Explosion(engine, m_iCurrentScreenX - 32, m_iCurrentScreenY, manager));
			}
			else if (tile == 3) {
				engine->addEntity(new Explosion(engine, m_iCurrentScreenX - 32, m_iCurrentScreenY, manager));
				setBox(m_iCurrentScreenX - 32, m_iCurrentScreenY);// Set the tile of the breakable tile to grass when exploded
			}

			// One tile to the right of the dynamite:
			tile = getTile(m_iCurrentScreenX + 32, m_iCurrentScreenY);
			if (tile != 2 && tile != 3) {
				engine->addEntity(new Explosion(engine, m_iCurrentScreenX + 32, m_iCurrentScreenY, manager));
			}
			else if (tile == 3) {
				engine->addEntity(new Explosion(engine, m_iCurrentScreenX + 32, m_iCurrentScreenY, manager));
				setBox(m_iCurrentScreenX + 32, m_iCurrentScreenY);
			}


			// One tile under the dynamite:
			tile = getTile(m_iCurrentScreenX, m_iCurrentScreenY + 32);
			if (tile != 2 && tile != 3) {
				engine->addEntity(new Explosion(engine, m_iCurrentScreenX, m_iCurrentScreenY + 32, manager));
			}
			else if (tile == 3) {
				engine->addEntity(new Explosion(engine, m_iCurrentScreenX, m_iCurrentScreenY + 32, manager));
				setBox(m_iCurrentScreenX, m_iCurrentScreenY + 32);
			}


			// One tile on top of the dynamite:
			tile = getTile(m_iCurrentScreenX, m_iCurrentScreenY - 32);
			if (tile != 2 && tile != 3) {
				engine->addEntity(new Explosion(engine, m_iCurrentScreenX, m_iCurrentScreenY - 32, manager));
			}
			else if (tile == 3) {
				engine->addEntity(new Explosion(engine, m_iCurrentScreenX, m_iCurrentScreenY - 32, manager));
				setBox(m_iCurrentScreenX, m_iCurrentScreenY - 32);
			}
		}
	}
		exploded = true;
		player->dynamiteNumber++;
}

int Dynamite::getTile(int x, int y) {
	if (manager->isValidTilePosition(x, y))
	{
		int iTileX = manager->getMapXForScreenX(x);
		int iTileY = manager->getMapYForScreenY(y);
		return manager->getMapValue(iTileX, iTileY);
	}
	return 123;
}

void Dynamite::setBox(int x, int y) {
	int iTileX = manager->getMapXForScreenX(x);
	int iTileY = manager->getMapYForScreenY(y);
	manager->setAndRedrawMapValueAt(iTileX, iTileY, 1, getEngine(), getEngine()->getBackgroundSurface());// Set the tile of the breakable tile to grass when exploded

}

