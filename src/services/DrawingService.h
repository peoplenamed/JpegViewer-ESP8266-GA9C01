#ifndef _DRAWING_SERVICE_H_
#define _DRAWING_SERVICE_H_

#include "config.h"

class DrawingService {
    public:
        DrawingService();

        void setPixels(Pixel* pixels, size_t count);
        uint16_t getPixel(int x, int y);
        void drawImageFromExternalBuffer(Pixel* externalBuffer);
        void drawImageFromBuffer();
    private:
        void setPixel(int x, int y, uint16_t color);
        uint16_t frameBuffer[_SCREEN_HEIGHT][_SCREEN_WIDTH];

};

#endif // _DRAWING_SERVICE_H_
