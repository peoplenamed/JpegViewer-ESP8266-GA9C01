/*********************
 *      INCLUDES
 *********************/
#include "DizzyFaceAnimation.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
DizzyFaceAnimation::DizzyFaceAnimation()
	: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
	, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
	, mouthElement(_MOUTH_X, _MOUTH_Y)
{ }

int DizzyFaceAnimation::getTotalFrames() {
	return frames;
}

void DizzyFaceAnimation::renderFrame(int frame, uint16_t foreground, uint16_t background) {
	switch(frame)
	{
		case 1:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
		case 2:
		case 6:
		case 10:
		case 14:
		case 18:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_SPIRAL_ONE_LR, foreground, background);
			eyeRightElement.render(EYE_SPIRAL_ONE_LR, foreground, background);
			break;
		case 3:
		case 7:
		case 11:
		case 15:
		case 19:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_SPIRAL_TWO_LR, foreground, background);
			eyeRightElement.render(EYE_SPIRAL_TWO_LR, foreground, background);
			break;
		case 4:
		case 8:
		case 12:
		case 16:
		case 20:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_SPIRAL_THREE_LR, foreground, background);
			eyeRightElement.render(EYE_SPIRAL_THREE_LR, foreground, background);
			break;
		case 5:
		case 9:
		case 13:
		case 17:
		case 21:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_SPIRAL_FOUR_LR, foreground, background);
			eyeRightElement.render(EYE_SPIRAL_FOUR_LR, foreground, background);
			break;
		case 22:
		case 26:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_CLOSING_LR, foreground, background);
			eyeRightElement.render(EYE_CLOSING_LR, foreground, background);
			break;
		case 23:
		case 27:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_CLOSED_LR, foreground, background);
			eyeRightElement.render(EYE_CLOSED_LR, foreground, background);
			break;
		case 24:
		case 28:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_CLOSING_LR, foreground, background);
			eyeRightElement.render(EYE_CLOSING_LR, foreground, background);
			break;
		case 25:
		case 29:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
		case 30:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
		case 31:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
		default:
			break;
	}
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