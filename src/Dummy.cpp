#include "header.h"
#include "Dummy.h"

void Dummy::virtDoUpdate(int iCurrentTime)
{
	time++;
	Mob::virtDoUpdate(iCurrentTime);
	currentSprite->update();
	double xa = 0;
	double ya = 0;

	if(rand() % 3 == 0) xa = (double)(rand() % 100) / 100;
	if (rand() % 3 == 0) ya = (double)(rand() % 100) / 100;
		
	if ((rand() % 2) == 0) {
		xa = (double)(xa * -1);
		ya = (double)(ya * -1);
	}			
	if (rand() % 4 == 0) {
		xa = 0;
		ya = 0;
	}
	if (ya < 0) {
		currentSprite = dummyUp;
	}
	else if (ya > 0) {
		currentSprite = dummyDown;
	}
	if (xa < 0) {
		currentSprite = dummyLeft;
	}
	else if (xa > 0) {
		currentSprite = dummyRight;
	}

	if (xa != 0 || ya != 0) {   // If the dummy needs to be displaced, the dummy is moved according to the displacement and walking is set to true
		moveMe(xa, ya);
		walking = true;
	}
	else {
		walking = false;
	}

	player = (Player1*)engine->getPlayer();
	player->deductPlayerHealth(getXCentre(), getYCentre(), 10);

}

void Dummy::damage(int i)
{

}

void Dummy::virtDraw()
{
	currentImage = currentSprite->getSprite();
	image.renderImageWithMask(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY,
		image.getWidth(), image.getHeight());
}