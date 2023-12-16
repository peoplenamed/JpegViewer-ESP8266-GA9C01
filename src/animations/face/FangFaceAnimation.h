#ifndef _FANG_FACE_ANIMATION_H_
#define _FANG_FACE_ANIMATION_H_
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
class FangFaceAnimation : public Animation
{
public:
	FangFaceAnimation();
	void renderFrame(int frame, uint16_t foreground, uint16_t background);
	int getTotalFrames();
	int frames = 6;

private:
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
};
#endif