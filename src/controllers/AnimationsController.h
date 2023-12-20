#ifndef _ANIMATIONS_CONTROLLER_H_
#define _ANIMATIONS_CONTROLLER_H_

#include "animations/maths/DrawRimCircle.h"
#include "animations/maths/Circlewipe.h"
#include "animations/maths/TriangleWipe.h"
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
#include "animations/jpeg/DimondEyes.h"
#include "animations/jpeg/CalvinDuplicator.h"
#include "animations/jpeg/CalvinAndHobbes.h"
#include "animations/jpeg/OctoCat.h"
#include "animations/text/TextAlert.h"
#include "animations/text/TextOverLay.h"
#include "animations/TextDraw.h"
#include "animations/maths/Circlewipe.h"
#include "animations/maths/TriangleWipe.h"
#include "animations/maths/DrawRimCircle.h"
#include "config.h"
#include "services/DisplayService.h"
#include "services/DrawingService.h"
#include "services/ColorsService.h"

class AnimationsController
{
public:
	AnimationsController();
	//  ~();
	void init(int *_imageSelect);

private:
	// SERVICES
	ColorsService colorsService;
	DisplayService displayService;
	DrawingService drawingService;

	// VARIABLES
	Pixel *pixels;
	uint16_t backgroundColor = colorsService.white;
	uint16_t foregroundColor = colorsService.indigoViolet;
	Animation *animation;
	MathAnimation *mathAnimation;
	JPEGAnimation *jpegAnimation;
	CircleWipe circleWipe;
	TriangleWipe triangleWipe;
	DrawRimCircle drawRimCircle;
	TextDraw *textDraw;
	boolean randomColors = false;
	boolean rainbowColors = true;
	boolean mathWipe = false;
	int currentAngle = 0;
	int currentFrame = 0;
	int totalFrames = 0;
	int *imageSelect = 0;
	int currentSelection = -1;
	int vTaskDelayTimeout = 200; // Interval between frames

	// FUNCTIONS
	void chooseAnimation();
	void afterFrameEvents();

	void afterAnimationFrameEvents();
	void afterJpegFrameEvents();
	void afterMathFrameEvents();
	void updateFrames();
	void setColorShiftingEffect();
	void processAnimationFrame();
	boolean isAnimationRunning();
	void processCommand();
	void incrementFrame();
	void drawAnimation();
	boolean serialCommandReceived();
	void setupDisplay();
	void chooseImage();
};

#endif // _ANIMATIONS_CONTROLLER_H_
