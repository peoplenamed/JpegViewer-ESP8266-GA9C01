/*********************
 *      INCLUDES
 *********************/
#include "PopEyeFaceAnimation.h";

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
PopEyeFaceAnimation::PopEyeFaceAnimation()
    : eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y),
      eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y),
      mouthElement(_MOUTH_X, _MOUTH_Y)
{
}

void PopEyeFaceAnimation::renderIn()
{
    mouthElement.render(MOUTH_CLOSED);

    eyeLeftElement.render(EYE_OPEN_LR);
    eyeRightElement.render(EYE_OPEN_LR);
    delay(300);
    eyeLeftElement.render(EYE_POP_ONE_LR);
    delay(300);
    eyeLeftElement.render(EYE_POP_TWO_LR);
}

void PopEyeFaceAnimation::renderOut()
{
    mouthElement.render(MOUTH_CLOSED);

    eyeLeftElement.render(EYE_POP_TWO_LR);
    delay(300);

    eyeLeftElement.render(EYE_POP_ONE_LR);
    delay(300);

    eyeLeftElement.render(EYE_OPEN_LR);
    eyeRightElement.render(EYE_OPEN_LR);
}

void PopEyeFaceAnimation::renderLoop()
{
    mouthElement.render(MOUTH_CLOSED);

    for (int i = 0; i < 3; i++)
    {
        eyeLeftElement.render(EYE_POP_TWO_LR);
        delay(300);
        eyeLeftElement.render(EYE_POP_ONE_LR);
        delay(300);
        eyeLeftElement.render(EYE_OPEN_LR);
        eyeRightElement.render(EYE_OPEN_LR);
        delay(300);
        eyeRightElement.render(EYE_POP_ONE_LR);
        delay(300);
        eyeRightElement.render(EYE_POP_TWO_LR);
        delay(300);
        eyeRightElement.render(EYE_POP_ONE_LR);
        delay(300);
        eyeLeftElement.render(EYE_OPEN_LR);
        eyeRightElement.render(EYE_OPEN_LR);
        delay(300);
        eyeLeftElement.render(EYE_POP_ONE_LR);
        delay(300);
        eyeLeftElement.render(EYE_POP_TWO_LR);
    }
}