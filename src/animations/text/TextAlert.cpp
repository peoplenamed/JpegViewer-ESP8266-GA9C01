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
							uint16_t backgroundColor=NULL) {
	displayService.wipeScreen(_wipe, backgroundColor);

	switch(textType)
	{
		case 1:
            // errorText
            displayService.drawText(_text, 0, 105, 4, 3);
			break;
		case 2:
            // successText
            displayService.drawText(_text, 0, 105, 5, 4);
			break;
		default:
			break;
	}
}