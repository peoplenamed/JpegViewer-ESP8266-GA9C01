/*********************
 *      INCLUDES
 *********************/
#include "PopEyeFaceAnimation.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
PopEyeFaceAnimation::PopEyeFaceAnimation()
	: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
	, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
	, mouthElement(_MOUTH_X, _MOUTH_Y)
{ }

boolean PopEyeFaceAnimation::renderFrame(int frame) {
	switch(frame)
	{
		case 1:
			mouthElement.render(MOUTH_CLOSED);
			eyeLeftElement.render(EYE_OPEN_LR);
			eyeRightElement.render(EYE_OPEN_LR);
			break;
		case 2:
			eyeLeftElement.render(EYE_POP_ONE_LR);
			break;
		case 3:
			eyeLeftElement.render(EYE_POP_TWO_LR);
			break;
		case 4:
			mouthElement.render(MOUTH_CLOSED);
			eyeLeftElement.render(EYE_POP_TWO_LR);
			break;
		case 5:
			eyeLeftElement.render(EYE_POP_ONE_LR);
			break;
		case 6:
			eyeLeftElement.render(EYE_OPEN_LR);
			eyeRightElement.render(EYE_OPEN_LR);
			break;
		default:
			return true;
			break;
	}
	return false;
}


// void PopEyeFaceAnimation::renderLoop()
// {
// 	mouthElement.render(MOUTH_CLOSED);

// 	for(int i = 0; i < 3; i++)
// 	{
// 		eyeLeftElement.render(EYE_POP_TWO_LR);
// 		delay(300);
// 		eyeLeftElement.render(EYE_POP_ONE_LR);
// 		delay(300);
// 		eyeLeftElement.render(EYE_OPEN_LR);
// 		eyeRightElement.render(EYE_OPEN_LR);
// 		delay(300);
// 		eyeRightElement.render(EYE_POP_ONE_LR);
// 		delay(300);
// 		eyeRightElement.render(EYE_POP_TWO_LR);
// 		delay(300);
// 		eyeRightElement.render(EYE_POP_ONE_LR);
// 		delay(300);
// 		eyeLeftElement.render(EYE_OPEN_LR);
// 		eyeRightElement.render(EYE_OPEN_LR);
// 		delay(300);
// 		eyeLeftElement.render(EYE_POP_ONE_LR);
// 		delay(300);
// 		eyeLeftElement.render(EYE_POP_TWO_LR);
// 	}
// }