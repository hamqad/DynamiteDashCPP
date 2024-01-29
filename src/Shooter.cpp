#include "header.h"
#include "Shooter.h"

void Shooter::virtDoUpdate(int icurrenttime)
{
	Mob::virtDoUpdate(icurrenttime);
	player = (Player1*)engine->getPlayer();
	player->deductPlayerHealth(getXCentre(), getYCentre(), 10);

	if (fireTracker > 0) fireTracker--; // Decreases the fire rate every update cycle
	time++;
	player = (Player1*)engine->getPlayer(); // Sets player to the current player
	double dx = player->getXCentre() - m_iCurrentScreenX; // difference between the shooters and players x position
	double dy = player->getYCentre() - m_iCurrentScreenY; // difference between the shooters and players y position
	double dir = atan2(dy, dx); // Resultant direction
	if (fireTracker <= 0) { // Shoots a fireball from the shooter to the player if the delay has reached 0
		engine->addEntity(new Fireball(engine, m_iCurrentScreenX, m_iCurrentScreenY, dir, this, m_pTileManager));
		fireTracker = fireRate; // Resets the delay to the fire rate value 
	}

}

void Shooter::damage(int i)
{

}

void Shooter::virtDraw()
{
	image.renderImageWithMask(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY,
		image.getWidth(), image.getHeight());
}