#ifndef _SLEEP_FACE_ANIMATION_H_
#define _SLEEP_FACE_ANIMATION_H_
/*********************
 *      INCLUDES
 *********************/
#include "config.h"
#include "services/ColorsService.h"
#include "animations/Animation.h"
#include "elements/EyeElement.h"
#include "elements/MouthElement.h"
#include "elements/SleepElement.h"

/*********************
 *      Class
 *********************/
class SleepFaceAnimation : public Animation
{
public:
	SleepFaceAnimation();
	void renderFrame(int frame, uint16_t foreground, uint16_t background, bool drawBackgroundColor);
	int getTotalFrames();

private:
	bool drawBackgroundColor = false;
	int frames = 6;
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
	SleepElement sleepElement;
};
#endif