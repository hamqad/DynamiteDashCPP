#include "header.h"
#include "Zombie.h"
#include "BaseEngine.h"
#include "DisplayableObject.h"
#include "UtilCollisionDetection.h"



void Zombie::virtDraw()
{
	currentImage = currentSprite->getSprite();
	currentImage.renderImageWithMask(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY,
		currentImage.getWidth(), currentImage.getHeight());

}

void Zombie::move() {
	int ya = 0;
	if (direction == -1) {
		ya += speed;
		if (collision(0, ya)) {
			direction = 1;
			currentSprite = zombieUp;
		}
	}else if(direction == 1){
		ya -= speed;
		if (collision(0, ya)) {
			direction = -1;
			currentSprite = zombieDown;
		}
	}
	m_iCurrentScreenY += ya;
}

void Zombie::virtDoUpdate(int iCurrentTime)
{
	Mob::virtDoUpdate(iCurrentTime);
	currentSprite->update();
	move();
	player = (Player1*)engine->getPlayer();
	player->deductPlayerHealth(getXCentre(), getYCentre(), 10);
}

void Zombie::damage(int i)
{

}
