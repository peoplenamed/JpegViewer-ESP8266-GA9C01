#include "JpegDrawService.h"

void JpegDrawService::chooseAnimation()
{
    Log.info("JpegDrawService::chooseAnimation currentSelection: %i\n", currentSelection);
	switch(currentSelection) {
	case 1:
		#ifdef DEBUG
			Log.info("[JpegDrawService]<chooseAnimation>  Drawing #1 DimondEyes\n");
		#endif
		jpegAnimation = new DimondEyes();
		break;
	case 2:
		#ifdef DEBUG
			Log.info("[JpegDrawService]<chooseAnimation>  Drawing #2 OctoCat\n");
		#endif
		jpegAnimation = new OctoCat();
		break;
	case 3:
		#ifdef DEBUG
			Log.info("[JpegDrawService]<chooseAnimation>  Drawing #3 CalvinAndHobbes\n");
		#endif
		jpegAnimation = new CalvinAndHobbes();
		break;
	default:
		#ifdef DEBUG
			Log.info("[JpegDrawService]<chooseAnimation>  Drawing default CalvinDuplicator\n");
		#endif
		jpegAnimation = new CalvinDuplicator();
		break;
	}
	totalFrames = jpegAnimation->getTotalFrames();
}

void JpegDrawService::processAnimationFrame() {
	#ifdef DEBUG
		Log.trace("JpegDrawService::processAnimationFrame  currentFrame: %i\n", currentFrame);
	#endif
    drawJpeg();
}

void JpegDrawService::processCustomCommand(String customJpeg) {
}

void JpegDrawService::processCommand(int selected) {
    Log.info("JpegDrawService::processCommand selected: %i\n", selected);
    currentFrame = 1;
    currentSelection = selected;
    chooseAnimation();
}

void JpegDrawService::drawJpeg() {
	if (jpegAnimation != NULL){
		if(isAnimationRunning()) {
			#ifdef DEBUG
				Log.trace("JpegDrawService::drawJpeg  currentFrame: %i\n", currentFrame);
			#endif
			jpegAnimation->renderFrame(currentFrame);
			afterFrameEvents();
		} else {
			endAnimation();
		}
	}
}

void JpegDrawService::endAnimation() {
		currentSelection = 0;
		jpegAnimation = NULL;
		currentFrame = 0;
}

boolean JpegDrawService::isAnimationRunning() {
	boolean result = currentFrame <= totalFrames;
	#ifdef DEBUG
		Log.trace("JpegDrawService::isAnimationRunning  currentFrame(%i) <= totalFrames(%i): %T\n",
		currentFrame, totalFrames, result);
	#endif
	return result;
}

void JpegDrawService::incrementFrame() {
	#ifdef DEBUG
		Log.trace("JpegDrawService::incrementFrame  currentFrame++: %i\n", currentFrame + 1);
	#endif
	currentFrame++;
}

void JpegDrawService::updateTotalFrames() {
	totalFrames = jpegAnimation->getTotalFrames();
	#ifdef DEBUG
		Log.trace("JpegDrawService::updateTotalFrames  totalFrames: %i\n", totalFrames);
	#endif
}

void JpegDrawService::afterFrameEvents() {
	#ifdef DEBUG
		Log.trace("JpegDrawService::afterFrameEvents  currentFrame: %i\n", currentFrame);
	#endif
	if (isAnimationRunning()) {
		incrementFrame();
	} else if (currentSelection != 0){
		currentSelection = 0;
	}
}

void JpegDrawService::setDrawBackgroundColor(bool _drawBackgroundColor) {
    drawBackgroundColor = _drawBackgroundColor;
}