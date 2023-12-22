#ifndef _SATISFIED_FACE_ANIMATION_H_
#define _SATISFIED_FACE_ANIMATION_H_
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
class SatisfiedFaceAnimation : public Animation
{
public:
	SatisfiedFaceAnimation();
	void renderFrame(int frame, uint16_t foreground, uint16_t background, bool drawBackgroundColor);
	int getTotalFrames();

private:
	bool drawBackgroundColor = false;
	int frames = 4;
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
};
#endif