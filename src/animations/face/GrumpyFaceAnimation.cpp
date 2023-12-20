/*********************
 *      INCLUDES
 *********************/
#include "GrumpyFaceAnimation.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
GrumpyFaceAnimation::GrumpyFaceAnimation()
	: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
	, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
	, mouthElement(_MOUTH_X, _MOUTH_Y)
{ }

int GrumpyFaceAnimation::getTotalFrames() {
	return frames;
}

void GrumpyFaceAnimation::renderFrame(int frame, uint16_t foreground, uint16_t background) {
	switch(frame)
	{
		case 1:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_DISAPPOINTED_LR, foreground, background);
			eyeRightElement.render(EYE_DISAPPOINTED_LR, foreground, background);
		case 2:
			mouthElement.render(MOUTH_GRUMPY_ONE, foreground, background);
			eyeLeftElement.render(EYE_DISAPPOINTED_LR, foreground, background);
			eyeRightElement.render(EYE_DISAPPOINTED_LR, foreground, background);
			break;
		case 3:
			mouthElement.render(MOUTH_GRUMPY_TWO, foreground, background);
			eyeLeftElement.render(EYE_DISAPPOINTED_LR, foreground, background);
			eyeRightElement.render(EYE_DISAPPOINTED_LR, foreground, background);
			break;
		case 4:
			mouthElement.render(MOUTH_GRUMPY_ONE, foreground, background);
			eyeLeftElement.render(EYE_DISAPPOINTED_LR, foreground, background);
			eyeRightElement.render(EYE_DISAPPOINTED_LR, foreground, background);
			break;
		case 5:
			mouthElement.render(MOUTH_GRUMPY_TWO, foreground, background);
			eyeLeftElement.render(EYE_DISAPPOINTED_LR, foreground, background);
			eyeRightElement.render(EYE_DISAPPOINTED_LR, foreground, background);
			break;
		case 6:
			mouthElement.render(MOUTH_GRUMPY_ONE, foreground, background);
			eyeLeftElement.render(EYE_DISAPPOINTED_LR, foreground, background);
			eyeRightElement.render(EYE_DISAPPOINTED_LR, foreground, background);
			break;
		case 7:
			mouthElement.render(MOUTH_GRUMPY_TWO, foreground, background);
			eyeLeftElement.render(EYE_DISAPPOINTED_LR, foreground, background);
			eyeRightElement.render(EYE_DISAPPOINTED_LR, foreground, background);
			break;
		case 8:
			mouthElement.render(MOUTH_GRUMPY_ONE, foreground, background);
			eyeLeftElement.render(EYE_DISAPPOINTED_LR, foreground, background);
			eyeRightElement.render(EYE_DISAPPOINTED_LR, foreground, background);
			break;
		case 9:
			mouthElement.render(MOUTH_GRUMPY_TWO, foreground, background);
			eyeLeftElement.render(EYE_DISAPPOINTED_LR, foreground, background);
			eyeRightElement.render(EYE_DISAPPOINTED_LR, foreground, background);
			break;
		case 10:
			mouthElement.render(MOUTH_GRUMPY_TWO, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
		case 11:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_DISAPPOINTED_LR, foreground, background);
			eyeRightElement.render(EYE_DISAPPOINTED_LR, foreground, background);
			break;
		default:
			break;
	}
}

void GrumpyFaceAnimation::getPixels(Pixel *&pixels, int frame, uint16_t foreground, uint16_t background) {
	switch(frame)
	{
		case 1:
			mouthElement.getPixels(*&pixels, MOUTH_CLOSED, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_DISAPPOINTED_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_DISAPPOINTED_LR, foreground, background);
		case 2:
			mouthElement.getPixels(*&pixels, MOUTH_GRUMPY_ONE, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_DISAPPOINTED_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_DISAPPOINTED_LR, foreground, background);
			break;
		case 3:
			mouthElement.getPixels(*&pixels, MOUTH_GRUMPY_TWO, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_DISAPPOINTED_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_DISAPPOINTED_LR, foreground, background);
			break;
		case 4:
			mouthElement.getPixels(*&pixels, MOUTH_GRUMPY_ONE, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_DISAPPOINTED_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_DISAPPOINTED_LR, foreground, background);
			break;
		case 5:
			mouthElement.getPixels(*&pixels, MOUTH_GRUMPY_TWO, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_DISAPPOINTED_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_DISAPPOINTED_LR, foreground, background);
			break;
		case 6:
			mouthElement.getPixels(*&pixels, MOUTH_GRUMPY_ONE, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_DISAPPOINTED_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_DISAPPOINTED_LR, foreground, background);
			break;
		case 7:
			mouthElement.getPixels(*&pixels, MOUTH_GRUMPY_TWO, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_DISAPPOINTED_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_DISAPPOINTED_LR, foreground, background);
			break;
		case 8:
			mouthElement.render(MOUTH_GRUMPY_ONE, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_DISAPPOINTED_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_DISAPPOINTED_LR, foreground, background);
			break;
		case 9:
			mouthElement.getPixels(*&pixels, MOUTH_GRUMPY_TWO, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_DISAPPOINTED_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_DISAPPOINTED_LR, foreground, background);
			break;
		case 10:
			mouthElement.getPixels(*&pixels, MOUTH_GRUMPY_TWO, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			break;
		case 11:
			mouthElement.getPixels(*&pixels, MOUTH_CLOSED, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_DISAPPOINTED_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_DISAPPOINTED_LR, foreground, background);
			break;
		default:
			break;
	}
}