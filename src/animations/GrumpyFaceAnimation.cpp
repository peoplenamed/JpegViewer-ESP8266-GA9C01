/*********************
 *      INCLUDES
 *********************/
#include "GrumpyFaceAnimation.h";

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
GrumpyFaceAnimation::GrumpyFaceAnimation()
    : eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y),
      eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y),
      mouthElement(_MOUTH_X, _MOUTH_Y)
{
}

void GrumpyFaceAnimation::renderIn()
{
    mouthElement.render(MOUTH_CLOSED);

    eyeLeftElement.render(EYE_DISAPPOINTED_LR);
    eyeRightElement.render(EYE_DISAPPOINTED_LR);
    mouthElement.render(MOUTH_GRUMPY_ONE);
    delay(200);
    mouthElement.render(MOUTH_GRUMPY_TWO);
    delay(200);
    mouthElement.render(MOUTH_GRUMPY_ONE);
    delay(200);
    mouthElement.render(MOUTH_GRUMPY_TWO);
    delay(200);
    mouthElement.render(MOUTH_GRUMPY_ONE);
    delay(200);
    mouthElement.render(MOUTH_GRUMPY_TWO);
    delay(200);
    mouthElement.render(MOUTH_GRUMPY_ONE);
    delay(200);
    mouthElement.render(MOUTH_GRUMPY_TWO);
}

void GrumpyFaceAnimation::renderOut()
{

    mouthElement.render(MOUTH_GRUMPY_TWO);
    eyeLeftElement.render(EYE_OPEN_LR);
    eyeRightElement.render(EYE_OPEN_LR);

    delay(200);
    mouthElement.render(MOUTH_CLOSED);
}

void GrumpyFaceAnimation::renderLoop()
{
    eyeLeftElement.render(EYE_ANGRY_L);
    eyeRightElement.render(EYE_ANGRY_R);

    mouthElement.render(MOUTH_GRUMPY_ONE);
    delay(200);
    mouthElement.render(MOUTH_GRUMPY_TWO);
    delay(200);
    mouthElement.render(MOUTH_GRUMPY_ONE);

    eyeLeftElement.render(EYE_DISAPPOINTED_LR);
    eyeRightElement.render(EYE_DISAPPOINTED_LR);
    delay(200);
}