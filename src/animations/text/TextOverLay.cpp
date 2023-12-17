/*********************
 *      INCLUDES
 *********************/
#include "TextOverLay.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
TextOverLay::TextOverLay() { }

void TextOverLay::renderFrame(int textType,
							  char* _text,
							  boolean _wipe,
							  uint16_t textColor,
							  uint16_t backgroundColor) {

    displayService.wipeScreen(_wipe, backgroundColor);

	switch(textType)
	{
		case 1:
            // northText
            displayService.drawText(_text, 85, 10, 3, textColor);
			break;
		case 2:
            // southText
            displayService.drawText(_text, 85, 200, 3, textColor);
			break;
		case 3:
            // eastText
            displayService.drawText(_text, 0, 110, 3, textColor);
			break;
		case 4:
            // westText
            displayService.drawText(_text, 185, 110, 3, textColor);
			break;
		case 5:
            // centerText
            displayService.drawText(_text, 85, 110, 3, textColor);
			break;
		case 8:
            // userDefinedText
            displayService.drawText(_text, x, y, size, color);
			break;
		default:
			break;
	}
}

void TextOverLay::setCustomSettings(int _x, int _y, int _size, uint16_t _color) {
	x = _x;
	y = _y;
	size = _size;
	color = _color;
}

int TextOverLay::getTotalFrames() {
	return frames;
}
