/*********************
 *      INCLUDES
 *********************/
#include "SatisfiedFaceAnimation.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
SatisfiedFaceAnimation::SatisfiedFaceAnimation()
	: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
	, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
	, mouthElement(_MOUTH_X, _MOUTH_Y)
{ }

boolean SatisfiedFaceAnimation::renderFrame(int frame) {
	switch(frame)
	{
		case 1:
			mouthElement.render(MOUTH_CLOSED);
			eyeLeftElement.render(EYE_OPEN_LR);
			eyeRightElement.render(EYE_OPEN_LR);
			break;
		case 2:
			eyeLeftElement.render(EYE_SATISFIED_LR);
			eyeRightElement.render(EYE_SATISFIED_LR);
			break;
		case 3:
			mouthElement.render(MOUTH_CLOSED);
			eyeLeftElement.render(EYE_SATISFIED_LR);
			eyeRightElement.render(EYE_SATISFIED_LR);
			break;
		case 4:
			eyeLeftElement.render(EYE_OPEN_LR);
			eyeRightElement.render(EYE_OPEN_LR);
			break;
		default:
			return false;
	}
	return true;
}