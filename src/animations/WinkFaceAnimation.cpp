/*********************
 *      INCLUDES
 *********************/
#include "WinkFaceAnimation.h";

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
WinkFaceAnimation::WinkFaceAnimation()
    : eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y),
      eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y),
      mouthElement(_MOUTH_X, _MOUTH_Y)
{
}

void WinkFaceAnimation::renderIn()
{
    mouthElement.render(MOUTH_CLOSED);

    eyeLeftElement.render(EYE_OPEN_LR);
    eyeRightElement.render(EYE_OPEN_LR);
    delay(300);

    eyeLeftElement.render(EYE_CLOSING_LR);
    delay(300);

    eyeLeftElement.render(EYE_CLOSED_LR);
}

void WinkFaceAnimation::renderOut()
{
    mouthElement.render(MOUTH_CLOSED);

    eyeLeftElement.render(EYE_CLOSED_LR);
    delay(300);

    eyeLeftElement.render(EYE_CLOSING_LR);
    delay(300);

    eyeLeftElement.render(EYE_OPEN_LR);
}