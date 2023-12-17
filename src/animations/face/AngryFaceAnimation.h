#ifndef _ANGRY_FACE_ANIMATION_H_
#define _ANGRY_FACE_ANIMATION_H_
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
class AngryFaceAnimation : public Animation
{
public:
	AngryFaceAnimation();
	void renderFrame(int frame, uint16_t foreground, uint16_t background);
	// void renderIn();
	// void renderOut();
	// void renderLoop();
	int getTotalFrames();

private:
	int frames = 6;
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
};
#endif