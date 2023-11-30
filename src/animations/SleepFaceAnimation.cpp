/*********************
 *      INCLUDES
 *********************/
#include "SleepFaceAnimation.h";

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
SleepFaceAnimation::SleepFaceAnimation()
	: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
	, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
	, mouthElement(_MOUTH_X, _MOUTH_Y)
	, sleepElement()
{ }

void SleepFaceAnimation::renderIn()
{

	gfx->fillScreen(BLACK);
	gfx->drawEllipse(_MOUTH_X, _MOUTH_Y, 20, 10, WHITE);
	delay(5000);

	mouthElement.render(MOUTH_CLOSED);

	eyeLeftElement.render(EYE_OPEN_LR);
	eyeRightElement.render(EYE_OPEN_LR);
	delay(200);

	eyeLeftElement.render(EYE_CLOSING_LR);
	eyeRightElement.render(EYE_CLOSING_LR);
	delay(200);

	eyeLeftElement.render(EYE_CLOSED_LR);
	eyeRightElement.render(EYE_CLOSED_LR);
	delay(200);
}

void SleepFaceAnimation::renderLoop()
{
	gfx->fillScreen(BLACK);
	mouthElement.render(MOUTH_CLOSED);

	eyeLeftElement.render(EYE_CLOSED_LR);
	eyeRightElement.render(EYE_CLOSED_LR);
	delay(200);
	sleepElement.render(_EYE_RIGHT_X + 45, _EYE_RIGHT_Y - 10);
	delay(1000);
	sleepElement.render(_EYE_RIGHT_X + 55, _EYE_RIGHT_Y - 25);
	delay(1000);
	sleepElement.render(_EYE_RIGHT_X + 65, _EYE_RIGHT_Y - 40);
	// sleepElement.render(_EYE_RIGHT_X + 10, _EYE_RIGHT_Y + 15);
	delay(2000);
}

void SleepFaceAnimation::renderOut()
{
	gfx->fillScreen(BLACK);
	mouthElement.render(MOUTH_CLOSED);

	eyeLeftElement.render(EYE_CLOSED_LR);
	eyeRightElement.render(EYE_CLOSED_LR);
	delay(200);

	eyeLeftElement.render(EYE_CLOSING_LR);
	eyeRightElement.render(EYE_CLOSING_LR);
	delay(200);

	eyeLeftElement.render(EYE_OPEN_LR);
	eyeRightElement.render(EYE_OPEN_LR);
	delay(200);
}