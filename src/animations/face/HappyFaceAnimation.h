#ifndef _HAPPY_FACE_ANIMATION_H_
#define _HAPPY_FACE_ANIMATION_H_
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
class HappyFaceAnimation : public Animation
{
public:
	HappyFaceAnimation();
	void renderFrame(int frame, uint16_t foreground, uint16_t background);
	int getTotalFrames();
	int frames = 31;

private:
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
};
#endif