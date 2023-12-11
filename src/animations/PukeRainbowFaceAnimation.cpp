/*********************
 *      INCLUDES
 *********************/
#include "PukeRainbowFaceAnimation.h"

/*********************
 *      DEFINES
 *********************/



// Constructor implementation
PukeRainbowFaceAnimation::PukeRainbowFaceAnimation()
	: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
	, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
	, mouthElement(_MOUTH_X, _MOUTH_Y)
{
}

boolean PukeRainbowFaceAnimation::renderFrame(int frame) {
	switch(frame)
	{
		case 1:
			mouthElement.render(MOUTH_CLOSED);
			eyeLeftElement.render(EYE_OPEN_LR);
			eyeRightElement.render(EYE_OPEN_LR);
			break;
		case 2:
			mouthElement.render(MOUTH_SMILE_FILLED);
			break;
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 22:
		case 23:
			this->drawRainbow(frame);
			break;
		case 24:
			mouthElement.render(MOUTH_FANGS_TWO);
			eyeLeftElement.render(EYE_OPEN_LR);
			eyeRightElement.render(EYE_OPEN_LR);
			break;
		case 25:
			mouthElement.render(MOUTH_FANGS_ONE);
			break;
		case 26:
			mouthElement.render(MOUTH_CLOSED);
			break;
		default:
			return false;
	}
	return true;
	// reset();
}

void PukeRainbowFaceAnimation::reset() {
	colorIndex = 0;
}

void PukeRainbowFaceAnimation::drawRainbow(int frame) {
	for(int i = 0; i < 60; i += 5)
	{ // Increment by 5 for 5 pixels wide lines
		int currentColorIndex =
			(frame + i / 5) % numColors; // Divide i by 5 to get the correct color index
		gfx->fillRect(
			_MOUTH_X + (40) + i, _MOUTH_Y + 25, 5, 100, rainbowColors[currentColorIndex]);
	}
	colorIndex = (colorIndex + 1) % numColors;
}