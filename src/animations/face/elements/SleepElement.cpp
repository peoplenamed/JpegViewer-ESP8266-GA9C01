/*********************
 *      INCLUDES
 *********************/
#include "SleepElement.h"

/*********************
 *      DEFINES
 *********************/
void SleepElement::render(int x, int y)
{
	gfx->setCursor(x, y);
	gfx->setTextSize(2);
	gfx->setTextColor(WHITE);
	gfx->println(F("z"));
}

// FIX ME
// void SleepElement::getPixels(Pixel*& pixelBuffer, int type, uint16_t foreground, uint16_t background)
// {
//     const unsigned char* bitmapImage;
//     Pixel* pixelBuffer = new Pixel[xMax * yMax];  // Assuming all images are xMax by yMax

//     switch(type)
//     {
//     case SLEEP_CLOSED:
//         bitmapImage = sleep_closed;
//         break;
//     case SLEEP_OPEN:
//         bitmapImage = sleep_open;
//         break;
//     // Add more cases as needed...
//     default:
//         bitmapImage = sleep_closed;
//         break;
//     }

//     for (int i = 0; i < xMax * yMax; i++) {
//         pixelBuffer[i].x = x + i % xMax;
//         pixelBuffer[i].y = y + i / xMax;
//         pixelBuffer[i].color = bitmapImage[i] ? foreground : background;
//     }

//     return pixelBuffer;
// }