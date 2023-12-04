#ifndef _SLEEP_FACE_ANIMATION_H_
#define _SLEEP_FACE_ANIMATION_H_
/*********************
 *      INCLUDES
 *********************/
#include "../config.h";
#include "../services/HexColorsService.h";
#include "FaceAnimation.h";
#include "elements/EyeElement.h";
#include "elements/MouthElement.h";
#include "elements/SleepElement.h";

/*********************
 *      Class
 *********************/
class SleepFaceAnimation : public FaceAnimation
{
public:
	SleepFaceAnimation();
	void renderIn();
	void renderOut();
	void renderLoop();

private:
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
	SleepElement sleepElement;
};
#endif