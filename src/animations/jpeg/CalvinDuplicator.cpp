/*********************
 *      INCLUDES
 *********************/
#include "CalvinDuplicator.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
CalvinDuplicator::CalvinDuplicator() { }

void CalvinDuplicator::renderFrame(int frame) {
	#ifdef DEBUG
		Log.trace("CalvinDuplicator::renderFrame  frame: %i\n", frame);
	#endif

	displayService.drawJpgAnimationFrame("1Ys_", ".jpg", frame);
}

int CalvinDuplicator::getTotalFrames() {
	#ifdef DEBUG
		Log.trace("CalvinDuplicator::getTotalFrames  frames: %i\n", frames);
	#endif
	return frames;
}