#include "AnimationsController.h"

AnimationsController::AnimationsController()
{
	Log.info("Animations initializer\n");
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
		animation = new PopEyeFaceAnimation();
		break;
	case 1:
		animation = new FangFaceAnimation();
		break;
	case 2:
		animation = new GrumpyFaceAnimation();
		break;
	case 3:
		animation = new WinkFaceAnimation();
		break;
	case 4:
		animation = new AngryFaceAnimation();
		break;
	case 5:
		animation = new SatisfiedFaceAnimation;
		break;
	case 6:
		animation = new NormalAnimation();
		break;
	case 8:
		animation = new LoadingFaceAnimation();
		break;
	case 9:
		animation = new HappyFaceAnimation();
		break;
	case 10:
		animation = new PukeRainbowFaceAnimation();
		break;
	case 11:
		animation = new AngryFaceAnimation();
		break;
	case 12:
		animation = new SleepFaceAnimation();
		break;
	case 13:
		animation = new GrumpyFaceAnimation();
		break;
	case 14:
		animation = new WinkFaceAnimation();
		break;
	case 15:
		animation = new SatisfiedFaceAnimation();
		break;
	case 16:
		animation = new PopEyeFaceAnimation();
		break;
	case 17:
		animation = new FangFaceAnimation();
		break;
	// FIX ME!
	// case 25:
	// 	CircleWipe circleWipe = new CircleWipe();
	// 	circleWipe.renderFrame(10, false, foregroundColor, backgroundColor);
	// 	break;
	// case 26:
	// 	CircleWipe circleWipe = new CircleWipe();
	// 	circleWipe.renderFrame(10, true, foregroundColor, backgroundColor);
	// 	break;
	// case 27:
	// 	TriangleWipe triangleWipe = new TriangleWipe();
	// 	triangleWipe.renderFrame(false, foregroundColor, backgroundColor);
	// 	break;
	// case 28:
	// 	TriangleWipe triangleWipe = new TriangleWipe();
	// 	triangleWipe.renderFrame(true, foregroundColor, backgroundColor);
	// 	break;
	// case 29:
	// 	DrawRimCircle drawRimCircle = new DrawRimCircle();
	// 	drawRimCircle.renderFrame(120, false, foregroundColor, backgroundColor);
	// 	break;
	case 50:
		// northText("North");
		textDraw = new TextOverLay();
		textDraw->renderFrame(1, "center", true, foregroundColor, backgroundColor);
		break;
	case 51:
		textDraw = new TextOverLay();
		textDraw->renderFrame(2, "center", true, foregroundColor, backgroundColor);
		// southText("South");
		break;
	case 52:
		textDraw = new TextOverLay();
		textDraw->renderFrame(3, "center", true, foregroundColor, backgroundColor);
		// eastText("East");
		break;
	case 53:
		textDraw = new TextOverLay();
		textDraw->renderFrame(4, "center", true, foregroundColor, backgroundColor);
		// westText("West");
		break;
	case 54:
		textDraw = new TextOverLay();
		textDraw->renderFrame(5, "center", true, foregroundColor, backgroundColor);
		// centerText("100%");
		break;
	case 55:
		textDraw = new TextAlert();
		textDraw->renderFrame(1, "ERROR!", true, foregroundColor, backgroundColor);
		break;
	case 56:
		textDraw = new TextAlert();
		textDraw->renderFrame(2, "SUCCESS!", true, foregroundColor, backgroundColor);
		break;
	case 57:
		// FIX ME!
		// customText("100%");
	case 75:
		jpegAnimation = new DimondEyes();
		break;
	case 76:
		jpegAnimation = new OctoCat();
	case 77:
		jpegAnimation = new CalvinAndHobbes();
		break;
	default:
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
	if (animation != NULL) {
		 animation->renderFrame(currentFrame, foregroundColor, backgroundColor);
		afterFrameEvents();
	}
	if (jpegAnimation != NULL) {
		jpegAnimation->renderFrame(currentFrame);
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
		textDraw = NULL;
	} else if (*imageSelect < 50) {
		animation = NULL;
		jpegAnimation = NULL;
		textDraw = NULL;
	} else if (*imageSelect < 75) {
		totalFrames = textDraw->frames;
		animation = NULL;
		jpegAnimation = NULL;
	} else {
		animation = NULL;
		jpegAnimation = NULL;
		textDraw = NULL;
	}
}

void AnimationsController::afterFrameEvents() {
	if (isAnimationRunning()) {
		incrementFrame();
		setColorShiftingEffect();
	} else if (currentSelection == *imageSelect){
		*imageSelect = NULL;
		currentSelection = NULL;
	}
}

void AnimationsController::setColorShiftingEffect() {
	if (randomColors) {
		foregroundColor = colorsService.getNextRGB(foregroundColor);
		backgroundColor = colorsService.getNextRGB(backgroundColor);
	} else if (rainbowColors) {
		if (currentAngle >= 360){ currentAngle = 0; }
		foregroundColor = colorsService.powerHSV(currentAngle);
		// backgroundColor = colorsService.powerHSV(currentAngle + 200);
		currentAngle += 20;
	}
}
