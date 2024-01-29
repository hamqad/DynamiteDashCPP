#include "header.h"
#include "MenuButton.h"
#include "BaseEngine.h"

void MenuButton::virtDoUpdate(int iCurrentTime) {

}

void MenuButton::virtDraw() {
	PsyhqEngine* engine;
	engine = (PsyhqEngine*)getEngine();
}

void MenuButton::virtMouseDown(int iButton, int iX, int iY)
{
	if (iButton == SDL_BUTTON_LEFT) {
		if (iX >= x && iX < (x + width) && iY >= y && iY < y + height) {
			PsyhqEngine* engine;
			engine = (PsyhqEngine*)getEngine();
			engine->setState(state);
		}
	}
}