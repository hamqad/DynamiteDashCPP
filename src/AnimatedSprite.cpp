#include "header.h"
#include "AnimatedSprite.h"

void AnimatedSprite::update() {
	time++; // Increments the time value each time the cycle updates
	if (time % rate == 0) { // Loops through the animation at the specified rate
		//if (frame >= length - 1) {
		//	frame = 0; // Resets the frames when it has exceeded the length of the animation
		//}
		//else {
		//	frame++; // Goes to the next frame
		//}
		
		if (currentImage.getImageURL() == one.getImageURL()) {
			currentImage = two;
		}
		else if (currentImage.getImageURL() == two.getImageURL()) {
			currentImage = three;
		}
		else {
			currentImage = one;
		}
	}
}

SimpleImage AnimatedSprite::getSprite() {
	return currentImage;
}

void AnimatedSprite::setFrameRate(int frames) {
	rate = frames;
}

void AnimatedSprite::setFrame(int index) {
	frame = index;
	if (frame == 1) currentImage = one;
	else if (frame == 2) currentImage = two;
	else currentImage = three;
	
}

int AnimatedSprite::getFrame() {
	return frame;
}
