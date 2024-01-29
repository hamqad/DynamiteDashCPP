#include "header.h"
#include <math.h>
#include "Mob.h"

void Mob::virtDoUpdate(int iCurrentTime) {
	if (health == 0) {
		engine->removeEntity(this);
	} 
}

void Mob::moveMe(double xa, double ya)
{
	if (xa != 0 && ya != 0) {  // If player is moving horizontally, the function is called again twice with each of the directions individually 
		moveMe(xa, 0);
		moveMe(0, ya);
		return;
	}

	while (xa != 0) {   // While the mob still needs to be displaced 
		if (abs(xa) > 1) { // If the displacement is still larger than one
			if (!collision(abs(xa), ya)) { // Displace the mob by 1 if there is no collision
				m_iCurrentScreenX += abs(xa);
			}
			xa -= abs(xa);
		}
		else {
			if (!collision(abs(xa), ya)) { // Displace the mob by the decimal required if there is no collision
				m_iCurrentScreenX += xa;
			}
			xa = 0;
		}
	}
	// This assures that the collision is always tested on the y axis each time the mob moves by 1 despite the overall displacement value:
	while (ya != 0) {   // While the mob still needs to be displaced 
		if (abs(ya) > 1) { // If the displacement is still larger than one
			if (!collision(xa, abs(ya))) { // Displace the mob by 1 if there is no collision
				m_iCurrentScreenY += abs(ya);
			}
			ya -= abs(ya);
		}
		else {
			if (!collision(xa, abs(ya))) { // Displace the mob by the decimal required if there is no collision
				m_iCurrentScreenY += ya;
			}
			ya = 0;
		}
	}
}


int Mob::abs(double value)
{
	if (value < 0) return -1;
	return 1;
}


void Mob::damage(int i)
{
	if ((health - i) < 0) health = 0;
	else health -= i;
}

void Mob::deductHealth(int x, int y, int iDamage)
{
	int mobX = (int)ceil(getXCentre() / 32); // The players current x tile coordinate
	int mobY = (int)ceil(getYCentre() / 32); // The players current y tile coordinate
	int enemyX = (int)ceil(x / 32); // The enemies current x tile position
	int enemyY = (int)ceil(y / 32); // The enemies current y tile position
	if (mobX == enemyX && mobY == enemyY) {
		damage(iDamage);
	}
}

bool Mob::collision(double xa, double ya)
{
	bool solid = false;   // Default collision is set to false
	for (int w = 0; w < image.getWidth(); w++) {
		for (int h = 0; h < image.getHeight(); h++)
		{
			int realPositionX = (m_iCurrentScreenX + w) + xa;
			int realPositionY = (m_iCurrentScreenY + h) + ya;

			if (image.getPixelColour(w, h) == 16711896) {
				continue;
			}
			else if (m_pTileManager->isValidTilePosition(realPositionX, realPositionY)) {
				int iTileX = m_pTileManager->getMapXForScreenX(realPositionX);
				int iTileY = m_pTileManager->getMapYForScreenY(realPositionY);
				int iCurrentTile = m_pTileManager->getMapValue(iTileX, iTileY);
				if (iCurrentTile != 2 && iCurrentTile != 3) {
					continue;
				}else{
					return true;
				}
			}
		}
	}
	return solid;
}
