#ifndef _JPEG_DRAW_SERVICE_H_
#define _JPEG_DRAW_SERVICE_H_

#include "config.h"
#include "services/ColorsService.h"
#include "animations/JPEGAnimation.h"

#include "animations/jpeg/DimondEyes.h"
#include "animations/jpeg/CalvinDuplicator.h"
#include "animations/jpeg/CalvinAndHobbes.h"
#include "animations/jpeg/OctoCat.h"

class JpegDrawService
{
public:
	JpegDrawService(ColorsService& colorsService)
        : colorsService(colorsService) {
        Log.info("JpegDrawService initializer with ColorsService\n");
    }
	//  ~();
	void processAnimationFrame();
    void processCommand(int selected);

private:
	// SERVICES
	ColorsService& colorsService;

	// VARIABLES
    uint16_t _currentColor;

	uint16_t backgroundColor = colorsService.white;
	uint16_t foregroundColor = colorsService.black;

	JPEGAnimation *jpegAnimation;
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

#endif // _JPEG_DRAW_SERVICE_H_
