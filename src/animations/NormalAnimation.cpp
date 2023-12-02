/*********************
 *      INCLUDES
 *********************/
#include "NormalAnimation.h";

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
NormalAnimation::NormalAnimation()
	: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
	, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
	, mouthElement(_MOUTH_X, _MOUTH_Y)
{ }

void NormalAnimation::renderIn()
{
	gfx->fillScreen(BLACK);
	mouthElement.render(MOUTH_CLOSED);
	eyeLeftElement.render(EYE_OPEN_LR);
	eyeRightElement.render(EYE_OPEN_LR);
}

void NormalAnimation::renderOut()
{
	gfx->fillScreen(BLACK);
	mouthElement.render(MOUTH_CLOSED);
	eyeLeftElement.render(EYE_OPEN_LR);
	eyeRightElement.render(EYE_OPEN_LR);
}

void NormalAnimation::renderLoop()
{
	gfx->fillScreen(BLACK);
	mouthElement.render(MOUTH_CLOSED);
	eyeLeftElement.render(EYE_OPEN_LR);
	eyeRightElement.render(EYE_OPEN_LR);
}