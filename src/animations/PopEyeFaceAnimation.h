#ifndef _POP_EYE_FACE_ANIMATION_H_
#define _POP_EYE_FACE_ANIMATION_H_
/*********************
 *      INCLUDES
 *********************/
#include "../../config.h";
#include "elements/EyeElement.h";
#include "elements/MouthElement.h";

/*********************
 *      Class
 *********************/
class PopEyeFaceAnimation
{
public:
	PopEyeFaceAnimation();
	void renderIn();
	void renderOut();
	void renderLoop();

private:
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
};
#endif