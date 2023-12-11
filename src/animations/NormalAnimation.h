#ifndef _NORMAL_FACE_ANIMATION_H_
#define _NORMAL_FACE_ANIMATION_H_
/*********************
 *      INCLUDES
 *********************/
#include "../config.h"
#include "FaceAnimation.h"
#include "elements/EyeElement.h"
#include "elements/MouthElement.h"

/*********************
 *      Class
 *********************/
class NormalAnimation : public FaceAnimation
{
public:
	NormalAnimation();
	int frames = 2;
	boolean renderFrame(int frame);

private:
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
};
#endif