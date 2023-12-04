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
class LoadingFaceAnimation : public FaceAnimation
{
public:
	LoadingFaceAnimation();
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