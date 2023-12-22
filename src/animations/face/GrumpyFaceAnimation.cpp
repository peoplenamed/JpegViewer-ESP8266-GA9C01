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

void GrumpyFaceAnimation::renderFrame(int frame, uint16_t foreground, uint16_t background, bool _drawBackgroundColor) {
	drawBackgroundColor = _drawBackgroundColor;
	
	switch(frame)
	{
		case 1:
			mouthElement.render(MOUTH_CLOSED, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_DISAPPOINTED_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_DISAPPOINTED_LR, foreground, background, drawBackgroundColor);
		case 2:
			mouthElement.render(MOUTH_GRUMPY_ONE, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_DISAPPOINTED_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_DISAPPOINTED_LR, foreground, background, drawBackgroundColor);
			break;
		case 3:
			mouthElement.render(MOUTH_GRUMPY_TWO, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_DISAPPOINTED_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_DISAPPOINTED_LR, foreground, background, drawBackgroundColor);
			break;
		case 4:
			mouthElement.render(MOUTH_GRUMPY_ONE, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_DISAPPOINTED_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_DISAPPOINTED_LR, foreground, background, drawBackgroundColor);
			break;
		case 5:
			mouthElement.render(MOUTH_GRUMPY_TWO, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_DISAPPOINTED_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_DISAPPOINTED_LR, foreground, background, drawBackgroundColor);
			break;
		case 6:
			mouthElement.render(MOUTH_GRUMPY_ONE, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_DISAPPOINTED_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_DISAPPOINTED_LR, foreground, background, drawBackgroundColor);
			break;
		case 7:
			mouthElement.render(MOUTH_GRUMPY_TWO, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_DISAPPOINTED_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_DISAPPOINTED_LR, foreground, background, drawBackgroundColor);
			break;
		case 8:
			mouthElement.render(MOUTH_GRUMPY_ONE, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_DISAPPOINTED_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_DISAPPOINTED_LR, foreground, background, drawBackgroundColor);
			break;
		case 9:
			mouthElement.render(MOUTH_GRUMPY_TWO, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_DISAPPOINTED_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_DISAPPOINTED_LR, foreground, background, drawBackgroundColor);
			break;
		case 10:
			mouthElement.render(MOUTH_GRUMPY_TWO, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			break;
		case 11:
			mouthElement.render(MOUTH_CLOSED, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_DISAPPOINTED_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_DISAPPOINTED_LR, foreground, background, drawBackgroundColor);
			break;
		default:
			break;
	}
}