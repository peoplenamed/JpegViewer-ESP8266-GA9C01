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
	void renderFrame(int frame, uint16_t foreground, uint16_t background, bool drawBackgroundColor);
	int getTotalFrames();
	FrameObject getFrameObject(int frame, uint16_t foreground, uint16_t background, bool _drawBackgroundColor);
	std::vector<FrameInfo> getFrameInfos(int frame, uint16_t foreground, uint16_t background, bool _drawBackgroundColor);

private:
	bool drawBackgroundColor = false;
	int frames = 31;
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
};
#endif