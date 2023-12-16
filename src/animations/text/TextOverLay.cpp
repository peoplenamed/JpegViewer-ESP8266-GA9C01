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
							  uint16_t backgroundColor=NULL) {

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
		case 6:
            // errorText
            displayService.drawText(_text, 0, 105, 4, 3);
			break;
		case 7:
            // successText
            displayService.drawText(_text, 0, 105, 5, 4);
			break;
		case 8:
            // FIX ME!
            // userDefinedText
            // displayService.drawText(_text, _x, _y, _size, _color);
			break;
		default:
			break;
	}
}