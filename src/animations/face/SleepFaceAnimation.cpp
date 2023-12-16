/*********************
 *      INCLUDES
 *********************/
#include "SleepFaceAnimation.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
SleepFaceAnimation::SleepFaceAnimation()
	: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
	, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
	, mouthElement(_MOUTH_X, _MOUTH_Y)
	, sleepElement()
{ }


int SleepFaceAnimation::getTotalFrames() {
	return frames;
}

void SleepFaceAnimation::renderFrame(int frame, uint16_t foreground, uint16_t background) {
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
			eyeLeftElement.render(EYE_CLOSED_LR, foreground, background);
			eyeRightElement.render(EYE_CLOSED_LR, foreground, background);
			break;
		case 4:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_CLOSED_LR, foreground, background);
			eyeRightElement.render(EYE_CLOSED_LR, foreground, background);
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
	}
}