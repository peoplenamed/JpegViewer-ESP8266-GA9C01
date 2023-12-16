/*********************
 *      INCLUDES
 *********************/
#include "CalvinDuplicator.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
CalvinDuplicator::CalvinDuplicator() { }

void CalvinDuplicator::renderFrame(int frame, int _delay) {
	if (_delay > 0) {
		frames = _delay;
	}
	displayService.drawImage("/download.jpeg");
}
