#pragma once
#include "DisplayableObject.h"
#include "PsyhqTileManager.h"
#include "PsyhqEngine.h"
class Entity :
    public DisplayableObject
{
public:
    PsyhqEngine* engine;
    PsyhqTileManager* m_pTileManager;
    Entity(BaseEngine* pEngine, int x, int y, PsyhqTileManager* manager)
        : DisplayableObject(pEngine)
    {
        m_pTileManager = manager;
        engine = (PsyhqEngine*)getEngine();
        m_iCurrentScreenX = x;
        m_iCurrentScreenY = y;
        tileManager = manager;
    }
    PsyhqTileManager* tileManager;
    SimpleImage image;
    void setImage(SimpleImage Image);
    void reset();
    int getX();
    int getY();
protected:
    void virtDraw();
    void virtDoUpdate(int iCurrentTime);
    SimpleImage getImage();
    bool removed;
};
