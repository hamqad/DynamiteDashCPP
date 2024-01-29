#include "header.h"
#include "Player1.h"
#include "BaseEngine.h"
#include "DisplayableObject.h"
#include "UtilCollisionDetection.h"
#include <math.h> 


void Player1::damage(int d)
{
	if ((health - d) < 0) health = 0;
	else health -= d;
	
	currentSprite = hurt;
	reset = true;
}

void Player1::virtDoUpdate(int icurrenttime)
{
	Player::virtDoUpdate(icurrenttime);
	if (walking)currentSprite->update();
	else currentSprite->setFrame(3);
	if (health == 0) engine->setState("gameover");

	
	if (m_pTileManager->isValidTilePosition(m_iCurrentScreenX, m_iCurrentScreenY))
	{
		int iTileX = m_pTileManager->getMapXForScreenX(m_iCurrentScreenX);
		int iTileY = m_pTileManager->getMapYForScreenY(m_iCurrentScreenY);
		int iCurrentTile = m_pTileManager->getMapValue(iTileX, iTileY);
		if (iCurrentTile == 6) {
			m_pTileManager->spawnDoor();
		}
		else if (iCurrentTile == 5) {
			engine->nextLevel();
		}
	}

	double xa = 0, ya = 0;
	if (engine->isKeyPressed(SDLK_w)){
		ya -= speed;
		currentSprite = playerUp;
	}if (engine->isKeyPressed(SDLK_s) && !playerCollision){
		ya += speed;
		currentSprite = playerDown;
	}if (engine->isKeyPressed(SDLK_a) && !playerCollision){
		xa -= speed;
		currentSprite = playerLeft;
	}if (engine->isKeyPressed(SDLK_d) && !playerCollision){
		xa += speed;
		currentSprite = playerRight;
	}if (engine->isKeyPressed(SDLK_k) ) {
		engine->pause();
		engine->lockForegroundForDrawing();
		engine->lockBackgroundForDrawing();
		m_pTileManager->saveLevel();
		engine->unlockBackgroundForDrawing();
		engine->unlockForegroundForDrawing();

	}if(engine->isKeyPressed(SDLK_l)) {
		engine->pause();
		engine->lockForegroundForDrawing();
		engine->lockBackgroundForDrawing();
		m_pTileManager->loadLevel();
		engine->unlockBackgroundForDrawing();
		engine->unlockForegroundForDrawing();
		engine->redrawDisplay();
	}

	if (xa != 0 || ya != 0) {   // if a key is pressed the player will move in the specific direction and walking will be set to true
		moveMe(xa, ya);
		walking = true;
	}else {
		walking = false;
	}
	updateDynamite();
	redrawDisplay();
}

void Player1::deductPlayerHealth(int x, int y, int iDamage)
{
	int playerX = (int)ceil(getXCentre() / 32); // The players current x tile coordinate
	int playerY = (int)ceil(getYCentre() / 32); // The players current y tile coordinate
	int enemyX = (int)ceil(x / 32); // The enemies current x tile position
	int enemyY = (int)ceil(y / 32); // The enemies current y tile position
	if (playerX == enemyX && playerY == enemyY) {
		damage(iDamage);
	}
}

void Player1::updateDynamite()
{
	dynamiteNumber = 2;
	if (engine->isKeyPressed(SDLK_SPACE) && currentPlace <= 0 && dynamiteNumber != 0) {
		dynamiteNumber--;
		Entity* dynamite = new Dynamite(engine, m_iCurrentScreenX, m_iCurrentScreenY, detonateTime, range, m_pTileManager, this);
		engine->addEntity(dynamite);
		time = 0;
		currentPlace = placeRate;
	}
}

void Player1::virtDraw()
{
	currentImage = currentSprite->getSprite();
	currentImage.renderImageWithMask(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY,
		currentImage.getWidth(), currentImage.getHeight());
}

void Player1::virtMouseDown(int iButton, int iX, int iY) {

}