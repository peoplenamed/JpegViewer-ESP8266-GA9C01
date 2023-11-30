/*********************
 *      INCLUDES
 *********************/
#include "FangFaceAnimation.h";

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
FangFaceAnimation::FangFaceAnimation()
	: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
	, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
	, mouthElement(_MOUTH_X, _MOUTH_Y)
{ }

void FangFaceAnimation::renderIn()
{
	mouthElement.render(MOUTH_CLOSED);
	eyeLeftElement.render(EYE_OPEN_LR);
	eyeRightElement.render(EYE_OPEN_LR);
	delay(300);

	mouthElement.render(MOUTH_FANGS_ONE);
	delay(300);
	mouthElement.render(MOUTH_FANGS_TWO);
}

void FangFaceAnimation::renderOut()
{

	mouthElement.render(MOUTH_FANGS_TWO);
	eyeLeftElement.render(EYE_OPEN_LR);
	eyeRightElement.render(EYE_OPEN_LR);
	delay(300);

	mouthElement.render(MOUTH_FANGS_ONE);
	delay(300);
	mouthElement.render(MOUTH_CLOSED);
}

void FangFaceAnimation::renderLoop()
{
	mouthElement.render(MOUTH_FANGS_TWO);
	eyeLeftElement.render(EYE_OPEN_LR);
	eyeRightElement.render(EYE_OPEN_LR);
	delay(300);
	mouthElement.render(MOUTH_FANGS_ONE);
	delay(300);
	mouthElement.render(MOUTH_FANGS_TWO);
}