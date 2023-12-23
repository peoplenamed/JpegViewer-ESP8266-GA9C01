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
class LoadingFaceAnimation : public Animation
{
public:
	LoadingFaceAnimation()
		: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
		, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
		, mouthElement(_MOUTH_X, _MOUTH_Y) { }
	void renderFrame(int frame, uint16_t foreground, uint16_t background, bool drawBackgroundColor);
	EyeType getRandomEyeType();
	int getTotalFrames();
	FrameObject getFrameObject(int frame, uint16_t foreground, uint16_t background, bool _drawBackgroundColor);
	std::vector<FrameInfo> getFrameInfos(int frame, uint16_t foreground, uint16_t background, bool _drawBackgroundColor);

private:
	bool drawBackgroundColor = false;
	int frames = 45;
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
};
#endif