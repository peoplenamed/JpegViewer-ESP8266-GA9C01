#include "AnimationsController.h"

void AnimationsController::init(int *_imageSelect, int *_textSelect, String *_userDefinedText) {
	imageSelect = _imageSelect;
	textSelect = _textSelect;
	userDefinedText = _userDefinedText;
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
		if (serialCommandReceived()) {
			currentSelection = *imageSelect;
			currentFrame = 1;
			if (*imageSelect > 74) {
				// This is hacky to get the ball down the road.
				// Need to make custom commands for everything.
				int selectedOffset = *imageSelect - 74;
				Log.info("[AnimationsController]<processAnimationFrame>  (jpeg) serialCommandReceived %i, %i \n", selectedOffset, currentSelection);
				jpegDrawService.processCommand(selectedOffset);
			} else if (*imageSelect > 49) {
				// This is hacky to get the ball down the road.
				// Need to make custom commands for everything.
				int selectedOffset = *imageSelect - 49;
				Log.info("[AnimationsController]<processAnimationFrame>  (text) serialCommandReceived %i, %i \n", selectedOffset, currentSelection);
				textDrawService.processCommand(selectedOffset);
			} else if (*imageSelect > 24) {
				// This is hacky to get the ball down the road.
				// Need to make custom commands for everything.
				int selectedOffset = *imageSelect - 24;
				Log.info("[AnimationsController]<processAnimationFrame>  (math) serialCommandReceived %i, %i \n", selectedOffset, currentSelection);
				mathDrawService.processCommand(selectedOffset);
			} else {
				// This is hacky to get the ball down the road.
				// Need to make custom commands for everything.
				displayService.wipeScreen(true, backgroundColor);
				Log.info("[AnimationsController]<processAnimationFrame>  (face) serialCommandReceived %i \n", currentSelection);
				// chooseAnimation(); 
				// faceDrawService.processCommand(currentSelection);
				faceDrawServiceExperimental.processCommand(currentSelection);
			}
		} else if (customSerialCommandReceived()) {
			currentUserDefinedText = *userDefinedText;
			textDrawService.processCustomCommand(currentUserDefinedText);
		}

		// drawAnimation();
		// textDrawService.processAnimationFrame();
		// jpegDrawService.processAnimationFrame();
		// mathDrawService.processAnimationFrame();
		// faceDrawService.processAnimationFrame();
		smashFrames();
    	vTaskDelay( vTaskDelayTimeout );
	}
}

void AnimationsController::smashFrames() {
	FrameObject frameObject = faceDrawServiceExperimental.getFrameObject();
	std::vector<FrameObject> frameObjects;
	frameObjects.push_back(frameObject);
	Log.info("[AnimationsController]<smashFrames>  frameObjects.size(): %i \n", frameObjects.size());
	frameSmasherService.smashFrames(frameObjects);
}

boolean AnimationsController::serialCommandReceived() {
	return *imageSelect != currentSelection;
}

boolean AnimationsController::customSerialCommandReceived() {
	return *userDefinedText != currentUserDefinedText;
}
