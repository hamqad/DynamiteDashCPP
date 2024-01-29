#include "header.h"
#include "Chaser.h"
#include <stdlib.h>

void Chaser::move()
{
	xa = 0;
	ya = 0;

	// Logic of chasers movement: (If the players position is not equal to the chasers distance, move towards the player)

	Player1* object = (Player1*)engine->getPlayer();
	int x = object->getXCentre(); // X coordinate of the foreign entity in the list
	int y = object->getYCentre(); // Y coordinate of the foreign entity in the list

	int ex = getXCentre();
	int ey = getYCentre();

	int dx = std::abs(x - ex); // Calculates the distance between the foreign entity and the current entity on the x axis
	int dy = std::abs(y - ey); // Calculates the distance between the foreign entity and the current entity on the y axis	
	int distance = (int)sqrt((dx * dx) + (dy * dy)); // uses Pythagoras' theorem to calculate the distance between the two entities 

	if (distance < 140) {
		if (getXCentre() < object->getXCentre()) xa += speed;
		if (getXCentre() > object->getXCentre()) xa -= speed;
		if (getYCentre() < object->getYCentre()) ya += speed;
		if (getYCentre() > object->getYCentre()) ya -= speed;
	}

	object->deductPlayerHealth(getXCentre(), getYCentre(), 10);

	if (xa != 0 || ya != 0) {   // if the chasers displacement is not 0  it will move in the specific direction and walking will be set to true
		moveMe(xa, ya);
		walking = true;
	}
	else{
		walking = false;
	}
}

void Chaser::virtDoUpdate(int icurrenttime)
{
	Mob::virtDoUpdate(icurrenttime);
	if (walking)currentSprite->update();
	else currentSprite->setFrame(3);

	if (ya < 0) {
		currentSprite = chaserUp;
	}
	else if (ya > 0) {
		currentSprite = chaserDown;
	}
	if (xa < 0) {
		currentSprite = chaserLeft;
	}
	else if (xa > 0) {
		currentSprite = chaserRight;
	}

	move();
}

void Chaser::damage(int i)
{

}

void Chaser::virtDraw()
{
	currentImage = currentSprite->getSprite();
	currentImage.renderImageWithMask(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY,
		currentImage.getWidth(), currentImage.getHeight());
}