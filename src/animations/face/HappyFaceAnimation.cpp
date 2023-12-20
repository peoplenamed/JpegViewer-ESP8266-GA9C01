/*********************
 *      INCLUDES
 *********************/
#include "HappyFaceAnimation.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
HappyFaceAnimation::HappyFaceAnimation()
	: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
	, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
	, mouthElement(_MOUTH_X, _MOUTH_Y)
{ }

int HappyFaceAnimation::getTotalFrames() {
	return frames;
}

void HappyFaceAnimation::renderFrame(int frame, uint16_t foreground, uint16_t background) {
	switch(frame)
	{
		case 1:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
		case 2:
			mouthElement.render(MOUTH_SMILE_ONE, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
		case 3:
			mouthElement.render(MOUTH_SMILE_TWO, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
		case 4:
			mouthElement.render(MOUTH_SMILE_TWO, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
		case 5:
			mouthElement.render(MOUTH_SMILE_ONE, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
		case 6:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
		default:
			break;
	}
}

void HappyFaceAnimation::getPixels(Pixel *&pixels, int frame, uint16_t foreground, uint16_t background) {
	switch(frame)
	{
		case 1:
			mouthElement.getPixels(*&pixels, MOUTH_CLOSED, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			break;
		case 2:
			mouthElement.getPixels(*&pixels, MOUTH_SMILE_ONE, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			break;
		case 3:
			mouthElement.getPixels(*&pixels, MOUTH_SMILE_TWO, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			break;
		case 4:
			mouthElement.getPixels(*&pixels, MOUTH_SMILE_TWO, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			break;
		case 5:
			mouthElement.getPixels(*&pixels, MOUTH_SMILE_ONE, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			break;
		case 6:
			mouthElement.getPixels(*&pixels, MOUTH_CLOSED, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			break;
		default:
			break;
	}
}