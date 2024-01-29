#pragma once
#include "DisplayableObject.h"
class scoreObject :
    public DisplayableObject
{
public:
    char* text = "SCORE = 0";
    scoreObject(BaseEngine* pEngine)
        : DisplayableObject(pEngine)
    {
        m_iCurrentScreenX = 800; // Starting position on the screen
        m_iCurrentScreenY = 700;
        m_iDrawWidth = 200; // Width of drawing area
        m_iDrawHeight = 60; // Height ob drawing area
    }
    void virtDraw();
    void virtDoUpdate(int iCurrentTime);
};

