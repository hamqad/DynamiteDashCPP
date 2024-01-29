#include "header.h"
#include "Explosion.h"

void Explosion::virtDoUpdate(int iCurrentTime) {
	time++;
	if (!deductedPlayerHealth) { // If the players health has not already been deducted
			player = (Player1*)engine->getPlayer();
			player->deductPlayerHealth(getXCentre(), getYCentre(), 50);
			deductedPlayerHealth = true;
	}
	
	if (!deductedEnemyHealth) {
		for (int i = 0; i < engine->getContentCount(); i++) {
			DisplayableObject* object = engine->getDisplayableObject(i);
			if ((dynamic_cast<Player1*>(object) == nullptr) && !(dynamic_cast<Mob*>(object) == nullptr)) {
				Mob* mob = (Mob*)object;
				mob->deductHealth(getXCentre(), getYCentre(), 100);
				deductedEnemyHealth = true;
			}
		}
	}
	if(time % 10 == 0) engine->removeEntity(this);


}

void Explosion::virtDraw() {
	currentImage.renderImageWithMask(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY,
		currentImage.getWidth(), currentImage.getHeight());
}