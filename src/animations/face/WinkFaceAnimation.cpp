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


void WinkFaceAnimation::renderFrame(int frame, uint16_t foreground, uint16_t background, bool _drawBackgroundColor) {
	drawBackgroundColor = _drawBackgroundColor;
	
	switch(frame)
	{
		case 1:
			mouthElement.render(MOUTH_CLOSED, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			break;
		case 2:
			mouthElement.render(MOUTH_CLOSED, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_CLOSING_LR, foreground, background, drawBackgroundColor);
			break;
		case 3:
			mouthElement.render(MOUTH_CLOSED, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_CLOSED_LR, foreground, background, drawBackgroundColor);
			break;
		case 4:
			eyeRightElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			mouthElement.render(MOUTH_CLOSED, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_CLOSED_LR, foreground, background, drawBackgroundColor);
			break;
		case 5:
			eyeRightElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			mouthElement.render(MOUTH_CLOSED, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_CLOSING_LR, foreground, background, drawBackgroundColor);
			break;
		case 6:
			eyeRightElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			mouthElement.render(MOUTH_CLOSED, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			break;
	}
}

int WinkFaceAnimation::getTotalFrames() {
	return frames;
}