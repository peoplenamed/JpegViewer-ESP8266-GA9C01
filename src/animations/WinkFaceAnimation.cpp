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


boolean WinkFaceAnimation::renderFrame(int frame) {
	switch(frame)
	{
		case 1:
			mouthElement.render(MOUTH_CLOSED);
			eyeLeftElement.render(EYE_OPEN_LR);
			eyeRightElement.render(EYE_OPEN_LR);
			break;
		case 2:
			eyeLeftElement.render(EYE_CLOSING_LR);
			break;
		case 3:
			eyeLeftElement.render(EYE_CLOSED_LR);
			break;
		case 4:
			mouthElement.render(MOUTH_CLOSED);
			eyeLeftElement.render(EYE_CLOSED_LR);
			break;
		case 5:
			eyeLeftElement.render(EYE_CLOSING_LR);
			break;
		case 6:
			eyeLeftElement.render(EYE_OPEN_LR);
			break;
		default:
			return false;
	}
	return true;
}