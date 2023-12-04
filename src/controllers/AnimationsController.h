#ifndef _ANIMATIONS_CONTROLLER_H_
#define _ANIMATIONS_CONTROLLER_H_

#include "../animations/AngryFaceAnimation.h"
#include "../animations/FangFaceAnimation.h"
#include "../animations/GrumpyFaceAnimation.h"
#include "../animations/HappyFaceAnimation.h"
#include "../animations/LoadingFaceAnimation.h"
#include "../animations/NormalAnimation.h"
#include "../animations/PopEyeFaceAnimation.h"
#include "../animations/SatisfiedFaceAnimation.h"
#include "../animations/SleepFaceAnimation.h"
#include "../animations/WinkFaceAnimation.h"
#include "../config.h"
#include "../services/DisplayService.h"
#include "../services/HexColorsService.h"

class Animations
{
public:
	Animations();
	//  ~();

	// IMAGES
	void setupDisplay();
	void chooseAnimation(int imageSelect);
	void chooseImage(int imageSelect);
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

private:
	Display display;
	int compassTextColor = 7;
	HexColorsService hexColors;
	int _width = _SCREEN_WIDTH;
	int _height = _SCREEN_HEIGHT;
};

#endif // _ANIMATIONS_H_
