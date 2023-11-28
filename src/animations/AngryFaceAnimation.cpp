/*********************
 *      INCLUDES
 *********************/
#include "AngryFaceAnimation.h";

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
AngryFaceAnimation::AngryFaceAnimation()
    : eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y),
      eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y),
      mouthElement(_MOUTH_X, _MOUTH_Y)
{
}

void AngryFaceAnimation::renderIn()
{
    mouthElement.render(MOUTH_CLOSED);

    eyeLeftElement.render(EYE_OPEN_LR);
    eyeRightElement.render(EYE_OPEN_LR);
    delay(200);

    eyeLeftElement.render(EYE_CLOSING_LR);
    eyeRightElement.render(EYE_CLOSING_LR);
    delay(200);

    eyeLeftElement.render(EYE_ANGRY_L);
    eyeRightElement.render(EYE_ANGRY_R);
}

void AngryFaceAnimation::renderOut()
{
    mouthElement.render(MOUTH_CLOSED);

    eyeLeftElement.render(EYE_ANGRY_L);
    eyeRightElement.render(EYE_ANGRY_R);
    delay(200);

    eyeLeftElement.render(EYE_CLOSING_LR);
    eyeRightElement.render(EYE_CLOSING_LR);
    delay(200);

    eyeLeftElement.render(EYE_OPEN_LR);
    eyeRightElement.render(EYE_OPEN_LR);
}