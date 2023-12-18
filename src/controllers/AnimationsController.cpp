#include "AnimationsController.h"

AnimationsController::AnimationsController()
{
	Log.info("[AnimationsController]<initializer>\n");
}

void AnimationsController::init(int *_imageSelect) {
	imageSelect = _imageSelect;
	setupDisplay();

	auto task = [](void* arg) { static_cast<AnimationsController*>(arg)->processAnimationFrame(); };
	xTaskCreate(task, "processAnimationFrame", 3092, this, 2, NULL);
}

void AnimationsController::setupDisplay()
{
	displayService.setupDisplay();
	displayService.wipeScreen(true, backgroundColor);
}

void AnimationsController::chooseAnimation()
{
	switch(*imageSelect)
	{
	case 0:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #0 PopEyeFaceAnimation\n");
		#endif
		animation = new PopEyeFaceAnimation();
		break;
	case 1:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #1 FangFaceAnimation\n");
		#endif
		animation = new FangFaceAnimation();
		break;
	case 2:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #2 GrumpyFaceAnimation\n");
		#endif
		animation = new GrumpyFaceAnimation();
		break;
	case 3:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #3 WinkFaceAnimation\n");
		#endif
		animation = new WinkFaceAnimation();
		break;
	case 4:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #4 AngryFaceAnimation\n");
		#endif
		animation = new AngryFaceAnimation();
		break;
	case 5:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #5 new \n");
		#endif
		animation = new SatisfiedFaceAnimation;
		break;
	case 6:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #6 NormalAnimation\n");
		#endif
		animation = new NormalAnimation();
		break;
	case 8:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #8 LoadingFaceAnimation\n");
		#endif
		animation = new LoadingFaceAnimation();
		break;
	case 9:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #9 HappyFaceAnimation\n");
		#endif
		animation = new HappyFaceAnimation();
		break;
	case 10:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #10 PukeRainbowFaceAnimation\n");
		#endif
		animation = new PukeRainbowFaceAnimation();
		break;
	case 11:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #11 AngryFaceAnimation\n");
		#endif
		animation = new AngryFaceAnimation();
		break;
	case 12:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #12 SleepFaceAnimation\n");
		#endif
		animation = new SleepFaceAnimation();
		break;
	case 13:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #13 GrumpyFaceAnimation\n");
		#endif
		animation = new GrumpyFaceAnimation();
		break;
	case 14:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #14 WinkFaceAnimation\n");
		#endif
		animation = new WinkFaceAnimation();
		break;
	case 15:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #15 SatisfiedFaceAnimation\n");
		#endif
		animation = new SatisfiedFaceAnimation();
		break;
	case 16:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #16 PopEyeFaceAnimation\n");
		#endif
		animation = new PopEyeFaceAnimation();
		break;
	case 17:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #17 FangFaceAnimation\n");
		#endif
		animation = new FangFaceAnimation();
		break;
	// FIX ME!
	case 25:
		circleWipe.renderFrame(10, false, foregroundColor, backgroundColor);
		break;
	case 26:
		circleWipe.renderFrame(10, true, foregroundColor, backgroundColor);
		break;
	case 27:
		triangleWipe.renderFrame(false, foregroundColor, backgroundColor);
		break;
	case 28:
		triangleWipe.renderFrame(true, foregroundColor, backgroundColor);
		break;
	case 29:
		drawRimCircle.renderFrame(120, false, foregroundColor, backgroundColor);
		break;
	case 75:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #75 DimondEyes\n");
		#endif
		jpegAnimation = new DimondEyes();
		break;
	case 76:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #76 OctoCat\n");
		#endif
		jpegAnimation = new OctoCat();
		break;
	case 77:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #77 CalvinAndHobbes\n");
		#endif
		jpegAnimation = new CalvinAndHobbes();
		break;
	default:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing default CalvinDuplicator\n");
		#endif
		jpegAnimation = new CalvinDuplicator();
		break;
	}
	updateFrames(); 
}

void AnimationsController::processAnimationFrame() {
	for(;;) {
		if (serialCommandReceived()) {
			displayService.wipeScreen(true, backgroundColor);
			currentFrame = 1;
			currentSelection = *imageSelect;
			chooseAnimation(); 
		}

		drawAnimation();
    	vTaskDelay( vTaskDelayTimeout );
	}
}

boolean AnimationsController::serialCommandReceived() {
	return *imageSelect != currentSelection;
}

void AnimationsController::drawAnimation() {
	if (animation != NULL && isAnimationRunning()) {
		#ifdef DEBUG
			Log.info("[AnimationsController]<drawAnimation> Drawing animation\n");
		#endif
		animation->renderFrame(currentFrame, foregroundColor, backgroundColor);
		afterAnimationFrameEvents();
	}
	if (jpegAnimation != NULL) {
		#ifdef DEBUG
			Log.info("[AnimationsController]<drawAnimation> Drawing jpegAnimation\n");
		#endif
		jpegAnimation->renderFrame(currentFrame);
		afterJpegFrameEvents();
	}
}

boolean AnimationsController::isAnimationRunning() {
	return currentFrame <= totalFrames;
}

void AnimationsController::incrementFrame() {
	currentFrame++;
}

void AnimationsController::updateFrames() {
	if (*imageSelect < 25) {
		totalFrames = animation->getTotalFrames();
		jpegAnimation = NULL;
	} else if (*imageSelect < 50) {
		animation = NULL;
		jpegAnimation = NULL;
	} else {
		totalFrames = jpegAnimation->getTotalFrames();
		animation = NULL;
	}
}

void AnimationsController::afterAnimationFrameEvents() {
	if (isAnimationRunning()) {
		incrementFrame();
		setColorShiftingEffect();
	} else if (currentSelection == *imageSelect){
		*imageSelect = 0;
		currentSelection = -1;
	}
}

void AnimationsController::afterJpegFrameEvents() {
	if (isAnimationRunning()) {
		incrementFrame();
		setColorShiftingEffect();
	} else if (currentSelection == *imageSelect){
		*imageSelect = 0;
		currentSelection = -1;
	}
}

void AnimationsController::setColorShiftingEffect() {
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
