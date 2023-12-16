/*********************
 *      INCLUDES
 *********************/
#include "DimondEyes.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
DimondEyes::DimondEyes() { }

void DimondEyes::renderFrame(int frame, int _delay) {

	switch(frame)
	{
		case 1:
			displayService.drawImage("/diamondEyes_0001.jpg");
			break;
		case 2:
			displayService.drawImage("/diamondEyes_0002.jpg");
			break;
		case 3:
			displayService.drawImage("/diamondEyes_0003.jpg");
			break;
		case 4:
			displayService.drawImage("/diamondEyes_0002.jpg");
			break;
		case 5:
			displayService.drawImage("/diamondEyes_0001.jpg");
			break;
		case 6:
			displayService.drawImage("/diamondEyes_0003.jpg");
			break;
		case 7:
			displayService.drawImage("/diamondEyes_0002.jpg");
			break;
		case 8:
			displayService.drawImage("/diamondEyes_0003.jpg");
			break;
		case 9:
			displayService.drawImage("/diamondEyes_0001.jpg");
			break;
		default:
			break;
	}
}
