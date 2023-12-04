#ifndef _LOADING_FACE_ANIMATION_H_
#define _LOADING_FACE_ANIMATION_H_
/*********************
 *      INCLUDES
 *********************/
#include "../config.h";
#include "FaceAnimation.h";
#include "elements/EyeElement.h";
#include "elements/MouthElement.h";

/*********************
 *      Class
 *********************/
class DizzyFaceAnimation : public FaceAnimation
{
public:
	DizzyFaceAnimation();
	void renderIn() override;
	void renderOut() override;
	void renderLoop() override;
	EyeType getRandomEyeType();

private:
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
};
#endif