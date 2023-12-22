#ifndef _TEXT_CONTROLLER_H_
#define _TEXT_CONTROLLER_H_

#include "config.h"
#include "services/DisplayService.h"
#include "services/ColorsService.h"
#include "animations/TextDraw.h"
#include "animations/text/TextAlert.h"
#include "animations/text/TextOverLay.h"
#include "services/DrawFrameService.h"

class TextDrawService : public DrawFrameService
{
public:
	TextDrawService(ColorsService& colorsService, DisplayService& displayService)
        : colorsService(colorsService), displayService(displayService) {
		Log.info("TextDrawService initializer\n");
    }
	//  ~();
	void init();
	void processAnimationFrame();
	void processCommand(int selected);
	void processCustomCommand(String customCmd);

private:
	// SERVICES
	ColorsService& colorsService;
    DisplayService& displayService;


	// VARIABLES
    int _textType;
    char* _text;
    boolean _wipe = false;
	bool drawBackgroundColor = false;
    uint16_t _currentColor;

	uint16_t backgroundColor = colorsService.red;
	uint16_t foregroundColor = colorsService.white;
	TextDraw *textDraw;
	boolean randomColors = false;
	boolean rainbowColors = true;
	int currentAngle;
	int currentFrame;
	int totalFrames;
	int *textSelect;
    String *userDefinedText;
	int currentSelection = -1;
	String currentUserDefinedTextSelection;

	// FUNCTIONS
	void afterFrameEvents();
	// void updateFrames();
	void setColorShiftingEffect();
	void incrementFrame();
	void drawText();
	void setupDisplay();
	// void chooseImage();
	boolean isAnimationRunning();
	void processCustomMessage(String charsAsString);


	void chooseAnimation();
	void updateTotalFrames();

	String getValueFromDelimitedString(String stringData, char separator, int index);
    char* getCharsFromString(String str);
	void endAnimation();
};

#endif // _TEXT_CONTROLLER_H_
