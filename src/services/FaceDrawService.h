#ifndef _FACE_DRAW_SERVICE_H_
#define _FACE_DRAW_SERVICE_H_

#include "config.h"
#include "services/ColorsService.h"
#include "animations/face/AngryFaceAnimation.h"
#include "animations/face/FangFaceAnimation.h"
#include "animations/face/GrumpyFaceAnimation.h"
#include "animations/face/HappyFaceAnimation.h"
#include "animations/face/LoadingFaceAnimation.h"
#include "animations/face/NormalAnimation.h"
#include "animations/face/PopEyeFaceAnimation.h"
#include "animations/face/PukeRainbowFaceAnimation.h"
#include "animations/face/SatisfiedFaceAnimation.h"
#include "animations/face/SleepFaceAnimation.h"
#include "animations/face/WinkFaceAnimation.h"
#include "animations/Animation.h"

#include "services/DrawFrameService.h"

class FaceDrawService : public DrawFrameService
{
public:
	FaceDrawService(ColorsService& colorsService)
        : colorsService(colorsService) {
        Log.info("FaceDrawService initializer with ColorsService\n");
    }
	//  ~();
	void processAnimationFrame();
    void processCommand(int selected);
	void setDrawBackgroundColor(bool _drawBackgroundColor);

private:
	// SERVICES
	ColorsService& colorsService;

	// VARIABLES
	boolean screenWipe;
	boolean drawBackgroundColor = false;
    uint16_t _currentColor;
	uint16_t backgroundColor = colorsService.white;
	uint16_t foregroundColor = colorsService.black;

	Animation *animation;
	int totalFrames = 0;
	int currentFrame = 0;
	int currentSelection = -1;
	boolean randomColors = false;
	boolean rainbowColors = true;
	int currentAngle = 0;

	// FUNCTIONS
	void processCustomCommand(String customJpeg);
	void chooseAnimation();
	void afterFrameEvents();
	void updateTotalFrames();
	boolean isAnimationRunning();
	void incrementFrame();
	void drawJpeg();
	void endAnimation();

    void setColorShiftingEffect();
};

#endif // _FACE_DRAW_SERVICE_H_
