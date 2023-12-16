/*********************
 *      INCLUDES
 *********************/
#include "OctoCat.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
OctoCat::OctoCat() { }

void OctoCat::renderFrame(int frame, int _delay) {
	if (_delay > 0) {
		frames = _delay;
	}
	displayService.drawImage("/octocat.jpg");
}
