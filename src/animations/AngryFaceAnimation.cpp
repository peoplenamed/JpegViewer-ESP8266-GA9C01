/*********************
 *      INCLUDES
 *********************/
#include <Arduino.h>;
#include <Arduino_GFX.h>;
#include "AngryFaceAnimation.h";
#include "../frames/EyeFrame.h";

/*********************
 *      DEFINES
 *********************/
void AngryFaceAnimation::render()
{
    EyeFrame eyeLeftFrame(_EYE_LEFT_X, _EYE_LEFT_Y);
    EyeFrame eyeRightFrame(_EYE_RIGHT_X, _EYE_RIGHT_Y);

    eyeLeftFrame.render(0);
    eyeRightFrame.render(0);
    delay(250);

    eyeLeftFrame.render(5);
    eyeRightFrame.render(5);
    delay(250);

    eyeLeftFrame.render(6);
    eyeRightFrame.render(6);
    delay(250);
}