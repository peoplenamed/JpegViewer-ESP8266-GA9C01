#include "TextDrawService.h"

void TextDrawService::init() {
}

void TextDrawService::chooseAnimation()
{
    #ifdef DEBUG
        Log.info("TextDrawService::chooseAnimation selected: %i\n", currentSelection);
    #endif
    if (currentSelection < 20) {
        textDraw = new TextOverLay();
    } else {
        textDraw = new TextAlert();
    }

	switch(currentSelection) {
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

void TextDrawService::processAnimationFrame() {
    #ifdef DEBUG
		Log.trace("TextDrawService::processAnimationFrame  currentFrame: %i\n", currentFrame);
	#endif
    drawText();
}

void TextDrawService::endAnimation() {
		currentSelection = NULL;
        currentUserDefinedTextSelection = "";
		textDraw = NULL;
		currentFrame = 0;
}

void TextDrawService::processCommand(int selected) {
    #ifdef DEBUG
        Log.info("TextDrawService::processCommand selected: %i\n", selected);
    #endif
    currentFrame = 1;
    currentSelection = selected;
    chooseAnimation();
    updateTotalFrames();
}

void TextDrawService::processCustomCommand(String customCmd) {
    currentFrame = 1;
    currentUserDefinedTextSelection = customCmd;
    processCustomMessage(customCmd);
    updateTotalFrames();
}

void TextDrawService::drawText() {
	if (textDraw != NULL && isAnimationRunning()) {
        boolean wipeFrame = _wipe && (currentFrame == 1);
        Log.info("GONNA WIPE????: %b:\n",wipeFrame);
		textDraw->renderFrame(_textType, _text, wipeFrame, _currentColor);
		afterFrameEvents();
	}
}

boolean TextDrawService::isAnimationRunning() {
	return currentFrame <= totalFrames;
}

void TextDrawService::incrementFrame() {
    Log.info("currentFrame: %i\n", currentFrame);
	currentFrame++;
}

void TextDrawService::updateTotalFrames() {
	totalFrames = textDraw->getTotalFrames();
}

void TextDrawService::afterFrameEvents() {
	if (isAnimationRunning()) {
		incrementFrame();
		setColorShiftingEffect();
	} else if (currentSelection == currentSelection){
		currentSelection = NULL;
		currentSelection = NULL;
        // *userDefinedText = "";
        currentUserDefinedTextSelection = "";
	}
}

void TextDrawService::setColorShiftingEffect() {
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


void TextDrawService::processCustomMessage(String charsAsString)
{
	// Example Messages
	//   <*Howdy friend|0|110|3|65152|0>
	//   <*75%|20|140|3|3|0>
    Log.info("-- processCustomMessage --");
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

char* TextDrawService::getCharsFromString(String str) {
    const int length = str.length(); 
    // declaring character array (+1 for null terminator) 
    char* customStringAsChars = new char[length + 1]; 
    // copying the contents of the 
    // string to char array 
    strcpy(customStringAsChars, str.c_str()); 
    return customStringAsChars;
}

String TextDrawService::getValueFromDelimitedString(String stringData, char separator, int index)
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
