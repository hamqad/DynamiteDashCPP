#pragma once
#include "DisplayableObject.h"
#include "PsyhqTileManager.h"
#include "PsyhqEngine.h"



class MenuButton :
    public DisplayableObject
{
  
protected:
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
    char* state = "test";
public:
    
    MenuButton(BaseEngine* bEngine, int xx, int yy, int iWidth, int iHeight, char* iState)
        : DisplayableObject(bEngine)
    {
        x = xx;
        y = yy;
        width = iWidth;
        height = iHeight;
        state = iState;
    }
    void virtDraw();
    void virtDoUpdate(int iCurrentTime);
    void virtMouseDown(int iButton, int iX, int iY);
    
};

