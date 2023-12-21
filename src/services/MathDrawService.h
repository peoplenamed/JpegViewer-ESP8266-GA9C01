#ifndef _MATH_DRAW_SERVICE_H_
#define _MATH_DRAW_SERVICE_H_

#include "config.h"
#include "services/ColorsService.h"
#include "animations/MathAnimation.h"
#include "animations/maths/DrawRimCircle.h"
#include "animations/maths/Circlewipe.h"
#include "animations/maths/TriangleWipe.h"

class MathDrawService
{
public:
	MathDrawService(ColorsService& colorsService)
        : colorsService(colorsService) {
        Log.info("MathDrawService initializer with ColorsService\n");
    }
	//  ~();
	void processAnimationFrame();
    void processCommand(int selected);

private:
	// SERVICES
	ColorsService& colorsService;

	// VARIABLES
	boolean screenWipe;
    uint16_t _currentColor;
	uint16_t backgroundColor = colorsService.white;
	uint16_t foregroundColor = colorsService.black;

	MathAnimation *mathAnimation;
	int totalFrames = 0;
	int currentFrame = 0;
	int currentSelection = -1;

	// FUNCTIONS
	void processCustomCommand(String customJpeg);
	void chooseAnimation();
	void afterFrameEvents();
	void updateTotalFrames();
	boolean isAnimationRunning();
	void processCommand();
	void incrementFrame();
	void drawJpeg();
	void endAnimation();
};

#endif // _MATH_DRAW_SERVICE_H_
