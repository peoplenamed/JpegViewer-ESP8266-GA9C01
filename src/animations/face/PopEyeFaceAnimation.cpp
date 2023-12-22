/*********************
 *      INCLUDES
 *********************/
#include "PopEyeFaceAnimation.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
PopEyeFaceAnimation::PopEyeFaceAnimation()
	: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
	, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
	, mouthElement(_MOUTH_X, _MOUTH_Y)
{ }

int PopEyeFaceAnimation::getTotalFrames() {
	return frames;
}

void PopEyeFaceAnimation::renderFrame(int frame, uint16_t foreground, uint16_t background, bool _drawBackgroundColor) {
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
			eyeLeftElement.render(EYE_POP_ONE_LR, foreground, background, drawBackgroundColor);
			break;
		case 3:
			mouthElement.render(MOUTH_CLOSED, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_POP_TWO_LR, foreground, background, drawBackgroundColor);
			break;
		case 4:
			eyeRightElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			mouthElement.render(MOUTH_CLOSED, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_POP_TWO_LR, foreground, background, drawBackgroundColor);
			break;
		case 5:
			eyeRightElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			mouthElement.render(MOUTH_CLOSED, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_POP_ONE_LR, foreground, background, drawBackgroundColor);
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




// void PopEyeFaceAnimation::renderLoop()
// {
// 	mouthElement.render(MOUTH_CLOSED);

// 	for(int i = 0; i < 3; i++)
// 	{
// 		eyeLeftElement.render(EYE_POP_TWO_LR);
// 		delay(300);
// 		eyeLeftElement.render(EYE_POP_ONE_LR);
// 		delay(300);
// 		eyeLeftElement.render(EYE_OPEN_LR);
// 		eyeRightElement.render(EYE_OPEN_LR);
// 		delay(300);
// 		eyeRightElement.render(EYE_POP_ONE_LR);
// 		delay(300);
// 		eyeRightElement.render(EYE_POP_TWO_LR);
// 		delay(300);
// 		eyeRightElement.render(EYE_POP_ONE_LR);
// 		delay(300);
// 		eyeLeftElement.render(EYE_OPEN_LR);
// 		eyeRightElement.render(EYE_OPEN_LR);
// 		delay(300);
// 		eyeLeftElement.render(EYE_POP_ONE_LR);
// 		delay(300);
// 		eyeLeftElement.render(EYE_POP_TWO_LR);
// 	}
// }