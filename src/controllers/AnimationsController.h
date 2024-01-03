#ifndef _ANIMATIONS_CONTROLLER_H_
#define _ANIMATIONS_CONTROLLER_H_


#include "config.h"
#include "services/DisplayService.h"
#include "services/JpegDrawService.h"
#include "services/ColorsService.h"
#include "services/TextDrawService.h"
#include "services/MathDrawService.h"
#include "services/FaceDrawService.h"
#include "services/FrameSmasherService.h"
#include "services/FaceDrawServiceExperimental.h"

class AnimationsController
{
public:
	
	AnimationsController(): 
		textDrawService(colorsService, displayService),
		jpegDrawService(colorsService),
		mathDrawService(colorsService),
		faceDrawService(colorsService),
		faceDrawServiceExperimental(colorsService) {
		Log.info("[AnimationsController]<initializer>\n");
	}
	//  ~();
	void init(int *_imageSelect, int *_textSelect, String *_userDefinedText);

private:
	// SERVICES
	ColorsService colorsService;
	DisplayService displayService;
	TextDrawService textDrawService;
	JpegDrawService jpegDrawService;
	MathDrawService mathDrawService;
	FaceDrawService faceDrawService;
	FaceDrawServiceExperimental faceDrawServiceExperimental;
	FrameSmasherService frameSmasherService;


	// VARIABLES
	uint16_t backgroundColor = colorsService.white;
	uint16_t foregroundColor = colorsService.indigoViolet;
	Animation *animation;
	boolean randomColors = false;
	boolean rainbowColors = true;
	int currentAngle = 0;
	int currentFrame = 0;
	int totalFrames = 0;
	int *imageSelect = 0;
	int *textSelect = 0;
	String *userDefinedText;
	String currentUserDefinedText;
	int currentSelection = -1;
	int vTaskDelayTimeout = 175; // Interval between frames

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
	boolean customSerialCommandReceived();
	void setupDisplay();
	void chooseImage();
	void smashFrames();
};

#endif // _ANIMATIONS_CONTROLLER_H_
