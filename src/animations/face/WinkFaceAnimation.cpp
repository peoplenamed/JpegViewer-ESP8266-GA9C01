/*********************
 *      INCLUDES
 *********************/
#include "WinkFaceAnimation.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
WinkFaceAnimation::WinkFaceAnimation()
	: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
	, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
	, mouthElement(_MOUTH_X, _MOUTH_Y)
{ }


void WinkFaceAnimation::renderFrame(int frame, uint16_t foreground, uint16_t background) {
	switch(frame)
	{
		case 1:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
		case 2:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			eyeLeftElement.render(EYE_CLOSING_LR, foreground, background);
			break;
		case 3:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			eyeLeftElement.render(EYE_CLOSED_LR, foreground, background);
			break;
		case 4:
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_CLOSED_LR, foreground, background);
			break;
		case 5:
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_CLOSING_LR, foreground, background);
			break;
		case 6:
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			break;
	}
}

int WinkFaceAnimation::getTotalFrames() {
	return frames;
}

void WinkFaceAnimation::getPixels(Pixel *&pixels, int frame, uint16_t foreground, uint16_t background) {
	switch(frame)
	{
		case 1:
			mouthElement.getPixels(*&pixels, MOUTH_CLOSED, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			break;
		case 2:
			mouthElement.getPixels(*&pixels, MOUTH_CLOSED, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_CLOSING_LR, foreground, background);
			break;
		case 3:
			mouthElement.getPixels(*&pixels, MOUTH_CLOSED, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_CLOSED_LR, foreground, background);
			break;
		case 4:
			eyeRightElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			mouthElement.getPixels(*&pixels, MOUTH_CLOSED, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_CLOSED_LR, foreground, background);
			break;
		case 5:
			eyeRightElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			mouthElement.getPixels(*&pixels, MOUTH_CLOSED, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_CLOSING_LR, foreground, background);
			break;
		case 6:
			eyeRightElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			mouthElement.getPixels(*&pixels, MOUTH_CLOSED, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			break;
	}
}
