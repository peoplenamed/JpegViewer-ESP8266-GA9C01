#ifndef _PUKE_RAINBOW_FACE_ANIMATION_H_
#define _PUKE_RAINBOW_FACE_ANIMATION_H_
/*********************
 *      INCLUDES
 *********************/
#include "../config.h"
#include "FaceAnimation.h"
#include "elements/EyeElement.h"
#include "elements/MouthElement.h"

/*********************
 *      Class
 *********************/
class PukeRainbowFaceAnimation : public FaceAnimation
{
public:
	PukeRainbowFaceAnimation();
	int frames = 26;
	boolean renderFrame(int frame);

private:
	EyeElement eyeLeftElement;
	EyeElement eyeRightElement;
	MouthElement mouthElement;
	void drawRainbow(int frame);
	void reset();
	const uint16_t rainbowColors[13] = {
		gfx->color565(255, 0, 0), // Red
		gfx->color565(255, 80, 0), // Red-Orange
		gfx->color565(255, 165, 0), // Orange
		gfx->color565(255, 210, 0), // Yellow-Orange
		gfx->color565(255, 255, 0), // Yellow
		gfx->color565(128, 255, 0), // Yellow-Green
		gfx->color565(0, 128, 0), // Green
		gfx->color565(0, 128, 128), // Green-Blue
		gfx->color565(0, 0, 255), // Blue
		gfx->color565(75, 0, 255), // Blue-Indigo
		gfx->color565(75, 0, 130), // Indigo
		gfx->color565(143, 0, 255), // Indigo-Violet
		gfx->color565(238, 130, 238) // Violet
	};
	int numColors = 13;
	int colorIndex = 0;
};
#endif