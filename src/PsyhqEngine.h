#pragma once
#include "BaseEngine.h"
#include "header.h"
#include "PsyhqTileManager.h"
#include "MenuButton.h"
#include "ExampleFilterPointClasses.h"
#include "LevelOne.h"
#include "LevelTwo.h"
#include "LevelThree.h"
#include "LevelFour.h"
#include "LevelFive.h"
#include "LevelSix.h"
#include "LevelSeven.h"
#include "LevelEight.h"
#include "LevelNine.h"
#include "LevelTen.h"
#include <vector>



class PsyhqEngine : 
    public BaseEngine
{
public:
    PsyhqEngine()
        // Set up filters - first translate points then scale
        : m_filterScaling(0, 0, this), m_filterTranslation(0, 0, &m_filterScaling)
    {}
    ImageManager* iManager = new ImageManager();
    char* prevState = "animation";
    char* state = "animation";
    void virtSetupBackgroundBuffer();
    void createLevel(char* level);
    int virtInitialiseObjects();
    void setState(char* state);
    char* getState();
    void virtMainLoopPreUpdate();
    void virtKeyDown(int iKeyCode);
    void virtMouseWheel(int x, int y, int which, int timestamp);
    void addEntity(DisplayableObject* entity);
    void removeEntity(DisplayableObject* entity);
    int virtInitialise() override;
    DisplayableObject* getPlayer();
    void nextLevel();
    std::string text = " ";
    std::string newText = " ";
    bool updated = false;
    int textCounter = 0;
    char currentChar;
    virtual void copyAllBackgroundBuffer() override;

protected:
    LevelOne* level1 = new LevelOne(this, getForegroundSurface());
    LevelTwo* level2 = new LevelTwo(this, getForegroundSurface());
    LevelThree* level3 = new LevelThree(this, getForegroundSurface());
    LevelFour* level4 = new LevelFour(this, getForegroundSurface());
    LevelFive* level5 = new LevelFive(this, getForegroundSurface());
    LevelSix* level6 = new LevelSix(this, getForegroundSurface());
    LevelSeven* level7 = new LevelSeven(this, getForegroundSurface());
    LevelEight* level8 = new LevelEight(this, getForegroundSurface());
    LevelNine* level9 = new LevelNine(this, getForegroundSurface());
    LevelTen* level10 = new LevelTen(this, getForegroundSurface());
    PsyhqTileManager* currentLevel = level1;
    int m_iOffset;
    bool animation = false, d1 = false, d2 = false, d3 = false, d4 = false, d5 = false, d6 = false;
    bool gameState = false;
    FilterPointsScaling m_filterScaling;
    FilterPointsTranslation m_filterTranslation;
    
};
