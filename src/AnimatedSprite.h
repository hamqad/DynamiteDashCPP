#include "SimpleImage.h"
#include "ImageManager.h"
#pragma once
class AnimatedSprite
{
public:
	AnimatedSprite(SimpleImage iOne, SimpleImage iTwo, SimpleImage iThree) {
		currentImage = iOne;
		one = iOne;
		two = iTwo;
		three = iThree;
		
	}

protected:
	int frame = 0;
	int rate = 5;
	int time = 0;
	int length = 3;
	SimpleImage currentImage;
	SimpleImage one;
	SimpleImage two;
	SimpleImage three;

public:
	void update();
	SimpleImage getSprite();
	void setFrameRate(int frames);
	void setFrame(int index);
	int getFrame();



};

