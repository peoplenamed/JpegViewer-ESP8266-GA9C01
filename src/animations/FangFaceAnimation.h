#ifndef _FANG_FACE_ANIMATION_H_
#define _FANG_FACE_ANIMATION_H_
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
class FangFaceAnimation : public FaceAnimation
{
public:
	FangFaceAnimation();
	void renderIn() override;
	void renderOut() override;
	void renderLoop() override;

private:
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
};
#endif