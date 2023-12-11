#ifndef _ANIMATIONS_CONTROLLER_H_
#define _ANIMATIONS_CONTROLLER_H_

#include "../animations/AngryFaceAnimation.h"
#include "../animations/FangFaceAnimation.h"
#include "../animations/GrumpyFaceAnimation.h"
#include "../animations/HappyFaceAnimation.h"
#include "../animations/LoadingFaceAnimation.h"
#include "../animations/NormalAnimation.h"
#include "../animations/PopEyeFaceAnimation.h"
#include "../animations/PukeRainbowFaceAnimation.h"
#include "../animations/SatisfiedFaceAnimation.h"
#include "../animations/SleepFaceAnimation.h"
#include "../animations/WinkFaceAnimation.h"
#include "../config.h"
#include "../services/DisplayService.h"
#include "../services/HexColorsService.h"

class AnimationsController
{
public:
	AnimationsController();
	//  ~();
	void init(int *_imageSelect, boolean *_commandReceived);

private:
	// VARIABLES
	int currentFrame = 0;
	int totalFrames = 0;
	boolean drawFrame = false;
	int *imageSelect;
	int currentSelection = -1;
	boolean lastFrameDrawn;
	boolean commandReceived;
	int _width = _SCREEN_WIDTH;
	int _height = _SCREEN_HEIGHT;
	int vTaskDelayTimeout = 250;
	Display display;
	int compassTextColor = 7;

	// Could probably be moved to service layer.
	void afterFrameEvent();
	void processCommand();
	void processAnimationFrame();
	boolean isAnimationRunning();


	// IMAGES
	void setupDisplay();
	void chooseAnimation();
	void chooseImage();
	void calvinAndHobbes();
	void octocat();
	void calvinDuplicator();
	void grumpyFace();
	void winkFace();
	void disappointedFace();
	void normalFace();
	void satisfiedFace();
	void popEye();
	void fangs();
	void diamondEyes();
	void happyFace();
	void splashScreen();
	void pukeRainbowFace();

	// TEXT
	void northText(String _text);
	void southText(String _text);
	void eastText(String _text);
	void westText(String _text);
	void centerText(String _text);
	void errorText(String _text);
	void successText(String _text);
	void userDefinedText(String _text, int _x, int _y, int _size, int _color);

	// MATHS
	void circleWipe();
	void drawRimCircle(int radius, boolean wipe, int maxWipe);
	void circleWipe(int radius, boolean wipe);
	void triangleWipe(boolean wipe);
	void wipeScreen(boolean wipe);

	// ANIMATION CLASSES
	HexColorsService hexColors;
	LoadingFaceAnimation loadingFaceAnimation;
	SleepFaceAnimation sleepFaceAnimation;
	GrumpyFaceAnimation grumpyFaceAnimation;
	WinkFaceAnimation winkFaceAnimation;
	SatisfiedFaceAnimation satisfiedFaceAnimation;
	PopEyeFaceAnimation popEyeFaceAnimation;
	PukeRainbowFaceAnimation pukeRainbowFaceAnimation;
	HappyFaceAnimation happyFaceAnimation;
	AngryFaceAnimation angryFaceAnimation;
	NormalAnimation normalAnimation;
	FangFaceAnimation fangFaceAnimation;

	// T[] animates = {loadingFaceAnimation, sleepFaceAnimation, grumpyFaceAnimation,
	//  winkFaceAnimation, satisfiedFaceAnimation, popEyeFaceAnimation,
	//  pukeRainbowFaceAnimation, happyFaceAnimation, angryFaceAnimation,
	//  normalAnimation, fangFaceAnimation}


};

#endif // _ANIMATIONS_CONTROLLER_H_
