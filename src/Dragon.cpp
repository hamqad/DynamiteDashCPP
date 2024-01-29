#include "header.h"
#include "Dragon.h"

void Dragon::virtDoUpdate(int icurrenttime)
{
	time++;
	Mob::virtDoUpdate(icurrenttime);
	sprite->update();
	player = (Player1*)engine->getPlayer();
	player->deductPlayerHealth(getXCentre(), getYCentre(), 10);
	printf("Bool fire: %d, shots: %d\n", fire, shots);
	if (fire) {
		if (fireTracker > 0) fireTracker--; // Decreases the fire rate every update cycle
		if (fireTracker <= 0) {
			currentImage = shoot;
			engine->addEntity(new Fireball(engine, m_iCurrentScreenX, m_iCurrentScreenY, rand()%360, this, m_pTileManager));
			shots++;
			fireTracker = fireRate;
		}
	}
	if (shots >= 50) {
		fire = false;
		shots = 0;
	}
	if (fire == false && time % 200 == 0) {
		fire = true;
	}
}

void Dragon::damage(int i)
{

}

void Dragon::virtDraw()
{
	if (fire) {
		currentImage = shoot;
	}
	else {
		currentImage = sprite->getSprite();
	}
	
	currentImage.renderImageWithMask(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY,
		currentImage.getWidth(), currentImage.getHeight());
}