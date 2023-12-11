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

boolean GrumpyFaceAnimation::renderFrame(int frame) {
	switch(frame)
	{
		case 1:
			mouthElement.render(MOUTH_CLOSED);
			eyeLeftElement.render(EYE_DISAPPOINTED_LR);
			eyeRightElement.render(EYE_DISAPPOINTED_LR);
			mouthElement.render(MOUTH_GRUMPY_ONE);
			break;
		case 2:
			mouthElement.render(MOUTH_GRUMPY_TWO);
			break;
		case 3:
			mouthElement.render(MOUTH_GRUMPY_ONE);
			break;
		case 4:
			mouthElement.render(MOUTH_GRUMPY_TWO);
			break;
		case 5:
			mouthElement.render(MOUTH_GRUMPY_ONE);
			break;
		case 6:
			mouthElement.render(MOUTH_GRUMPY_TWO);
			break;
		case 7:
			mouthElement.render(MOUTH_GRUMPY_ONE);
			break;
		case 8:
			mouthElement.render(MOUTH_GRUMPY_TWO);
			break;
		case 9:
			mouthElement.render(MOUTH_GRUMPY_TWO);
			eyeLeftElement.render(EYE_OPEN_LR);
			eyeRightElement.render(EYE_OPEN_LR);
			break;
		case 10:
			mouthElement.render(MOUTH_CLOSED);
			break;
		default:
			return true;
			break;
	}
	return false;
}