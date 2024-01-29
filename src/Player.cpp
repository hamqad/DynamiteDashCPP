#include "header.h"
#include "Player.h"


void Player::virtDoUpdate(int icurrenttime)
{
	time++;
	if (currentPlace > 0) currentPlace--;

}

void Player::damage(int i)
{

}

void Player::virtDraw()
{
	image.renderImageWithMask(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY,
		image.getWidth(), image.getHeight());
}

void Player::deductPlayerHealth(int x, int y)
{
	
}


void Player::addHealth(int h)
{
	for (int i = h; i >= 0; i--) {
		if (!((health + i) > 100)) {
			health += i;
			return;
		}
		continue;
	}
}
