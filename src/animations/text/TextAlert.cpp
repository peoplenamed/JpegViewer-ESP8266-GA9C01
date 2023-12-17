/*********************
 *      INCLUDES
 *********************/
#include "TextAlert.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
TextAlert::TextAlert() { }

// Setting background color will wipe screen
void TextAlert::renderFrame(int textType,
						    char* _text,
							boolean _wipe,
							uint16_t textColor,
							uint16_t backgroundColor)
{
	displayService.wipeScreen(_wipe, backgroundColor);

	switch(textType)
	{
		case 1:
            // errorText
			// String _text, int _x, int _y, int _size, int _color
            displayService.drawText(_text, _x, _y, _size, _errorColor);
			break;
		case 2:
            // successText
            displayService.drawText(_text, _x, _y, _size, _successColor);
			break;
		default:
			break;
	}
}

void TextAlert::setCustomSettings(int _x, int _y, int _size, uint16_t _color) {
	x = _x;
	y = _y;
	size = _size;
	color = _color;
}

int TextAlert::getTotalFrames() {
	return frames;
}
