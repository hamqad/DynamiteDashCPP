#include "header.h"
#include "ChaserPro.h"

void ChaserPro::virtDoUpdate(int icurrenttime)
{
	Mob::virtDoUpdate(icurrenttime);
	player = (Player1*)engine->getPlayer();
	player->deductPlayerHealth(getXCentre(), getYCentre(), 10);
}

void ChaserPro::damage(int i)
{

}

void ChaserPro::virtDraw()
{
	image.renderImageWithMask(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY,
		image.getWidth(), image.getHeight());
}