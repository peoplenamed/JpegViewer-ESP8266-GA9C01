/*********************
 *      INCLUDES
 *********************/
#include "SatisfiedFaceAnimation.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
SatisfiedFaceAnimation::SatisfiedFaceAnimation()
	: eyeLeftElement(_EYE_LEFT_X, _EYE_LEFT_Y)
	, eyeRightElement(_EYE_RIGHT_X, _EYE_RIGHT_Y)
	, mouthElement(_MOUTH_X, _MOUTH_Y)
{ }

int SatisfiedFaceAnimation::getTotalFrames() {
	return frames;
}

void SatisfiedFaceAnimation::renderFrame(int frame, uint16_t foreground, uint16_t background, bool _drawBackgroundColor) {
	drawBackgroundColor = _drawBackgroundColor;
	
	switch(frame)
	{
		case 1:
			mouthElement.render(MOUTH_CLOSED, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			break;
		case 2:
			mouthElement.render(MOUTH_CLOSED, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_SATISFIED_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_SATISFIED_LR, foreground, background, drawBackgroundColor);
			break;
		case 3:
			mouthElement.render(MOUTH_CLOSED, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_SATISFIED_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_SATISFIED_LR, foreground, background, drawBackgroundColor);
			break;
		case 4:
			mouthElement.render(MOUTH_CLOSED, foreground, background, drawBackgroundColor);
			eyeLeftElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			eyeRightElement.render(EYE_OPEN_LR, foreground, background, drawBackgroundColor);
			break;
	}
}

FrameObject SatisfiedFaceAnimation::getFrameObject(int frame, uint16_t foreground, uint16_t background, bool _drawBackgroundColor) {
    drawBackgroundColor = _drawBackgroundColor;
	FrameObject frameObject;

	if (frame > 1) {
		frameObject.previousFrames = getFrameInfos(frame - 1, foreground, background, _drawBackgroundColor);
	}

	frameObject.currentFrames = getFrameInfos(frame, foreground, background, _drawBackgroundColor);

    return frameObject;
}

std::vector<FrameInfo> SatisfiedFaceAnimation::getFrameInfos(int frame, uint16_t foreground, uint16_t background, bool _drawBackgroundColor) {
	std::vector<FrameInfo> frameInfos;
   
	switch(frame)
	{
		case 1:
			frameInfos.push_back(mouthElement.getFrameInfo(MOUTH_CLOSED, foreground, background, drawBackgroundColor));
			frameInfos.push_back(eyeLeftElement.getFrameInfo(EYE_OPEN_LR, foreground, background, drawBackgroundColor));
			frameInfos.push_back(eyeRightElement.getFrameInfo(EYE_OPEN_LR, foreground, background, drawBackgroundColor));
			break;
		case 2:
			frameInfos.push_back(mouthElement.getFrameInfo(MOUTH_CLOSED, foreground, background, drawBackgroundColor));
			frameInfos.push_back(eyeLeftElement.getFrameInfo(EYE_SATISFIED_LR, foreground, background, drawBackgroundColor));
			frameInfos.push_back(eyeRightElement.getFrameInfo(EYE_SATISFIED_LR, foreground, background, drawBackgroundColor));
			break;
		case 3:
			frameInfos.push_back(mouthElement.getFrameInfo(MOUTH_CLOSED, foreground, background, drawBackgroundColor));
			frameInfos.push_back(eyeLeftElement.getFrameInfo(EYE_SATISFIED_LR, foreground, background, drawBackgroundColor));
			frameInfos.push_back(eyeRightElement.getFrameInfo(EYE_SATISFIED_LR, foreground, background, drawBackgroundColor));
			break;
		case 4:
			frameInfos.push_back(mouthElement.getFrameInfo(MOUTH_CLOSED, foreground, background, drawBackgroundColor));
			frameInfos.push_back(eyeLeftElement.getFrameInfo(EYE_OPEN_LR, foreground, background, drawBackgroundColor));
			frameInfos.push_back(eyeRightElement.getFrameInfo(EYE_OPEN_LR, foreground, background, drawBackgroundColor));
			break;
	}

    return frameInfos;
}