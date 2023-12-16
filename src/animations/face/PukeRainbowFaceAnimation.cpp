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

int PukeRainbowFaceAnimation::getTotalFrames() {
	return frames;
}

void PukeRainbowFaceAnimation::renderFrame(int frame, uint16_t foreground, uint16_t background) {
	switch(frame)
	{
		case 1:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
		case 2:
			mouthElement.render(MOUTH_SMILE_FILLED, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
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
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			this->drawRainbow(frame);
			break;
		case 24:
			mouthElement.render(MOUTH_FANGS_TWO, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
		case 25:
			mouthElement.render(MOUTH_FANGS_ONE, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
		case 26:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
	}
}

void PukeRainbowFaceAnimation::reset() {
	colorIndex = 0;
}

void PukeRainbowFaceAnimation::drawRainbow(int frame) {
	for(int i = 0; i < 60; i += 5)
	{ // Increment by 5 for 5 pixels wide lines
		int currentColorIndex =
			(frame + i / 5) % colorsService.RGB_COLORS_SIZE; // Divide i by 5 to get the correct color index
		gfx->fillRect(
			_MOUTH_X + (40) + i, _MOUTH_Y + 25, 5, 100, colorsService.RGB_COLORS[currentColorIndex].rgb);
	}
	colorIndex = (colorIndex + 1) % colorsService.RGB_COLORS_SIZE;
}