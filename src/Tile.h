#pragma once
#include "SimpleImage.h"
#include "ImageManager.h"
class Tile
{
public:
	int x, y;
	int value;
	SimpleImage image;
	Tile(int x, int y) {
		x = x;
		y = y;
	}

	int getX();
	int getY();
	int getValue();
	SimpleImage getImage();
	void setX(int x);
	void setY(int y);
	

};

