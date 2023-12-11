/*********************
 *      INCLUDES
 *********************/
#include "NormalAnimation.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
NormalAnimation::NormalAnimation()
	: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
	, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
	, mouthElement(_MOUTH_X, _MOUTH_Y)
{ }

boolean NormalAnimation::renderFrame(int frame) {
	switch(frame)
	{
		case 1:
			mouthElement.render(MOUTH_CLOSED);
			eyeLeftElement.render(EYE_OPEN_LR);
			eyeRightElement.render(EYE_OPEN_LR);
			break;
		case 2:
			mouthElement.render(MOUTH_CLOSED);
			eyeLeftElement.render(EYE_OPEN_LR);
			eyeRightElement.render(EYE_OPEN_LR);
			break;
		default:
			return true;
			break;
	}
	return false;
}