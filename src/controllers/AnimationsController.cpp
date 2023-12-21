#include "AnimationsController.h"

void AnimationsController::init(int *_imageSelect, int *_textSelect, String *_userDefinedText) {
	textDrawService.init(_textSelect, _userDefinedText);
	imageSelect = _imageSelect;
	setupDisplay();

	auto task = [](void* arg) { static_cast<AnimationsController*>(arg)->processAnimationFrame(); };
	xTaskCreate(task, "processAnimationFrame", 3092, this, 2, NULL);
}

void AnimationsController::setupDisplay()
{
	#ifdef DEBUG
		Log.trace("[AnimationsController]<setupDisplay>  \n");
	#endif
	displayService.setupDisplay();
	displayService.wipeScreen(true, backgroundColor);
}

void AnimationsController::processAnimationFrame() {
	for(;;) {
		Log.info("LOOP\n");
		Log.info("currentSelection %i\n", currentSelection);
		if (serialCommandReceived()) {
			currentSelection = *imageSelect;
			currentFrame = 1;
			if (*imageSelect > 74) {
				// This is hacky to get the ball down the road.
				// Need to make custom commands for everything.
				int selectedOffset = *imageSelect - 74;
				Log.info("[AnimationsController]<processAnimationFrame>  serialCommandReceived %i, %i \n", selectedOffset, currentSelection);
				jpegDrawService.processCommand(selectedOffset);
			} else if (*imageSelect > 24) {
				// This is hacky to get the ball down the road.
				// Need to make custom commands for everything.
				int selectedOffset = *imageSelect - 24;
				Log.info("[AnimationsController]<processAnimationFrame>  serialCommandReceived %i, %i \n", selectedOffset, currentSelection);
				mathDrawService.processCommand(selectedOffset);
			} else {
				// This is hacky to get the ball down the road.
				// Need to make custom commands for everything.
				displayService.wipeScreen(true, backgroundColor);
				// chooseAnimation(); 
				faceDrawService.processCommand(*imageSelect);
			}
			updateFrames(); 
		}

		drawAnimation();
		textDrawService.processAnimationFrame();
		jpegDrawService.processAnimationFrame();
		mathDrawService.processAnimationFrame();
		faceDrawService.processAnimationFrame();
    	vTaskDelay( vTaskDelayTimeout );
	}
}

boolean AnimationsController::serialCommandReceived() {
	return *imageSelect != currentSelection;
}
