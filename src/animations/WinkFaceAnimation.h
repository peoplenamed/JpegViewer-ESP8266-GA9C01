#ifndef _WINK_FACE_ANIMATION_H_
#define _WINK_FACE_ANIMATION_H_
/*********************
 *      INCLUDES
 *********************/
#include "../config.h"
#include "elements/EyeElement.h"
#include "elements/MouthElement.h"

/*********************
 *      Class
 *********************/
class WinkFaceAnimation
{
public:
	WinkFaceAnimation();
	int frames = 6;
	boolean renderFrame(int frame);

private:
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
};
#endif