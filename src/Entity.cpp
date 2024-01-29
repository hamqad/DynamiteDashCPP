#include "header.h"
#include "Entity.h"



void Entity::setImage(SimpleImage iImage) {
	image = iImage;
}
SimpleImage Entity::getImage()
{
    return image;
}

void Entity::virtDraw()
{
	image.renderImageWithMask(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY,
		image.getWidth(), image.getHeight());
}

void Entity::virtDoUpdate(int iCurrentTime)
{
}

void Entity::reset() {
	//removed = true;
}
int Entity::getX() {
	return m_iCurrentScreenX;
}

int Entity::getY() {
	return m_iCurrentScreenY;
}
