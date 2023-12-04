/*********************
 *      INCLUDES
 *********************/
#include "HappyFaceAnimation.h";

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
HappyFaceAnimation::HappyFaceAnimation()
	: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
	, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
	, mouthElement(_MOUTH_X, _MOUTH_Y)
{ }

void HappyFaceAnimation::renderIn()
{
	mouthElement.render(MOUTH_CLOSED);
	eyeLeftElement.render(EYE_OPEN_LR);
	eyeRightElement.render(EYE_OPEN_LR);
	delay(300);

	mouthElement.render(MOUTH_SMILE_ONE);
	delay(300);
	mouthElement.render(MOUTH_SMILE_TWO);
}

void HappyFaceAnimation::renderOut()
{

	mouthElement.render(MOUTH_SMILE_TWO);
	eyeLeftElement.render(EYE_OPEN_LR);
	eyeRightElement.render(EYE_OPEN_LR);
	delay(300);
	mouthElement.render(MOUTH_SMILE_ONE);
	delay(300);
	mouthElement.render(MOUTH_CLOSED);
}

void HappyFaceAnimation::renderLoop()
{
	eyeLeftElement.render(EYE_OPEN_LR);
	eyeRightElement.render(EYE_OPEN_LR);
	mouthElement.render(MOUTH_SMILE_TWO);
}