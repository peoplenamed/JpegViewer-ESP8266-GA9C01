/*********************
 *      INCLUDES
 *********************/
#include "PukeRainbowFaceAnimation.h";

/*********************
 *      DEFINES
 *********************/

const uint16_t PukeRainbowFaceAnimation::rainbowColors[] = {
	gfx->color565(255, 0, 0), // Red
	gfx->color565(255, 80, 0), // Red-Orange
	gfx->color565(255, 165, 0), // Orange
	gfx->color565(255, 210, 0), // Yellow-Orange
	gfx->color565(255, 255, 0), // Yellow
	gfx->color565(128, 255, 0), // Yellow-Green
	gfx->color565(0, 128, 0), // Green
	gfx->color565(0, 128, 128), // Green-Blue
	gfx->color565(0, 0, 255), // Blue
	gfx->color565(75, 0, 255), // Blue-Indigo
	gfx->color565(75, 0, 130), // Indigo
	gfx->color565(143, 0, 255), // Indigo-Violet
	gfx->color565(238, 130, 238) // Violet
};

// Constructor implementation
PukeRainbowFaceAnimation::PukeRainbowFaceAnimation()
	: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
	, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
	, mouthElement(_MOUTH_X, _MOUTH_Y)
{ }

void PukeRainbowFaceAnimation::renderIn()
{
	mouthElement.render(MOUTH_CLOSED);
	eyeLeftElement.render(EYE_OPEN_LR);
	eyeRightElement.render(EYE_OPEN_LR);
	delay(300);

	int numColors = sizeof(rainbowColors) / sizeof(rainbowColors[0]);
	int colorIndex = 0;

	mouthElement.render(MOUTH_SMILE_FILLED);
	while(true)
	{ // Replace with a condition to stop the loop as needed
		for(int i = 0; i < 60; i += 5)
		{ // Increment by 5 for 5 pixels wide lines
			int currentColorIndex =
				(colorIndex + i / 5) % numColors; // Divide i by 5 to get the correct color index
			gfx->fillRect(
				_MOUTH_X + (40) + i, _MOUTH_Y + 25, 5, 100, rainbowColors[currentColorIndex]);
		}
		colorIndex = (colorIndex + 1) % numColors;
		delay(100);
	}
}

void PukeRainbowFaceAnimation::renderOut()
{

	mouthElement.render(MOUTH_FANGS_TWO);
	eyeLeftElement.render(EYE_OPEN_LR);
	eyeRightElement.render(EYE_OPEN_LR);
	delay(300);

	mouthElement.render(MOUTH_FANGS_ONE);
	delay(300);
	mouthElement.render(MOUTH_CLOSED);
}

void PukeRainbowFaceAnimation::renderLoop()
{
	eyeLeftElement.render(EYE_OPEN_LR);
	eyeRightElement.render(EYE_OPEN_LR);

	int num = globalAniumationState.animationState.toInt();
}