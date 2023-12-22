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
class DizzyFaceAnimation : public Animation
{
public:
	DizzyFaceAnimation();
	void renderFrame(int frame, uint16_t foreground, uint16_t background, bool drawBackgroundColor);
	EyeType getRandomEyeType();
	int getTotalFrames();

private:
	bool drawBackgroundColor = false;
	int frames = 31;
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
};
#endif