#include "TextService.h"

void TextService::init(int *_textSelect, String *_userDefinedText) {
	textSelect = _textSelect;
	userDefinedText = _userDefinedText;
	// setupDisplay();

	// auto task = [](void* arg) { static_cast<TextService*>(arg)->processTextFrame(); };
	// xTaskCreate(task, "processTextFrame", 3092, this, 2, NULL);
}

// void TextService::setupDisplay()
// {
// 	// displayService.setupDisplay();
// 	// displayService.wipeScreen(true, backgroundColor);
// }

void TextService::chooseText()
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
	}
}

void TextService::processTextFrame() {
	// for(;;) {
        processSerial();
		drawText();
    	// vTaskDelay( vTaskDelayTimeout );
	// }
}

void TextService::processSerial() {
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

boolean TextService::serialCommandReceived() {
	return *textSelect != currentSelection;
}

boolean TextService::customSerialCommandReceived() {
	return *userDefinedText != currentUserDefinedTextSelection;
}

void TextService::drawText() {
	if (textDraw != NULL && isTextRunning()) {
        boolean wipeFrame = _wipe && (currentFrame == 1);
        Log.info("GONNA WIPE????: %b:\n",wipeFrame);
		textDraw->renderFrame(_textType, _text, wipeFrame, _currentColor);
		afterFrameEvents();
	}
}

boolean TextService::isTextRunning() {
	return currentFrame <= totalFrames;
}

void TextService::incrementFrame() {
    Log.info("currentFrame: %i\n", currentFrame);
	currentFrame++;
}

void TextService::updateFrames() {
	totalFrames = textDraw->getTotalFrames();
}

void TextService::afterFrameEvents() {
	if (isTextRunning()) {
		incrementFrame();
		setColorShiftingEffect();
	} else if (currentSelection == *textSelect){
		*textSelect = NULL;
		currentSelection = NULL;
        *userDefinedText = "";
        currentUserDefinedTextSelection = "";
	}
}

void TextService::setColorShiftingEffect() {
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


void TextService::processCustomMessage()
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

char* TextService::getCharsFromString(String str) {
    const int length = str.length(); 
    // declaring character array (+1 for null terminator) 
    char* customStringAsChars = new char[length + 1]; 
    // copying the contents of the 
    // string to char array 
    strcpy(customStringAsChars, str.c_str()); 
    return customStringAsChars;
}

String TextService::getValueFromDelimitedString(String stringData, char separator, int index)
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
