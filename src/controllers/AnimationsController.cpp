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
	case 25:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #25 CircleWipe\n");
		#endif
		mathAnimation = new CircleWipe();
		mathAnimation->setTotalFrames(120);
		mathWipe = false;
		break;
	case 26:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #26 CircleWipe\n");
		#endif
		mathAnimation = new CircleWipe();
		mathAnimation->setTotalFrames(120);
		mathWipe = true;
		break;
	case 27:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #27 TriangleWipe\n");
		#endif
		mathAnimation = new TriangleWipe();
		mathAnimation->setTotalFrames(120);
		mathWipe = false;
		break;
	case 28:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #28 TriangleWipe\n");
		#endif
		mathAnimation = new TriangleWipe();
		mathAnimation->setTotalFrames(50);
		mathWipe = true;
		break;
	case 29:
		#ifdef DEBUG
			Log.info("[AnimationsController]<chooseAnimation>  Drawing #29 CircleWipe\n");
		#endif
		mathAnimation = new CircleWipe();
		mathAnimation->setTotalFrames(20);
		mathWipe = false;
		break;

	}
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
			} else {
				displayService.wipeScreen(true, backgroundColor);
				chooseAnimation(); 
			}
			updateFrames(); 
		}

		drawAnimation();
		textDrawService.processAnimationFrame();
		jpegDrawService.processAnimationFrame();
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
	// if (jpegAnimation != NULL) {
	// 	#ifdef DEBUG
	// 		Log.info("[AnimationsController]<drawAnimation> Drawing jpegAnimation\n");
	// 	#endif
	// 	// jpegAnimation->renderFrame(currentFrame);
	// 	afterJpegFrameEvents();
	// }

	if (mathAnimation != NULL) {
		#ifdef DEBUG
			Log.info("[AnimationsController]<drawAnimation> Drawing mathAnimation\n");
		#endif
		mathAnimation->renderFrame(currentFrame, mathWipe, foregroundColor, backgroundColor);
		afterMathFrameEvents();
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
		#ifdef DEBUG
			Log.info("[AnimationsController]<updateFrames> (*imageSelect < 25) \n");
		#endif
		totalFrames = animation->getTotalFrames();
		// jpegAnimation = NULL;
		mathAnimation = NULL;
	} else if (*imageSelect < 50) {
		#ifdef DEBUG
			Log.info("[AnimationsController]<updateFrames> (*imageSelect < 50) \n");
		#endif
		totalFrames = mathAnimation->getTotalFrames();
		animation = NULL;
		// jpegAnimation = NULL;
	} else {
		totalFrames = 0;
		// #ifdef DEBUG
		// 	Log.info("[AnimationsController]<updateFrames> (else) \n");
		// #endif
		// Log.info("---------1---------\n");
		// totalFrames = jpegAnimation->getTotalFrames();
		Log.info("---------2---------\n");
		animation = NULL;
		Log.info("---------3---------\n");
		mathAnimation = NULL;
		Log.info("---------4---------\n");
	}
	#ifdef DEBUG
		Log.info("[AnimationsController]<updateFrames> totalFrames:%i, animation=?, mathAnimation=? \n", totalFrames);
		Log.info("[AnimationsController]<updateFrames> totalFrames:%i, animation=%b, mathAnimation=%b \n", totalFrames,animation,mathAnimation);
	#endif
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

// void AnimationsController::afterJpegFrameEvents() {
// 	if (isAnimationRunning()) {
// 		incrementFrame();
// 		setColorShiftingEffect();
// 	} else if (currentSelection == *imageSelect){
// 		*imageSelect = 0;
// 		currentSelection = -1;
// 	}
// }

void AnimationsController::afterMathFrameEvents() {
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
