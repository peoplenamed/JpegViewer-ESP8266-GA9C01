/*********************
 *      INCLUDES
 *********************/
#include "NormalAnimation.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
NormalAnimation::NormalAnimation()
	: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
	, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
	, mouthElement(_MOUTH_X, _MOUTH_Y)
{ }

int NormalAnimation::getTotalFrames() {
	return frames;
}

void NormalAnimation::renderFrame(int frame, uint16_t foreground, uint16_t background) {
	switch(frame)
	{
		case 1:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
		case 2:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
		default:
			break;
	}
}

void NormalAnimation::getPixels(Pixel *&pixels, int frame, uint16_t foreground, uint16_t background) {
	switch(frame)
	{
		case 1:
			mouthElement.getPixels(*&pixels, MOUTH_CLOSED, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			break;
		case 2:
			mouthElement.getPixels(*&pixels, MOUTH_CLOSED, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			break;
		default:
			break;
	}
}
