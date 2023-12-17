#include "TextController.h"

TextController::TextController()
{
	Log.info("Text initializer\n");
}

void TextController::init(int *_textSelect, String *_userDefinedText) {
	textSelect = _textSelect;
	userDefinedText = _userDefinedText;
	setupDisplay();

	auto task = [](void* arg) { static_cast<TextController*>(arg)->processTextFrame(); };
	xTaskCreate(task, "processTextFrame", 3092, this, 2, NULL);
}

void TextController::setupDisplay()
{
	displayService.setupDisplay();
	displayService.wipeScreen(true, backgroundColor);
}

void TextController::chooseText()
{
    if (*textSelect < 20) {
        textDraw = new TextOverLay();
    } else {
        textDraw = new TextAlert();
    }

	switch(*textSelect) {
        case 0:
            _textType = 1;
            _text = "North";
            _wipe = true;
            _currentColor = foregroundColor;
            break;
        case 1:
            _textType = 2;
            _text = "South";
            _wipe = true;
            _currentColor = foregroundColor;
            break;
        case 2:
            _textType = 3;
            _text = "East";
            _wipe = true;
            _currentColor = foregroundColor;
            break;
        case 3:
            _textType = 4;
            _text = "West";
            _wipe = true;
            _currentColor = foregroundColor;
            break;
        case 4:
            _textType = 5;
            _text = "center";
            _wipe = true;
            _currentColor = foregroundColor;
            break;
        case 20:
            _textType = 1;
            _text = "ERROR!";
            _wipe = true;
            _currentColor = foregroundColor;
            break;
        case 21:
            _textType = 2;
            _text = "SUCCESS!";
            _wipe = true;
            _currentColor = foregroundColor;
            break;
        // case 7:
            // FIX ME!
            // customText("100%");
        // default:
        // 	break;
	}
}

void TextController::processTextFrame() {
	for(;;) {
        processSerial();
		drawText();
    	vTaskDelay( vTaskDelayTimeout );
	}
}

void TextController::processSerial() {
    boolean serialReceived = serialCommandReceived();
    boolean customSerialReceived = customSerialCommandReceived();
    if (serialReceived || customSerialReceived) {
        currentFrame = 1;

        if (serialReceived) {
            currentSelection = *textSelect;
            chooseText();
        } else if (customSerialReceived) {
            currentUserDefinedTextSelection = *userDefinedText;
            processCustomMessage();
        }
        updateFrames();
    }
}

boolean TextController::serialCommandReceived() {
	return *textSelect != currentSelection;
}

boolean TextController::customSerialCommandReceived() {
	return *userDefinedText != currentUserDefinedTextSelection;
}

void TextController::drawText() {
	if (textDraw != NULL && isTextRunning()) {
		textDraw->renderFrame(_textType, _text, _wipe, _currentColor);
		afterFrameEvents();
	}
}

boolean TextController::isTextRunning() {
	return currentFrame <= totalFrames;
}

void TextController::incrementFrame() {
    Log.info("currentFrame: %i\n", currentFrame);
	currentFrame++;
}

void TextController::updateFrames() {
	totalFrames = textDraw->getTotalFrames();
}

void TextController::afterFrameEvents() {
	if (isTextRunning()) {
		incrementFrame();
		setColorShiftingEffect();
	} else if (currentSelection == *textSelect){
		*textSelect = NULL;
		currentSelection = NULL;
	}
}

void TextController::setColorShiftingEffect() {
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


void TextController::processCustomMessage()
{
	// Example Messages
	//   <*Howdy friend|0|110|3|65152|0>
	//   <*75%|20|140|3|3|0>
    Log.info("-- processCustomMessage --");
	String charsAsString = *userDefinedText;
	charsAsString.remove(0, 1); // remove asterisk
	String __text = getValueFromDelimitedString(charsAsString, '|', 0);
	String __x = getValueFromDelimitedString(charsAsString, '|', 1);
	String __y = getValueFromDelimitedString(charsAsString, '|', 2);
	String __size = getValueFromDelimitedString(charsAsString, '|', 3);
	String __color = getValueFromDelimitedString(charsAsString, '|', 4);
	String __wipe = getValueFromDelimitedString(charsAsString, '|', 5);

    _wipe = __wipe.toInt() == 1;

    // char* customStringAsChars = getCharsFromString(__text);
    _text = getCharsFromString(__text);
    _currentColor = __color.toInt();

    textDraw = new TextOverLay();
    _textType = 8;
    textDraw->setCustomSettings(__x.toInt(), __y.toInt(), __size.toInt(), __color.toInt());
    // textDraw->renderFrame(_textType, _text, _wipe, _currentColor);
    // textDraw->renderFrame(_textType, _text, shouldWipe, __color.toInt());
}

char* TextController::getCharsFromString(String str) {
    const int length = str.length(); 
    // declaring character array (+1 for null terminator) 
    char* customStringAsChars = new char[length + 1]; 
    // copying the contents of the 
    // string to char array 
    strcpy(customStringAsChars, str.c_str()); 
    return customStringAsChars;
}

String TextController::getValueFromDelimitedString(String stringData, char separator, int index)
{
	int found = 0;
	int strIndex[] = {0, -1};
	int maxIndex = stringData.length() - 1;

	for(int i = 0; i <= maxIndex && found <= index; i++)
	{
		if(stringData.charAt(i) == separator || i == maxIndex)
		{
			found++;
			strIndex[0] = strIndex[1] + 1;
			strIndex[1] = (i == maxIndex) ? i + 1 : i;
		}
	}

	return found > index ? stringData.substring(strIndex[0], strIndex[1]) : "";
}
