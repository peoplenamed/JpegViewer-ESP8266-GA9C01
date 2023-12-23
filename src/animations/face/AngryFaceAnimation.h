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
	void renderFrame(int frame, uint16_t foreground, uint16_t background, bool drawBackgroundColor);
	// void renderIn();
	// void renderOut();
	// void renderLoop();
	int getTotalFrames();
	FrameObject getFrameObject(int frame, uint16_t foreground, uint16_t background, bool _drawBackgroundColor);
	std::vector<FrameInfo> getFrameInfos(int frame, uint16_t foreground, uint16_t background, bool _drawBackgroundColor);

private:
	int frames = 6;
	bool drawBackgroundColor = false;
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
};
#endif