/*********************
 *      INCLUDES
 *********************/
#include "FangFaceAnimation.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
FangFaceAnimation::FangFaceAnimation()
	: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
	, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
	, mouthElement(_MOUTH_X, _MOUTH_Y)
{ }
boolean FangFaceAnimation::renderFrame(int frame) {
	switch(frame)
	{
		case 1:
			mouthElement.render(MOUTH_CLOSED);
			eyeLeftElement.render(EYE_OPEN_LR);
			eyeRightElement.render(EYE_OPEN_LR);
			break;
		case 2:
			mouthElement.render(MOUTH_FANGS_ONE);
			break;
		case 3:
			mouthElement.render(MOUTH_FANGS_TWO);
			break;
		case 4:
			mouthElement.render(MOUTH_FANGS_TWO);
			eyeLeftElement.render(EYE_OPEN_LR);
			eyeRightElement.render(EYE_OPEN_LR);
			break;
		case 5:
			mouthElement.render(MOUTH_FANGS_ONE);
			break;
		case 6:
			mouthElement.render(MOUTH_CLOSED);
			break;
		default:
			return true;
			break;
	}
	return false;
}
