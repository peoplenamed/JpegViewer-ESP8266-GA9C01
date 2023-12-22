#ifndef _NORMAL_FACE_ANIMATION_H_
#define _NORMAL_FACE_ANIMATION_H_
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
class NormalAnimation : public Animation
{
public:
	NormalAnimation();
	void renderFrame(int frame, uint16_t foreground, uint16_t background, bool drawBackgroundColor);
	int getTotalFrames();

private:
	bool drawBackgroundColor = false;
	int frames = 2;
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
};
#endif