#ifndef _SATISFIED_FACE_ANIMATION_H_
#define _SATISFIED_FACE_ANIMATION_H_
/*********************
 *      INCLUDES
 *********************/
#include "../config.h"
#include "elements/EyeElement.h"
#include "elements/MouthElement.h"

/*********************
 *      Class
 *********************/
class SatisfiedFaceAnimation
{
public:
	SatisfiedFaceAnimation();
	int frames = 4;
	boolean renderFrame(int frame);

private:
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
};
#endif