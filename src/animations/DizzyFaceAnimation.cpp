/*********************
 *      INCLUDES
 *********************/
#include "DizzyFaceAnimation.h";

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
DizzyFaceAnimation::DizzyFaceAnimation()
	: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
	, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
	, mouthElement(_MOUTH_X, _MOUTH_Y)
{ }

void DizzyFaceAnimation::renderIn()
{
	gfx->fillScreen(BLACK);

	eyeLeftElement.render(EYE_OPEN_LR);
	eyeRightElement.render(EYE_OPEN_LR);

	for(int i = 0; i < 5; i++)
	{
		eyeLeftElement.render(EYE_SPIRAL_ONE_LR);
		eyeRightElement.render(EYE_SPIRAL_ONE_LR);
		delay(100);
		eyeLeftElement.render(EYE_SPIRAL_TWO_LR);
		eyeRightElement.render(EYE_SPIRAL_TWO_LR);
		delay(100);
		eyeLeftElement.render(EYE_SPIRAL_THREE_LR);
		eyeRightElement.render(EYE_SPIRAL_THREE_LR);
		delay(100);
		eyeLeftElement.render(EYE_SPIRAL_FOUR_LR);
		eyeRightElement.render(EYE_SPIRAL_FOUR_LR);
		delay(100);
	}
	for(int i = 0; i < 2; i++)
	{
		eyeLeftElement.render(EYE_CLOSING_LR);
		eyeRightElement.render(EYE_CLOSING_LR);
		delay(200);
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
	mouthElement.render(MOUTH_CLOSED);
	eyeLeftElement.render(EYE_OPEN_LR);
	eyeRightElement.render(EYE_OPEN_LR);
}

void DizzyFaceAnimation::renderOut()
{
	gfx->fillScreen(BLACK);
	mouthElement.render(MOUTH_CLOSED);
	eyeLeftElement.render(EYE_OPEN_LR);
	eyeRightElement.render(EYE_OPEN_LR);
}

void DizzyFaceAnimation::renderLoop()
{
	gfx->fillScreen(BLACK);
	mouthElement.render(MOUTH_CLOSED);
	eyeLeftElement.render(EYE_OPEN_LR);
	eyeRightElement.render(EYE_OPEN_LR);
}

EyeType DizzyFaceAnimation::getRandomEyeType()
{
	// Array of EyeType values ending with '_LR'
	EyeType lrTypes[] = {EYE_OPEN_LR,
						 EYE_DISAPPOINTED_LR,
						 EYE_SATISFIED_LR,
						 EYE_DIAMOND_LR,
						 EYE_CLOSING_LR,
						 EYE_CLOSED_LR};

	// Size of the lrTypes array
	int numTypes = sizeof(lrTypes) / sizeof(lrTypes[0]);

	// Generate a random index
	int randomIndex = random(numTypes);

	return lrTypes[randomIndex];
}