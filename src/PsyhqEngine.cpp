#include "header.h"
#include "PsyhqEngine.h"
#include "scoreObject.h"
#include "Player1.h"
#include "Chaser.h"
#include "ChaserPro.h"
#include "Shooter.h"
#include "Zombie.h"
#include "Dragon.h"
#include "Dummy.h"
#include "LevelOne.h"
#include "Fireball.h"
#include <stdlib.h>

Player1* player;

// Runs before the game begins - Used to initalise variables and objects if needed
int PsyhqEngine::virtInitialise()
{
	getBackgroundSurface()->setDrawPointsFilter(&m_filterTranslation);
	getForegroundSurface()->setDrawPointsFilter(&m_filterTranslation);
	return BaseEngine::virtInitialise();
	
}

// Runs before printing the background - Checks the current state of the game and displays an image / creates the level accordingly
void PsyhqEngine::virtSetupBackgroundBuffer()
{
	notifyObjectsAboutMouse(true);
	if (strcmp("start", state) == 0) {
		gameState = false;
		SimpleImage home = iManager->loadImage("res/gamescreens/home.png", true);
		home.renderImage(getBackgroundSurface(), 0, 0, 0, 0,
			home.getWidth(), home.getHeight());
		virtInitialiseObjects();
	}
	else if (strcmp("help", state) == 0) {
		gameState = false;
		printf("Its help\n");
		SimpleImage help = iManager->loadImage("res/gamescreens/help.png", true);
		help.renderImage(getBackgroundSurface(), 0, 0, 0, 0,
			help.getWidth(), help.getHeight());
		virtInitialiseObjects();
	}
	else if (strcmp("singleplayer", state) == 0) {
		gameState = false;
		SimpleImage single = iManager->loadImage("res/gamescreens/singleplayer.png", true);
		single.renderImage(getBackgroundSurface(), 0, 0, 0, 0,
			single.getWidth(), single.getHeight());
		virtInitialiseObjects();
	}
	else if (strcmp("multiplayerplayer", state) == 0) {
		gameState = false;
		SimpleImage multiplayerp = iManager->loadImage("res/gamescreens/multiplayerplayer.png", true);
		multiplayerp.renderImage(getBackgroundSurface(), 0, 0, 0, 0,
			multiplayerp.getWidth(), multiplayerp.getHeight());
		virtInitialiseObjects();
	}
	else if (strcmp("multiplayerlevel", state) == 0) {
		gameState = false;
		SimpleImage multiplayerl = iManager->loadImage("res/gamescreens/multiplayerlevel.png", true);
		multiplayerl.renderImage(getBackgroundSurface(), 0, 0, 0, 0,
			multiplayerl.getWidth(), multiplayerl.getHeight());
		virtInitialiseObjects();
	}
	else if (strcmp("gameover", state) == 0) {
		gameState = false;
		SimpleImage gameover = iManager->loadImage("res/gamescreens/gameover.png", true);
		gameover.renderImage(getBackgroundSurface(), 0, 0, 0, 0,
			gameover.getWidth(), gameover.getHeight());
		virtInitialiseObjects();
	}
	else if (strcmp("level1", state) == 0) {
		gameState = true;
		currentLevel = level1;
		currentLevel->setTopLeftPositionOnScreen(700, 460);
		createLevel("Level 1");

	}
	else if (strcmp("level2", state) == 0) {
		gameState = true;
		currentLevel = level2;
		currentLevel->setTopLeftPositionOnScreen((int)((ceil(700) / 32) * 32), (int)((ceil(460) / 32) * 32));
		createLevel("Level 2");
	}
	else if (strcmp("level3", state) == 0) {
		gameState = true;
		currentLevel = level3;
		currentLevel->setTopLeftPositionOnScreen((int)((ceil(700) / 32) * 32), (int)((ceil(460) / 32) * 32));
		createLevel("Level 3");
	}
	else if (strcmp("level4", state) == 0) {
		gameState = true;
		currentLevel = level4;
		currentLevel->setTopLeftPositionOnScreen((int)((ceil(672) / 32) * 32), (int)((ceil(280) / 32) * 32));
		createLevel("Level 4");
	}
	else if (strcmp("level5", state) == 0) {
		gameState = true;
		currentLevel = level5;
		currentLevel->setTopLeftPositionOnScreen(608, 220);
		createLevel("Level 5");
	}
	else if (strcmp("level6", state) == 0) {
		gameState = true;
		currentLevel = level6;
		currentLevel->setTopLeftPositionOnScreen(544, 156);
		createLevel("Level 6");
	}
	else if (strcmp("level7", state) == 0) {
		gameState = true;
		currentLevel = level7;
		currentLevel->setTopLeftPositionOnScreen(448, 60);
		createLevel("Level 7");
	}
	else if (strcmp("level8", state) == 0) {
		gameState = true;
		currentLevel = level8;
		currentLevel->setTopLeftPositionOnScreen(448, 60);
		createLevel("Level 8");
	}
	else if (strcmp("level9", state) == 0) {
		gameState = true;
		currentLevel = level9;
		currentLevel->setTopLeftPositionOnScreen(384, 0);
		createLevel("Level 9");
	}
	else if (strcmp("level10", state) == 0) {
		gameState = true;
		currentLevel = level10;
		currentLevel->setTopLeftPositionOnScreen(0, 0);
		createLevel("Level 10");
	}
}

// Called in the above function in order to generate a level - Every level has a brown background and random green lines to represent grass
// Then draws all the tiles in that level. 
void PsyhqEngine::createLevel(char* level) {
	// Draw the background that every level has by drawing random lines
	fillBackground(0xb573b20);
	for (int iX = 0; iX < getWindowWidth(); iX++)
		for (int iY = 0; iY < this->getWindowHeight(); iY++)
			if ((rand() % 6) == 0)
			{ 
				drawBackgroundLine(iX, iY, (iX + (rand() % 5)), (iY + (rand() % 5)), 0x059C4F);
			}
	// Draw the text that displays the current level
	drawBackgroundString((getWindowWidth() / 2) - 30, 20, level, 0xffffff,
		getFont("Pixeboy-z8XGD.ttf", 48));

	//Loops through the current levels tiles and displays them to the screen
	currentLevel->drawAllTiles(this, getBackgroundSurface());

	// Since this function is called every time a new level is loaded, it also intialises all the mobs in the level
	virtInitialiseObjects();
}

// Loads the next level depending on what the currrent level is 
void PsyhqEngine::nextLevel() {
	if (strcmp("level1", state) == 0) {
		setState("level2");
	}
	else if (strcmp("level2", state) == 0) {
		setState("level3");
	}
	else if (strcmp("level3", state) == 0) {
		setState("level4");
	}
	else if (strcmp("level4", state) == 0) {
		setState("level5");
	}
	else if (strcmp("level5", state) == 0) {
		setState("level6");
	}
	else if (strcmp("level6", state) == 0) {
		setState("level7");
	}
	else if (strcmp("level7", state) == 0) {
		setState("level8");
	}
	else if (strcmp("level8", state) == 0) {
		setState("level9");
	}
	else if (strcmp("level9", state) == 0) {
		setState("level10");
	}
	else if (strcmp("level10", state) == 0) {
		setState("gameover");
	}
}

// Initialises the objects depending on the state of the game - If its a level state, creates all the mobs on the screen
int PsyhqEngine::virtInitialiseObjects()
{
	if (strcmp("start", state) == 0) {
		drawableObjectsChanged();
		destroyOldObjects(true);
		createObjectArray(4);
		storeObjectInArray(0, new MenuButton(this, 48, 33, 56, 56, "quit"));
		storeObjectInArray(1, new MenuButton(this, 715, 557, 490, 98, "singleplayer"));
		storeObjectInArray(2, new MenuButton(this, 715, 691, 490, 98, "multiplayerplayer"));
		storeObjectInArray(3, new MenuButton(this, 715, 827, 490, 98, "help"));
		setAllObjectsVisible(true);
	}
	else if (strcmp("help", state) == 0) {
		drawableObjectsChanged();
		destroyOldObjects(true);
		createObjectArray(1);
		storeObjectInArray(0, new MenuButton(this, 48, 33, 56, 56, "start"));
		setAllObjectsVisible(true);
	}
	else if (strcmp("singleplayer", state) == 0) {
		drawableObjectsChanged();
		destroyOldObjects(true);
		createObjectArray(11);
		storeObjectInArray(0, new MenuButton(this, 48, 33, 56, 56, "start"));
		storeObjectInArray(1, new MenuButton(this, 240, 468, 213, 213, "level1"));
		storeObjectInArray(2, new MenuButton(this, 547, 468, 213, 213, "level2"));
		storeObjectInArray(3, new MenuButton(this, 854, 468, 213, 213, "level3"));
		storeObjectInArray(4, new MenuButton(this, 1161, 468, 213, 213, "level4"));
		storeObjectInArray(5, new MenuButton(this, 1467, 468, 213, 213, "level5"));
		storeObjectInArray(6, new MenuButton(this, 240, 753, 213, 213, "level6"));
		storeObjectInArray(7, new MenuButton(this, 547, 753, 213, 213, "level7"));
		storeObjectInArray(8, new MenuButton(this, 854, 753, 213, 213, "level8"));
		storeObjectInArray(9, new MenuButton(this, 1161, 753, 213, 213, "level9"));
		storeObjectInArray(10, new MenuButton(this, 1467, 753, 213, 213, "level10"));
		setAllObjectsVisible(true);
	}
	else if (strcmp("multiplayerplayer", state) == 0) {
		drawableObjectsChanged();
		destroyOldObjects(true);
		createObjectArray(4);
		storeObjectInArray(0, new MenuButton(this, 48, 33, 56, 56, "start"));
		storeObjectInArray(1, new MenuButton(this, 641, 465, 213, 213, "multiplayerlevel"));
		storeObjectInArray(2, new MenuButton(this, 946, 465, 213, 213, "multiplayerlevel"));
		storeObjectInArray(3, new MenuButton(this, 797, 754, 213, 213, "multiplayerlevel"));
		setAllObjectsVisible(true);
	}
	else if (strcmp("multiplayerlevel", state) == 0) {
		drawableObjectsChanged();
		destroyOldObjects(true);
		createObjectArray(11);
		storeObjectInArray(0, new MenuButton(this, 48, 33, 56, 56, "start"));
		storeObjectInArray(1, new MenuButton(this, 240, 468, 213, 213, "mlevel1"));
		storeObjectInArray(2, new MenuButton(this, 547, 468, 213, 213, "mlevel2"));
		storeObjectInArray(3, new MenuButton(this, 854, 468, 213, 213, "mlevel3"));
		storeObjectInArray(4, new MenuButton(this, 1161, 468, 213, 213, "mlevel4"));
		storeObjectInArray(5, new MenuButton(this, 1467, 468, 213, 213, "mlevel5"));
		storeObjectInArray(6, new MenuButton(this, 240, 753, 213, 213, "mlevel6"));
		storeObjectInArray(7, new MenuButton(this, 547, 753, 213, 213, "mlevel7"));
		storeObjectInArray(8, new MenuButton(this, 854, 753, 213, 213, "mlevel8"));
		storeObjectInArray(9, new MenuButton(this, 1161, 753, 213, 213, "mlevel9"));
		storeObjectInArray(10, new MenuButton(this, 1467, 753, 213, 213, "mlevel10"));
		setAllObjectsVisible(true);
	}
	else if (strcmp("level1", state) == 0) {
		drawableObjectsChanged();
		destroyOldObjects(true);
		createObjectArray(1);
		player = new Player1(this, 732, 524, currentLevel);
		storeObjectInArray(0, player);
		setAllObjectsVisible(true);
	}
	else if (strcmp("level2", state) == 0) {
		drawableObjectsChanged();
		destroyOldObjects(true);
		createObjectArray(1);
		player = new Player1(this, 732, 524, currentLevel);
		storeObjectInArray(0, player);
		setAllObjectsVisible(true);
	}
	else if (strcmp("level3", state) == 0) {
		drawableObjectsChanged();
		destroyOldObjects(true);
		createObjectArray(3);
		player = new Player1(this, 732, 524, currentLevel);
		storeObjectInArray(0, player);
		storeObjectInArray(1, new Zombie(this, 900, 492, currentLevel));
		storeObjectInArray(2, new Zombie(this, 932, 556, currentLevel));
		setAllObjectsVisible(true);
	}
	else if (strcmp("level4", state) == 0) {
		drawableObjectsChanged();
		destroyOldObjects(true);
		createObjectArray(4);
		player = new Player1(this, 736, 332, currentLevel);
		storeObjectInArray(0, player);
		storeObjectInArray(1, new Chaser(this, 1100, 332, currentLevel));
		storeObjectInArray(2, new Chaser(this, 832, 532, currentLevel));
		storeObjectInArray(3, new Chaser(this, 736, 736, currentLevel));
		setAllObjectsVisible(true);
	}
	else if (strcmp("level5", state) == 0) {
		drawableObjectsChanged();
		destroyOldObjects(true);
		createObjectArray(2);
		player = new Player1(this, 640, 544, currentLevel);
		storeObjectInArray(0, new Player1(this, 640, 544, currentLevel));
		storeObjectInArray(1, new Chaser(this, 960, 544, currentLevel));
		setAllObjectsVisible(true);
	}
	else if (strcmp("level6", state) == 0) {
		drawableObjectsChanged();
		destroyOldObjects(true);
		createObjectArray(25);
		player = new Player1(this, 576, 512, currentLevel);
		storeObjectInArray(0, player);
		storeObjectInArray(1, new Zombie(this, 672, 256, currentLevel));
		storeObjectInArray(2, new Zombie(this, 704, 760, currentLevel));
		storeObjectInArray(3, new Zombie(this, 736, 256, currentLevel));
		storeObjectInArray(4, new Zombie(this, 768, 760, currentLevel));
		storeObjectInArray(5, new Zombie(this, 800, 256, currentLevel));
		storeObjectInArray(6, new Zombie(this, 832, 760, currentLevel));
		storeObjectInArray(7, new Zombie(this, 864, 256, currentLevel));
		storeObjectInArray(8, new Zombie(this, 896, 760, currentLevel));
		storeObjectInArray(9, new Zombie(this, 928, 256, currentLevel));
		storeObjectInArray(10, new Zombie(this, 960, 760, currentLevel));
		storeObjectInArray(11, new Zombie(this, 992, 256, currentLevel));
		storeObjectInArray(12, new Zombie(this, 1024, 760, currentLevel));
		storeObjectInArray(13, new Zombie(this, 1056, 256, currentLevel));
		storeObjectInArray(14, new Zombie(this, 1088, 760, currentLevel));
		storeObjectInArray(15, new Zombie(this, 1120, 256, currentLevel));
		storeObjectInArray(16, new Zombie(this, 1152, 760, currentLevel));
		storeObjectInArray(17, new Zombie(this, 1184, 256, currentLevel));
		storeObjectInArray(18, new Zombie(this, 1216, 760, currentLevel));
		
		storeObjectInArray(19, new Zombie(this, 1280, 192, currentLevel));
		storeObjectInArray(20, new Zombie(this, 1312, 860, currentLevel));

		storeObjectInArray(21, new Zombie(this, 896, 832, currentLevel));
		storeObjectInArray(22, new Zombie(this, 1152, 855, currentLevel));
		storeObjectInArray(23, new Zombie(this, 640, 832, currentLevel));
		setAllObjectsVisible(true);
	}
	else if (strcmp("level7", state) == 0) {
		drawableObjectsChanged();
		destroyOldObjects(true);
		createObjectArray(3);
		player = new Player1(this, 480, 480, currentLevel);
		storeObjectInArray(0, player);
		storeObjectInArray(1, new Zombie(this, 576, 672, currentLevel));
		storeObjectInArray(2, new ChaserPro(this, 480, 350, currentLevel));
		setAllObjectsVisible(true);
	}
	else if (strcmp("level8", state) == 0) {
		drawableObjectsChanged();
		destroyOldObjects(true);
		createObjectArray(29);
		player = new Player1(this, 512, 96, currentLevel);
		storeObjectInArray(0, player);
		storeObjectInArray(1, new Dummy(this, 1181, 137, currentLevel));
		storeObjectInArray(2, new Dummy(this, 922, 823, currentLevel));
		storeObjectInArray(3, new Dummy(this, 779, 754, currentLevel));
		storeObjectInArray(4, new Dummy(this, 996, 372, currentLevel));
		storeObjectInArray(5, new Dummy(this, 1064, 773, currentLevel));
		storeObjectInArray(6, new Dummy(this, 1149, 561, currentLevel));
		storeObjectInArray(7, new Dummy(this, 1136, 452, currentLevel));
		storeObjectInArray(8, new Dummy(this, 958, 481, currentLevel));
		storeObjectInArray(9, new Dummy(this, 780, 580, currentLevel));
		storeObjectInArray(10, new Dummy(this, 1177, 386, currentLevel));
		storeObjectInArray(11, new Dummy(this, 844, 234, currentLevel));
		storeObjectInArray(12, new Dummy(this, 1364, 797, currentLevel));
		storeObjectInArray(13, new Dummy(this, 692, 655, currentLevel));
		storeObjectInArray(14, new Dummy(this, 616, 438, currentLevel));
		storeObjectInArray(15, new Dummy(this, 612, 538, currentLevel));
		storeObjectInArray(16, new Dummy(this, 1211, 430, currentLevel));
		storeObjectInArray(17, new Dummy(this, 654, 153, currentLevel));
		storeObjectInArray(18, new Dummy(this, 512, 518, currentLevel));
		storeObjectInArray(19, new Dummy(this, 1067, 490, currentLevel));
		storeObjectInArray(20, new Dummy(this, 907, 702, currentLevel));
		storeObjectInArray(21, new Dummy(this, 628, 317, currentLevel));
		storeObjectInArray(22, new Dummy(this, 1124, 700, currentLevel));
		storeObjectInArray(23, new Dummy(this, 908, 782, currentLevel));
		storeObjectInArray(24, new Dummy(this, 1253, 412, currentLevel));
		storeObjectInArray(25, new Dummy(this, 1228, 522, currentLevel));
		storeObjectInArray(26, new Dummy(this, 939, 679, currentLevel));
		storeObjectInArray(27, new Dummy(this, 721, 572, currentLevel));
		storeObjectInArray(28, new Dummy(this, 798, 320, currentLevel));
		setAllObjectsVisible(true);
	}
	else if (strcmp("level9", state) == 0) {
		drawableObjectsChanged();
		destroyOldObjects(true);
		createObjectArray(9);
		player = new Player1(this, 416, 64, currentLevel);
		storeObjectInArray(0, player);
		storeObjectInArray(1, new Shooter(this, 416, 800, currentLevel));
		storeObjectInArray(2, new Shooter(this, 416, 892, currentLevel));
		storeObjectInArray(3, new Shooter(this, 544, 992, currentLevel));
		storeObjectInArray(4, new Shooter(this, 672, 992, currentLevel));
		storeObjectInArray(5, new Shooter(this, 1184, 992, currentLevel));
		storeObjectInArray(6, new Shooter(this, 1312, 992, currentLevel));
		storeObjectInArray(7, new Shooter(this, 1472, 800, currentLevel));
		storeObjectInArray(8, new Shooter(this, 1472, 892, currentLevel));
		setAllObjectsVisible(true);
	}
	else if (strcmp("level10", state) == 0) {
		drawableObjectsChanged();
		destroyOldObjects(true);
		createObjectArray(2);
		player = new Player1(this, 160, 544, currentLevel);
		storeObjectInArray(0, player);
		storeObjectInArray(1, new Dragon(this, 1520, 544, currentLevel));
		setAllObjectsVisible(true);
	}
	else if (strcmp("gameover", state) == 0) {
		drawableObjectsChanged();
		destroyOldObjects(true);
		createObjectArray(1);
		storeObjectInArray(0, new MenuButton(this, 48, 33, 56, 56, "start"));

		setAllObjectsVisible(true);
	}
	return 0;
}

// Runs before every loop of the main loop. Checks if the state has been changed. If it has, it sets up the background again re-initalises objects
// This also handles the beginngin dynamite animation
void PsyhqEngine::virtMainLoopPreUpdate()
{
	if (strcmp(prevState, state) != 0) {
		lockAndSetupBackground();
		redrawDisplay();
		prevState = state;
	}

	if (strcmp("animation", state) == 0) {
		if (!d1) {
			lockBackgroundForDrawing();
			printf("Loading dynamite 1\n");
			SimpleImage dynamite1 = iManager->loadImage("res/gamescreens/dynamite1.png", true);
			dynamite1.renderImage(getBackgroundSurface(), 0, 0, 0, 0,
				dynamite1.getWidth(), dynamite1.getHeight());
			unlockBackgroundForDrawing();
			this->redrawDisplay();
			d1 = true;
		}
		else if (!d2) {
			lockBackgroundForDrawing();
			printf("Loading dynamite 2\n");
			SimpleImage dynamite2 = iManager->loadImage("res/gamescreens/dynamite2.png", true);
			dynamite2.renderImage(getBackgroundSurface(), 0, 0, 0, 0,
				dynamite2.getWidth(), dynamite2.getHeight());
			d2 = true;
			unlockBackgroundForDrawing();
			this->redrawDisplay();

		}
		else if (!d3) {
			lockBackgroundForDrawing();
			printf("Loading dynamite 3\n");
			SimpleImage dynamite3 = iManager->loadImage("res/gamescreens/dynamite3.png", true);
			dynamite3.renderImage(getBackgroundSurface(), 0, 0, 0, 0,
				dynamite3.getWidth(), dynamite3.getHeight());
			unlockBackgroundForDrawing();
			this->redrawDisplay();
			d3 = true;
		}
		else if (!d4) {
			lockBackgroundForDrawing();
			printf("Loading dynamite 4\n");
			SimpleImage dynamite4 = iManager->loadImage("res/gamescreens/dynamite4.png", true);
			dynamite4.renderImage(getBackgroundSurface(), 0, 0, 0, 0,
				dynamite4.getWidth(), dynamite4.getHeight());
			unlockBackgroundForDrawing();
			this->redrawDisplay();
			d4 = true;
		}
		else if (!d5) {
			lockBackgroundForDrawing();
			printf("Loading dynamite 5\n");
			SimpleImage dynamite5 = iManager->loadImage("res/gamescreens/dynamite5.png", true);
			dynamite5.renderImage(getBackgroundSurface(), 0, 0, 0, 0,
				dynamite5.getWidth(), dynamite5.getHeight());
			unlockBackgroundForDrawing();
			this->redrawDisplay();
			d5 = true;
		}
		else if (!d6) {
			lockBackgroundForDrawing();
			printf("Loading dynamite 6\n");
			SimpleImage dynamite6 = iManager->loadImage("res/gamescreens/dynamite6.png", true);
			dynamite6.renderImage(getBackgroundSurface(), 0, 0, 0, 0,
				dynamite6.getWidth(), dynamite6.getHeight());
			unlockBackgroundForDrawing();
			this->redrawDisplay();
			d6 = true;
		}
		else {
			animation = true;
			state = "start";
		}
	}

	if (strcmp("level10", state) == 0) {
		m_iOffset = (m_iOffset + 1) % getWindowHeight();
		this->redrawDisplay();
	}
	else {
		m_iOffset = 0;
	}
}

// Used to check if the user has input any key
void PsyhqEngine::virtKeyDown(int iKeyCode)
{
	if (strcmp(state, "gameover") == 0) {
		lockBackgroundForDrawing();
		switch (iKeyCode)
		{
			case SDLK_a:text.append("a"); break;
			case SDLK_b:text.append("b"); break;
			case SDLK_c:text.append("c"); break;
			case SDLK_d:text.append("d"); break;
			case SDLK_e:text.append("e"); break;
			case SDLK_f:text.append("f"); break;
			case SDLK_g:text.append("g"); break;
			case SDLK_h:text.append("h"); break;
			case SDLK_i:text.append("i"); break;
			case SDLK_j:text.append("j"); break;
			case SDLK_k:text.append("k"); break;
			case SDLK_l:text.append("l"); break;
			case SDLK_m:text.append("m"); break;
			case SDLK_n:text.append("n"); break;
			case SDLK_o:text.append("o"); break;
			case SDLK_p:text.append("p"); break;
			case SDLK_q:text.append("q"); break;
			case SDLK_r:text.append("r"); break;
			case SDLK_s:text.append("s"); break;
			case SDLK_t:text.append("t"); break;
			case SDLK_u:text.append("u"); break;
			case SDLK_v:text.append("v"); break;
			case SDLK_w:text.append("w"); break;
			case SDLK_x:text.append("x"); break;
			case SDLK_y:text.append("y"); break;
			case SDLK_z:text.append("z"); break;
			case SDLK_BACKSPACE:text.pop_back(); break;
		}	
			getBackgroundSurface()->drawFastString(700, 700, text.c_str(), 0x000000, getFont("Pixeboy-z8XGD.ttf", 48));
			redrawDisplay();
			unlockBackgroundForDrawing();
	}
	else {
		switch (iKeyCode)
		{
		case SDLK_r:
			lockBackgroundForDrawing();
			virtSetupBackgroundBuffer();
			unlockBackgroundForDrawing();
			redrawDisplay();
			break;
		case SDLK_ESCAPE:
			setState("start");
			break;
		case SDLK_LEFT:
			m_filterTranslation.changeOffset(10, 0);
			redrawDisplay();
			break;
		case SDLK_RIGHT:
			m_filterTranslation.changeOffset(-10, 0);
			redrawDisplay();
			break;
		case SDLK_UP:
			m_filterTranslation.changeOffset(0, 10);
			redrawDisplay();
			break;
		case SDLK_DOWN:
			m_filterTranslation.changeOffset(0, -10);
			redrawDisplay();
			break;
		}
	}
}

// Used to check if the user has input a scroll wheel 
void PsyhqEngine::virtMouseWheel(int x, int y, int which, int timestamp)
{
	// We grab the position of the centre of the screen before the zoom
	int iOldCentreX = convertClickedToVirtualPixelXPosition(this->getWindowWidth() / 2);
	int iOldCentreY = convertClickedToVirtualPixelYPosition(this->getWindowHeight() / 2);

	if (y < 0)
		m_filterScaling.compress();
	else if (y > 0)
		m_filterScaling.stretch();

	int iNewCentreX = convertClickedToVirtualPixelXPosition(this->getWindowWidth() / 2);
	int iNewCentreY = convertClickedToVirtualPixelYPosition(this->getWindowHeight() / 2);

	m_filterTranslation.changeOffset(iNewCentreX - iOldCentreX, iNewCentreY - iOldCentreY);
	redrawDisplay(); 
}

//Set the state of the game to something else
void PsyhqEngine::setState(char* state)
{
	this->state = state;
}

char* PsyhqEngine::getState()
{
	return state;
}

// Returns the player object 
DisplayableObject* PsyhqEngine::getPlayer() {
	return player;
}

// Adds an object to the object array
void PsyhqEngine::addEntity(DisplayableObject* entity)
{
	appendObjectToArray(entity);
	drawableObjectsChanged();
}

// Removes an object from the object array
void PsyhqEngine::removeEntity(DisplayableObject* entity) {
	removeDisplayableObject(entity);
	drawableObjectsChanged();
}

void PsyhqEngine::copyAllBackgroundBuffer()
{
	// Note: this relies upon the bounds checking and fixing which is within copyRectangleFrom in BaseEngine
	m_pForegroundSurface->copyRectangleFrom(m_pBackgroundSurface, 0, 0, getWindowWidth(), getWindowHeight(), 0, m_iOffset);
	m_pForegroundSurface->copyRectangleFrom(m_pBackgroundSurface, 0, getWindowHeight() - m_iOffset, getWindowWidth(), getWindowHeight(), 0, m_iOffset - getWindowHeight());
}
