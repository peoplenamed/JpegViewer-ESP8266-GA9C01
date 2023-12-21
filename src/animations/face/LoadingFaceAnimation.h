#ifndef _LOADING_FACE_ANIMATION_H_
#define _LOADING_FACE_ANIMATION_H_
/*********************
 *      INCLUDES
 *********************/
#include "config.h"
#include "animations/Animation.h"
#include "elements/EyeElement.h"
#include "elements/MouthElement.h"

/*********************
 *      Class
 *********************/
class LoadingFaceAnimation : public Animation
{
public:
	LoadingFaceAnimation()
		: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
		, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
		, mouthElement(_MOUTH_X, _MOUTH_Y) { }
	void renderFrame(int frame, uint16_t foreground, uint16_t background);
	EyeType getRandomEyeType();
	int getTotalFrames();
	int frames = 45;

private:
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
};
#endif