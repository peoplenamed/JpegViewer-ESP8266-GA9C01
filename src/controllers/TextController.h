#ifndef _TEXT_CONTROLLER_H_
#define _TEXT_CONTROLLER_H_

#include "config.h"
#include "services/DisplayService.h"
#include "services/ColorsService.h"
#include "animations/TextDraw.h"
#include "animations/text/TextAlert.h"
#include "animations/text/TextOverLay.h"

class TextController
{
public:
	TextController();
	//  ~();
	void init(int *_textSelect, String *_userDefinedText);

private:
	// SERVICES
	ColorsService colorsService;
	DisplayService displayService;

	// VARIABLES
    int _textType;
    char* _text;
    boolean _wipe = false;
    uint16_t _currentColor;

	uint16_t backgroundColor = colorsService.white;
	uint16_t foregroundColor = colorsService.black;
	TextDraw *textDraw;
	boolean randomColors = false;
	boolean rainbowColors = true;
	int currentAngle = 0;
	int currentFrame = 0;
	int totalFrames = 0;
	int *textSelect;
    String *userDefinedText;
	int currentSelection = -1;
	String currentUserDefinedTextSelection;
	int vTaskDelayTimeout = 800; // Interval between frames

	// FUNCTIONS
    void processSerial();
	void chooseText();
    void chooseCustomText();
	void afterFrameEvents();
	void updateFrames();
	void setColorShiftingEffect();
	void processTextFrame();
	boolean isTextRunning();
	void processCommand();
	void incrementFrame();
	void drawText();
	boolean serialCommandReceived();
	boolean customSerialCommandReceived();
	void setupDisplay();
	void chooseImage();

    void processCustomMessage();
	String getValueFromDelimitedString(String stringData, char separator, int index);
    char* getCharsFromString(String str);
};

#endif // _TEXT_CONTROLLER_H_
