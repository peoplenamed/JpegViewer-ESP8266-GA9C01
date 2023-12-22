#ifndef _GRUMPY_FACE_ANIMATION_H_
#define _GRUMPY_FACE_ANIMATION_H_
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
class GrumpyFaceAnimation : public Animation
{
public:
	GrumpyFaceAnimation();
	void renderFrame(int frame, uint16_t foreground, uint16_t background, bool drawBackgroundColor);
	int getTotalFrames();

private:
	bool drawBackgroundColor = false;
	int frames = 31;
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
};
#endif