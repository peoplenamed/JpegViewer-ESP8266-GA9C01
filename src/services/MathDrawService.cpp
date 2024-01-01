#include "MathDrawService.h"

void MathDrawService::chooseAnimation()
{
    Log.info("MathDrawService::chooseAnimation currentSelection: %i\n", currentSelection);
	switch(currentSelection) {
	case 1:
		#ifdef DEBUG
			Log.info("[]<chooseAnimation>  Drawing #25 CircleWipe\n");
		#endif
		mathAnimation = new CircleWipe();
		mathAnimation->setTotalFrames(120);
		screenWipe = false;
		break;
	case 2:
		#ifdef DEBUG
			Log.info("[]<chooseAnimation>  Drawing #26 CircleWipe\n");
		#endif
		mathAnimation = new CircleWipe();
		mathAnimation->setTotalFrames(120);
		screenWipe = true;
		break;
	case 3:
		#ifdef DEBUG
			Log.info("[]<chooseAnimation>  Drawing #27 TriangleWipe\n");
		#endif
		mathAnimation = new TriangleWipe();
		mathAnimation->setTotalFrames(120);
		screenWipe = false;
		break;
	case 4:
		#ifdef DEBUG
			Log.info("[]<chooseAnimation>  Drawing #28 TriangleWipe\n");
		#endif
		mathAnimation = new TriangleWipe();
		mathAnimation->setTotalFrames(50);
		screenWipe = true;
		break;
	case 5:
		#ifdef DEBUG
			Log.info("[]<chooseAnimation>  Drawing #29 CircleWipe\n");
		#endif
		mathAnimation = new CircleWipe();
		mathAnimation->setTotalFrames(20);
		screenWipe = false;
		break;

	default:
		#ifdef DEBUG
			Log.info("[MathDrawService]<chooseAnimation>  Drawing default CircleWipe\n");
		#endif
		mathAnimation = new CircleWipe();
		mathAnimation->setTotalFrames(20);
		screenWipe = false;
		break;
	}
	totalFrames = mathAnimation->getTotalFrames();
}

void MathDrawService::processAnimationFrame() {
	#ifdef DEBUG
		Log.trace("MathDrawService::processAnimationFrame  currentFrame: %i\n", currentFrame);
	#endif
    drawJpeg();
}

void MathDrawService::processCustomCommand(String customJpeg) {
}

void MathDrawService::processCommand(int selected) {
    Log.info("MathDrawService::processCommand selected: %i\n", selected);
    currentFrame = 1;
    currentSelection = selected;
    chooseAnimation();
}

void MathDrawService::drawJpeg() {
	if (mathAnimation != NULL){
		if(isAnimationRunning()) {
			#ifdef DEBUG
				Log.trace("MathDrawService::drawJpeg  currentFrame: %i\n", currentFrame);
			#endif
			mathAnimation->renderFrame(currentFrame, screenWipe, foregroundColor, backgroundColor);
			afterFrameEvents();
		} else {
			endAnimation();
		}
	}
}

void MathDrawService::endAnimation() {
	Log.trace("MathDrawService::endAnimation  \n");
	currentSelection = 0;
	mathAnimation = NULL;
	currentFrame = 0;
}

boolean MathDrawService::isAnimationRunning() {
	boolean result = currentFrame <= totalFrames;
	#ifdef DEBUG
		Log.trace("MathDrawService::isAnimationRunning  currentFrame(%i) <= totalFrames(%i): %T\n",
		currentFrame, totalFrames, result);
	#endif
	return result;
}

void MathDrawService::incrementFrame() {
	#ifdef DEBUG
		Log.trace("MathDrawService::incrementFrame  currentFrame++: %i\n", currentFrame + 1);
	#endif
	currentFrame++;
}

void MathDrawService::updateTotalFrames() {
	totalFrames = mathAnimation->getTotalFrames();
	#ifdef DEBUG
		Log.trace("MathDrawService::updateTotalFrames  totalFrames: %i\n", totalFrames);
	#endif
}

void MathDrawService::afterFrameEvents() {
	#ifdef DEBUG
		Log.trace("MathDrawService::afterFrameEvents  currentFrame: %i\n", currentFrame);
	#endif
	if (isAnimationRunning()) {
		incrementFrame();
	} else if (currentSelection != 0) {
		currentSelection = 0;
	}
}

void MathDrawService::setDrawBackgroundColor(bool _drawBackgroundColor) {
    drawBackgroundColor = _drawBackgroundColor;
}

