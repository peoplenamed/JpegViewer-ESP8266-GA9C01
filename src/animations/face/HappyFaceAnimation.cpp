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

void HappyFaceAnimation::renderFrame(int frame, uint16_t foreground, uint16_t background, bool _drawBackgroundColor) {
	drawBackgroundColor = _drawBackgroundColor;
	
	switch(frame)
	{
		case 1:
			mouthElement.render(MOUTH_CLOSED, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			break;
		case 2:
			mouthElement.render(MOUTH_SMILE_ONE, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			break;
		case 3:
			mouthElement.render(MOUTH_SMILE_TWO, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			break;
		case 4:
			mouthElement.render(MOUTH_SMILE_TWO, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			break;
		case 5:
			mouthElement.render(MOUTH_SMILE_ONE, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			break;
		case 6:
			mouthElement.render(MOUTH_CLOSED, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			break;
		default:
			break;
	}
}