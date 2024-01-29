#include "header.h"
#include "Fireball.h"

void Fireball::virtDoUpdate(int iCurrentTime) {
	if (m_pTileManager->isValidTilePosition((int)(m_iCurrentScreenX+nx), (int)(m_iCurrentScreenY+ny)))
	{
		int iTileX = m_pTileManager->getMapXForScreenX(m_iCurrentScreenX);
		int iTileY = m_pTileManager->getMapYForScreenY(m_iCurrentScreenY);
		int value = m_pTileManager->getMapValue(iTileX, iTileY);
		if (value == 2 || value == 3) {
			engine->removeEntity(this);
		} 
	}
	move(); // Moves the fireball
	deductHealth(); // Deducts the health from any mob that collides with the fire ball
}

void Fireball::virtDraw() {
	image.renderImageWithMask(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY,
		image.getWidth(), image.getHeight());
}

void Fireball::deductHealth() {
	if ((dynamic_cast<Player1*>(mob) == nullptr)) { // This ensures that the mob that fires the projectile can't damage itself
		if (!deductedPlayerHealth) { // If the players health has not already been reduced
			Player1* player = (Player1*)engine->getPlayer();
			player->deductPlayerHealth(m_iCurrentScreenX, m_iCurrentScreenY, 25);
		}
	}
}

void Fireball::move() {
	m_iCurrentScreenX += nx;
	m_iCurrentScreenY += ny;
}

double Fireball::distance() {
	double dist = 0;
	dist = sqrt(abs((xOrigin - m_iCurrentScreenX) * (xOrigin - m_iCurrentScreenX) + (yOrigin - m_iCurrentScreenY) * (yOrigin - m_iCurrentScreenY)));
	return dist;
}