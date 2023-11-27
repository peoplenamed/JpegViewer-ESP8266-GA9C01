/*********************
 *      INCLUDES
 *********************/
#include "../../config.h";
#include "AngryFaceAnimation.h";
#include "elements/EyeElement.h";
#include "elements/MouthElement.h";

/*********************
 *      DEFINES
 *********************/
void AngryFaceAnimation::renderIn()
{

    EyeElement eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y);
    EyeElement eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y);
    MouthElement mouthElement(_MOUTH_X, _MOUTH_Y);

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
    EyeElement eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y);
    EyeElement eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y);
    MouthElement mouthElement(_MOUTH_X, _MOUTH_Y);

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