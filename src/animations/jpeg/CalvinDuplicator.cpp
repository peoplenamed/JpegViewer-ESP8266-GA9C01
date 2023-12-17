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

	displayService.drawImage("/download.jpeg");
}

int CalvinDuplicator::getTotalFrames() {
	return frames;
}