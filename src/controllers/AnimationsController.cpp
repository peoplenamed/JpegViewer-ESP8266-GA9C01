#include "AnimationsController.h"

AnimationsController::AnimationsController()
{
	Log.info("Animations initializer\n");
}

void AnimationsController::init(int *_imageSelect, boolean *_commandReceived) {
	imageSelect = _imageSelect;
	commandReceived = _commandReceived;
	setupDisplay();

	auto task = [](void* arg) { static_cast<AnimationsController*>(arg)->processAnimationFrame(); };
	xTaskCreate(task, "processAnimationFrame", 3092, this, 2, NULL);
}

void AnimationsController::processAnimationFrame() {
	for(;;) {
		if (*imageSelect != currentSelection) {
			wipeScreen(true);
			Log.info("commandReceived: %T \n", commandReceived);
			commandReceived = false;
			currentFrame = 1;
			currentSelection = *imageSelect;
		}
		chooseAnimation();
    	vTaskDelay( 250 );
	}
}

void AnimationsController::setupDisplay()
{
	display.setupDisplay();
	splashScreen();
}

void AnimationsController::chooseAnimation()
{
	switch(*imageSelect)
	{
	case 0:
		lastFrameDrawn = popEyeFaceAnimation.renderFrame(currentFrame);
		totalFrames = popEyeFaceAnimation.frames;
		break;
	case 1:
		lastFrameDrawn = fangFaceAnimation.renderFrame(currentFrame);
		totalFrames = fangFaceAnimation.frames;
		break;
	case 2:
		// Log.info("AnimationsController::grumpyFace()\n");
		lastFrameDrawn = grumpyFaceAnimation.renderFrame(currentFrame);
		totalFrames = grumpyFaceAnimation.frames;
		break;
	case 3:
		// Log.info("AnimationsController::winkFaceAnimation()\n");
		lastFrameDrawn = winkFaceAnimation.renderFrame(currentFrame);
		totalFrames = winkFaceAnimation.frames;
		break;
	case 4:
		// Log.info("AnimationsController \n");
		lastFrameDrawn = angryFaceAnimation.renderFrame(currentFrame);
		totalFrames = angryFaceAnimation.frames;
		break;
	case 5:
		// Log.info("AnimationsController \n");
		lastFrameDrawn = satisfiedFaceAnimation.renderFrame(currentFrame);
		totalFrames = satisfiedFaceAnimation.frames;
		break;
	case 6:
		// Log.info("AnimationsController \n");
		lastFrameDrawn = normalAnimation.renderFrame(currentFrame);
		totalFrames = normalAnimation.frames;
		break;
	case 7:
		// Log.info("AnimationsController \n");
		// lastFrameDrawn = .renderFrame(currentFrame);
		diamondEyes();
		break;
	case 8:
		// Log.info("AnimationsController \n");
		splashScreen();
		break;
	case 9:
		Log.trace("happyFaceAnimation \n");
		lastFrameDrawn = happyFaceAnimation.renderFrame(currentFrame);
		totalFrames = happyFaceAnimation.frames;
		break;
	case 10:
		// Log.info("AnimationsController \n");
		lastFrameDrawn = pukeRainbowFaceAnimation.renderFrame(currentFrame);
		totalFrames = pukeRainbowFaceAnimation.frames;
		break;
	case 11: {
		Log.trace("AngryFaceAnimation \n");
		lastFrameDrawn = angryFaceAnimation.renderFrame(currentFrame);
		totalFrames = angryFaceAnimation.frames;
		break;
	}
	case 12: {
		Log.trace("SleepFaceAnimation \n");
		lastFrameDrawn = sleepFaceAnimation.renderFrame(currentFrame);
		totalFrames = sleepFaceAnimation.frames;
		break;
	}
	case 13: {
		Log.trace("GrumpyFaceAnimation \n");
		lastFrameDrawn = grumpyFaceAnimation.renderFrame(currentFrame);
		totalFrames = grumpyFaceAnimation.frames;
		break;
	}
	case 14: {
		Log.trace("winkFaceAnimation \n");
		lastFrameDrawn = winkFaceAnimation.renderFrame(currentFrame);
		totalFrames = winkFaceAnimation.frames;
		break;
	}
	case 15: {
		Log.trace("SatisfiedFaceAnimation \n");
		lastFrameDrawn = satisfiedFaceAnimation.renderFrame(currentFrame);
		totalFrames = satisfiedFaceAnimation.frames;
		break;
	}
	case 16: {
		Log.trace("PopEyeFaceAnimation \n");
		lastFrameDrawn = popEyeFaceAnimation.renderFrame(currentFrame);
		totalFrames = popEyeFaceAnimation.frames;
		break;
	}
	case 17: {
		Log.trace("FangFaceAnimation \n");
		lastFrameDrawn = fangFaceAnimation.renderFrame(currentFrame);
		totalFrames = fangFaceAnimation.frames;
		break;
	}
	case 20:
		// lastFrameDrawn = .renderFrame(currentFrame);
		circleWipe(10, false);
		break;
	case 21:
		// lastFrameDrawn = .renderFrame(currentFrame);
		circleWipe(10, true);
		break;
	case 22:
		// lastFrameDrawn = .renderFrame(currentFrame);
		triangleWipe(false);
		break;
	case 23:
		// lastFrameDrawn = .renderFrame(currentFrame);
		triangleWipe(true);
		break;
	case 30:
		// lastFrameDrawn = .renderFrame(currentFrame);
		drawRimCircle(120, false, 10);
		break;
	case 31:
		// lastFrameDrawn = .renderFrame(currentFrame);
		northText("North");
		southText("South");
		eastText("East");
		westText("West");
		centerText("100%");
		break;
	case 50:
		// lastFrameDrawn = .renderFrame(currentFrame);
		octocat();
		break;
	case 51:
		// lastFrameDrawn = .renderFrame(currentFrame);
		calvinAndHobbes();
		break;
	default:
		// // lastFrameDrawn = .renderFrame(currentFrame);
		calvinDuplicator();
		break;
	}

	afterFrameEvent();
}

/** STATIC IMAGES **/
void AnimationsController::calvinAndHobbes()
{
	display.drawImage("/download.jpeg");
}
void AnimationsController::octocat()
{
	display.drawImage("/octocat.jpg");
}

/** ANIMATIONS **/
void AnimationsController::calvinDuplicator()
{
	Log.info(".. calvinDuplicator2");
	display.drawJpgAnimation("1Ys_", ".jpg", 19, 3);
}



boolean AnimationsController::isAnimationRunning() {
		// Log.info("isAnimationRunning: %T..\n", (currentFrame < totalFrames));
	return currentFrame <= totalFrames;
}

void AnimationsController::afterFrameEvent() {
	if (isAnimationRunning()) {
		currentFrame++;
		Log.info("currentFrame++....%d\n", currentFrame);
	}
}

void AnimationsController::diamondEyes()
{
	// normalFace();
	delay(400);
	display.drawImage("/diamondEyes_0001.jpg");
	delay(200);
	display.drawImage("/diamondEyes_0002.jpg");
	delay(200);
	display.drawImage("/diamondEyes_0003.jpg");
	delay(200);
	display.drawImage("/diamondEyes_0002.jpg");
	delay(200);
	display.drawImage("/diamondEyes_0001.jpg");
	delay(200);
	display.drawImage("/diamondEyes_0003.jpg");
	delay(200);
	display.drawImage("/diamondEyes_0002.jpg");
	delay(200);
	display.drawImage("/diamondEyes_0003.jpg");
	delay(200);
	display.drawImage("/diamondEyes_0001.jpg");
	delay(200);
	// normalFace();
}

void AnimationsController::splashScreen()
{
	// Log.info("AnimationsController::splashScreen()\n");

	for (int i = 1; i <= loadingFaceAnimation.frames; i++) {
		loadingFaceAnimation.renderFrame(i);
		delay(140);
	}
	// Log.info("AnimationsController::splashScreen() DONE \n");
}

void AnimationsController::northText(String _text)
{
	display.drawText(_text, 85, 10, 3, compassTextColor);
}

void AnimationsController::southText(String _text)
{
	display.drawText(_text, 85, 200, 3, compassTextColor);
}

void AnimationsController::eastText(String _text)
{
	display.drawText(_text, 0, 110, 3, compassTextColor);
}

void AnimationsController::westText(String _text)
{
	display.drawText(_text, 185, 110, 3, compassTextColor);
}

void AnimationsController::centerText(String _text)
{
	display.drawText(_text, 85, 110, 3, compassTextColor);
}

void AnimationsController::errorText(String _text)
{
	display.drawText(_text, 0, 105, 4, 3);
}

void AnimationsController::successText(String _text)
{
	display.drawText(_text, 0, 105, 5, 4);
}

void AnimationsController::userDefinedText(String _text, int _x, int _y, int _size, int _color)
{
	display.drawText(_text, _x, _y, _size, _color);
}

void AnimationsController::wipeScreen(boolean wipe)
{
	display.wipeScreen(wipe);
}

void AnimationsController::drawRimCircle(int32_t radius, boolean wipe, int maxWipe)
{
	display.wipeScreen(wipe);

	int32_t _x = 120; // radius/2
	int32_t _y = 120; // radius/2

	for(int y = 0; y < maxWipe; y++)
	{
		display.DrawCircle(_x, _y, radius - y, hexColors.getRandomColor());
	}
}

void AnimationsController::circleWipe(int radius, boolean wipe)
{
	display.wipeScreen(wipe);
	int32_t w = _width;
	int32_t h = _height;
	// uint32_t start;
	int32_t x, y;
	int32_t r2 = radius * 2;
	int32_t w1 = w + radius;
	int32_t h1 = h + radius;

	for(x = 0; x < w1; x += r2)
	{
		for(y = 0; y < h1; y += r2)
		{
			display.DrawCircle(x, y, radius, hexColors.getRandomColor());
		}
	}
}

void AnimationsController::triangleWipe(boolean wipe)
{
	display.wipeScreen(wipe);
	int32_t i;
	int32_t cx = _width / 2;
	int32_t cy = _height / 2;
	int32_t cx1 = cx - 1;
	int32_t cy1 = cy - 1;
	int32_t cn = min(cx1, cy1);
	// digit size

	for(i = 0; i < cn; i += 5)
	{
		display.DrawTriangle(cx1,
							 cy1 - i, // peak
							 cx1 - i,
							 cy1 + i, // bottom left
							 cx1 + i,
							 cy1 + i, // bottom right
							 hexColors.getRandomColor());
	}
}
