/*********************
 *      INCLUDES
 *********************/
#include "CalvinAndHobbes.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
CalvinAndHobbes::CalvinAndHobbes() { }

void CalvinAndHobbes::renderFrame(int frame) {
	#ifdef DEBUG
		Log.trace("CalvinAndHobbes::renderFrame  frame: %i\n", frame);
	#endif

	displayService.drawImage("/download.jpeg");
}

int CalvinAndHobbes::getTotalFrames() {
	#ifdef DEBUG
		Log.trace("CalvinAndHobbes::getTotalFrames  frames: %i\n", frames);
	#endif
	return frames;
}