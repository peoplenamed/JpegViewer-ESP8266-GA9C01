/*********************
 *      INCLUDES
 *********************/
#include "OctoCat.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
OctoCat::OctoCat() { }

void OctoCat::renderFrame(int frame) {
	#ifdef DEBUG
		Log.trace("OctoCat::renderFrame  frame: %i\n", frame);
	#endif

	displayService.drawImage("/octocat.jpg");
}

int OctoCat::getTotalFrames() {
	#ifdef DEBUG
		Log.trace("OctoCat::getTotalFrames  frames: %i\n", frames);
	#endif
	return frames;
}