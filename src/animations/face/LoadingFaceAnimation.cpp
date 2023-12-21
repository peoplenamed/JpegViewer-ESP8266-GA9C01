/*********************
 *      INCLUDES
 *********************/
#include "LoadingFaceAnimation.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation


int LoadingFaceAnimation::getTotalFrames() {
	return frames;
}

void LoadingFaceAnimation::renderFrame(int frame, uint16_t foreground, uint16_t background) {
	switch(frame)
	{
		case 1:
		case 2:
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
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(getRandomEyeType(), foreground, background);
			eyeRightElement.render(getRandomEyeType(), foreground, background);
			break;
		case 16:
		case 20:
		case 24:
		case 28:
		case 32:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_SPIRAL_ONE_LR, foreground, background);
			eyeRightElement.render(EYE_SPIRAL_ONE_LR, foreground, background);
			break;
		case 17:
		case 21:
		case 25:
		case 29:
		case 33:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_SPIRAL_TWO_LR, foreground, background);
			eyeRightElement.render(EYE_SPIRAL_TWO_LR, foreground, background);
			break;
		case 18:
		case 22:
		case 26:
		case 30:
		case 34:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_SPIRAL_THREE_LR, foreground, background);
			eyeRightElement.render(EYE_SPIRAL_THREE_LR, foreground, background);
			break;
		case 19:
		case 23:
		case 27:
		case 31:
		case 35:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_SPIRAL_FOUR_LR, foreground, background);
			eyeRightElement.render(EYE_SPIRAL_FOUR_LR, foreground, background);
			break;
		case 36:
		case 40:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_CLOSING_LR, foreground, background);
			eyeRightElement.render(EYE_CLOSING_LR, foreground, background);
			break;
		case 37:
		case 41:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_CLOSED_LR, foreground, background);
			eyeRightElement.render(EYE_CLOSED_LR, foreground, background);
			break;
		case 38:
		case 42:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_CLOSING_LR, foreground, background);
			eyeRightElement.render(EYE_CLOSING_LR, foreground, background);
			break;
		case 39:
		case 43:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
		case 44:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
		case 45:
			mouthElement.render(MOUTH_CLOSED, foreground, background);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background);
			break;
		default:
			break;
	}
}

EyeType LoadingFaceAnimation::getRandomEyeType()
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