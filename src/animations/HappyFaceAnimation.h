#ifndef _HAPPY_FACE_ANIMATION_H_
#define _HAPPY_FACE_ANIMATION_H_
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
class HappyFaceAnimation : public FaceAnimation
{
public:
	HappyFaceAnimation();
	void renderIn() override;
	void renderOut() override;
	void renderLoop() override;

private:
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
};
#endif