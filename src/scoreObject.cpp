#include "header.h"
#include "BaseEngine.h"
#include "scoreObject.h"
#include <chrono>


void scoreObject::virtDraw()
{	
	getEngine()->drawForegroundString(m_iCurrentScreenX, m_iCurrentScreenY, text, 0x000000,
		                              getEngine()->getFont("Pixeboy-z8XGD.ttf", 48));

}


void scoreObject::virtDoUpdate(int iCurrentTime)
{
	switch (rand() % 100)
	{
	case 0: text = "Score = Winning Greatly"; break;
	case 1: text = "Score = Losing Greatly"; break;
	case 2: text = "Score = Winning Slighty"; break;
	case 3: text = "Score = Losing Slighty"; break;
	case 4: text = "Score = Neautral"; break;
	case 5: text = "Score = Game Over"; break;
	}

	if (getEngine()->isKeyPressed(SDLK_w))
		m_iCurrentScreenY -= 3;
	if (getEngine()->isKeyPressed(SDLK_s))
		m_iCurrentScreenY += 3;
	if (getEngine()->isKeyPressed(SDLK_a))
		m_iCurrentScreenX -= 3;
	if (getEngine()->isKeyPressed(SDLK_d))
		m_iCurrentScreenX += 3;

	redrawDisplay();
}
