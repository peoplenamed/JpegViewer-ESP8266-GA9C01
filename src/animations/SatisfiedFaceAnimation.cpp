/*********************
 *      INCLUDES
 *********************/
#include "SatisfiedFaceAnimation.h";

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
SatisfiedFaceAnimation::SatisfiedFaceAnimation()
    : eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y),
      eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y),
      mouthElement(_MOUTH_X, _MOUTH_Y)
{
}

void SatisfiedFaceAnimation::renderIn()
{
    mouthElement.render(MOUTH_CLOSED);

    eyeLeftElement.render(EYE_OPEN_LR);
    eyeRightElement.render(EYE_OPEN_LR);
    delay(300);

    eyeLeftElement.render(EYE_SATISFIED_LR);
    eyeRightElement.render(EYE_SATISFIED_LR);
}

void SatisfiedFaceAnimation::renderOut()
{
    mouthElement.render(MOUTH_CLOSED);

    eyeLeftElement.render(EYE_SATISFIED_LR);
    eyeRightElement.render(EYE_SATISFIED_LR);
    delay(300);

    eyeLeftElement.render(EYE_OPEN_LR);
    eyeRightElement.render(EYE_OPEN_LR);
}

void SatisfiedFaceAnimation::renderLoop()
{
    mouthElement.render(MOUTH_CLOSED);
    eyeLeftElement.render(EYE_SATISFIED_LR);
    eyeRightElement.render(EYE_SATISFIED_LR);
}