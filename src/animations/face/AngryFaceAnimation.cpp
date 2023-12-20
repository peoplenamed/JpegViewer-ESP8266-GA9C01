/*********************
 *      INCLUDES
 *********************/
#include "AngryFaceAnimation.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
AngryFaceAnimation::AngryFaceAnimation()
	: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
	, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
	, mouthElement(_MOUTH_X, _MOUTH_Y)
{ }

int AngryFaceAnimation::getTotalFrames() {
	return frames;
}

void AngryFaceAnimation::renderFrame(int frame, uint16_t foreground, uint16_t background) {
	switch(frame)
	{
		case 1:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
		case 2:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_CLOSING_LR, foreground, background);
			eyeRightElement.render(EYE_CLOSING_LR, foreground, background);
			break;
		case 3:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_ANGRY_L, foreground, background);
			eyeRightElement.render(EYE_ANGRY_R, foreground, background);
			break;
		case 4:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_ANGRY_L, foreground, background);
			eyeRightElement.render(EYE_ANGRY_R, foreground, background);
			break;
		case 5:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_CLOSING_LR, foreground, background);
			eyeRightElement.render(EYE_CLOSING_LR, foreground, background);
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

void AngryFaceAnimation::getPixels(Pixel *&pixels, int frame, uint16_t foreground, uint16_t background) {
	switch(frame)
	{
		case 1:
			mouthElement.getPixels(*&pixels, MOUTH_CLOSED, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_OPEN_LR, foreground, background);
			break;
		case 2:
			mouthElement.getPixels(*&pixels, MOUTH_CLOSED, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_CLOSING_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_CLOSING_LR, foreground, background);
			break;
		case 3:
			mouthElement.getPixels(*&pixels, MOUTH_CLOSED, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_ANGRY_L, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_ANGRY_R, foreground, background);
			break;
		case 4:
			mouthElement.getPixels(*&pixels, MOUTH_CLOSED, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_ANGRY_L, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_ANGRY_R, foreground, background);
			break;
		case 5:
			mouthElement.getPixels(*&pixels, MOUTH_CLOSED, foreground, background);
			eyeLeftElement.getPixels(*&pixels, EYE_CLOSING_LR, foreground, background);
			eyeRightElement.getPixels(*&pixels, EYE_CLOSING_LR, foreground, background);
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
