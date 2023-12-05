#ifndef _PUKE_RAINBOW_FACE_ANIMATION_H_
#define _PUKE_RAINBOW_FACE_ANIMATION_H_
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
class PukeRainbowFaceAnimation : public FaceAnimation
{
public:
	PukeRainbowFaceAnimation();
	void renderIn() override;
	void renderOut() override;
	void renderLoop() override;

private:
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
	static const uint16_t rainbowColors[];
};
#endif