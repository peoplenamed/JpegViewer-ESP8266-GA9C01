#ifndef _PUKE_RAINBOW_FACE_ANIMATION_H_
#define _PUKE_RAINBOW_FACE_ANIMATION_H_
/*********************
 *      INCLUDES
 *********************/
#include "config.h"
#include "animations/Animation.h"
#include "elements/EyeElement.h"
#include "elements/MouthElement.h"
#include "services/ColorsService.h"

/*********************
 *      Class
 *********************/
class PukeRainbowFaceAnimation : public Animation
{
public:
	PukeRainbowFaceAnimation();
	void renderFrame(int frame, uint16_t foreground, uint16_t background);
	int getTotalFrames();
	int frames = 26;

private:
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
	void drawRainbow(int frame);
	void reset();
	ColorsService colorsService;
	
	int colorIndex = 0;
};
#endif