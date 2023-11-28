/*********************
 *      INCLUDES
 *********************/
#include "SleepFaceAnimation.h";

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
SleepFaceAnimation::SleepFaceAnimation()
    : eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y),
      eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y),
      mouthElement(_MOUTH_X, _MOUTH_Y)
{
}

void SleepFaceAnimation::renderIn()
{

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

void SleepFaceAnimation::renderOut()
{
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