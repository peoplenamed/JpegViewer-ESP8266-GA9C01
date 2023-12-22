#include "FaceDrawService.h"

void FaceDrawService::chooseAnimation()
{
    Log.info("FaceDrawService::chooseAnimation currentSelection: %i\n", currentSelection);
	switch(currentSelection) {
{
	case 1:
		#ifdef DEBUG
			Log.info("[FaceDraw]<chooseAnimation>  Drawing #1 FangFaceAnimation\n");
		#endif
		animation = new FangFaceAnimation();
		break;
	case 2:
		#ifdef DEBUG
			Log.info("[FaceDraw]<chooseAnimation>  Drawing #2 GrumpyFaceAnimation\n");
		#endif
		animation = new GrumpyFaceAnimation();
		break;
	case 3:
		#ifdef DEBUG
			Log.info("[FaceDraw]<chooseAnimation>  Drawing #3 WinkFaceAnimation\n");
		#endif
		animation = new WinkFaceAnimation();
		break;
	case 4:
		#ifdef DEBUG
			Log.info("[FaceDraw]<chooseAnimation>  Drawing #4 AngryFaceAnimation\n");
		#endif
		animation = new AngryFaceAnimation();
		break;
	case 5:
		#ifdef DEBUG
			Log.info("[FaceDraw]<chooseAnimation>  Drawing #5 new \n");
		#endif
		animation = new SatisfiedFaceAnimation;
		break;
	case 6:
		#ifdef DEBUG
			Log.info("[FaceDraw]<chooseAnimation>  Drawing #6 NormalAnimation\n");
		#endif
		animation = new NormalAnimation();
		break;
	case 8:
		#ifdef DEBUG
			Log.info("[FaceDraw]<chooseAnimation>  Drawing #8 LoadingFaceAnimation\n");
		#endif
		animation = new LoadingFaceAnimation();
		break;
	case 9:
		#ifdef DEBUG
			Log.info("[FaceDraw]<chooseAnimation>  Drawing #9 HappyFaceAnimation\n");
		#endif
		animation = new HappyFaceAnimation();
		break;
	case 10:
		#ifdef DEBUG
			Log.info("[FaceDraw]<chooseAnimation>  Drawing #10 PukeRainbowFaceAnimation\n");
		#endif
		animation = new PukeRainbowFaceAnimation();
		break;
	case 11:
		#ifdef DEBUG
			Log.info("[FaceDraw]<chooseAnimation>  Drawing #11 AngryFaceAnimation\n");
		#endif
		animation = new AngryFaceAnimation();
		break;
	case 12:
		#ifdef DEBUG
			Log.info("[FaceDraw]<chooseAnimation>  Drawing #12 SleepFaceAnimation\n");
		#endif
		animation = new SleepFaceAnimation();
		break;
	case 13:
		#ifdef DEBUG
			Log.info("[FaceDraw]<chooseAnimation>  Drawing #13 GrumpyFaceAnimation\n");
		#endif
		animation = new GrumpyFaceAnimation();
		break;
	case 14:
		#ifdef DEBUG
			Log.info("[FaceDraw]<chooseAnimation>  Drawing #14 WinkFaceAnimation\n");
		#endif
		animation = new WinkFaceAnimation();
		break;
	case 15:
		#ifdef DEBUG
			Log.info("[FaceDraw]<chooseAnimation>  Drawing #15 SatisfiedFaceAnimation\n");
		#endif
		animation = new SatisfiedFaceAnimation();
		break;
	case 16:
		#ifdef DEBUG
			Log.info("[FaceDraw]<chooseAnimation>  Drawing #16 PopEyeFaceAnimation\n");
		#endif
		animation = new PopEyeFaceAnimation();
		break;
	case 17:
		#ifdef DEBUG
			Log.info("[FaceDraw]<chooseAnimation>  Drawing #17 FangFaceAnimation\n");
		#endif
		animation = new FangFaceAnimation();
		break;
	default:
		#ifdef DEBUG
			Log.info("[FaceDraw]<chooseAnimation>  Drawing default PopEyeFaceAnimation\n");
		#endif
		animation = new PopEyeFaceAnimation();
		break;
	}
	}
	totalFrames = animation->getTotalFrames();
}

void FaceDrawService::processAnimationFrame() {
	#ifdef DEBUG
		Log.trace("FaceDrawService::processAnimationFrame  currentFrame: %i\n", currentFrame);
	#endif
    drawJpeg();
}

void FaceDrawService::processCustomCommand(String customJpeg) {
}

void FaceDrawService::processCommand(int selected) {
    Log.info("FaceDrawService::processCommand selected: %i\n", selected);
    currentFrame = 1;
    currentSelection = selected;
    chooseAnimation();
}

void FaceDrawService::drawJpeg() {
	if (animation != NULL){
		if(isAnimationRunning()) {
			#ifdef DEBUG
				Log.trace("FaceDrawService::drawJpeg  currentFrame: %i\n", currentFrame);
			#endif
			animation->renderFrame(currentFrame, foregroundColor, backgroundColor, drawBackgroundColor);
			afterFrameEvents();
		} else {
			endAnimation();
		}
	}
}

void FaceDrawService::endAnimation() {
		currentSelection = 0;
		animation = NULL;
		currentFrame = 0;
}

boolean FaceDrawService::isAnimationRunning() {
	boolean result = currentFrame <= totalFrames;
	#ifdef DEBUG
		Log.trace("FaceDrawService::isAnimationRunning  currentFrame(%i) <= totalFrames(%i): %T\n",
		currentFrame, totalFrames, result);
	#endif
	return result;
}

void FaceDrawService::incrementFrame() {
	#ifdef DEBUG
		Log.trace("FaceDrawService::incrementFrame  currentFrame++: %i\n", currentFrame + 1);
	#endif
	currentFrame++;
}

void FaceDrawService::updateTotalFrames() {
	totalFrames = animation->getTotalFrames();
	#ifdef DEBUG
		Log.trace("FaceDrawService::updateTotalFrames  totalFrames: %i\n", totalFrames);
	#endif
}

void FaceDrawService::afterFrameEvents() {
	#ifdef DEBUG
		Log.trace("FaceDrawService::afterFrameEvents  currentFrame: %i\n", currentFrame);
	#endif
	if (isAnimationRunning()) {
		incrementFrame();
		setColorShiftingEffect();
	} else if (currentSelection != 0) {
		currentSelection = 0;
	}
}

void FaceDrawService::setColorShiftingEffect() {
	if (randomColors) {
		foregroundColor = colorsService.getNextRGB(foregroundColor);
		backgroundColor = colorsService.getNextRGB(backgroundColor);
	} else if (rainbowColors) {
		if (currentAngle >= 360){ currentAngle = 0; }
		// Defining a table is less CPU intensive.
		foregroundColor = colorsService.getColorWheelByDegrees(currentAngle);
		// foregroundColor = colorsService.powerHSV(currentAngle);
		currentAngle += 20;
	}
}