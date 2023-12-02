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

	gfx->fillRect(_EYE_RIGHT_X, _EYE_RIGHT_Y + (54 / 2), 53, 6, WHITE);
	gfx->fillRect(_MOUTH_X, _MOUTH_Y + 20, 116, 6, WHITE);

	mouthElement.render(MOUTH_CLOSED);

	eyeLeftElement.render(EYE_CLOSED_LR);
	eyeRightElement.render(EYE_CLOSED_LR);
	delay(200);
	sleepElement.render(_EYE_RIGHT_X + 45, _EYE_RIGHT_Y - 10);
	delay(1000);
	sleepElement.render(_EYE_RIGHT_X + 55, _EYE_RIGHT_Y - 25);
	delay(1000);
	sleepElement.render(_EYE_RIGHT_X + 65, _EYE_RIGHT_Y - 40);
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