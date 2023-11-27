#include <Arduino_GFX_Library.h>
//#include "colorStruct.h"
//#define DEBUG

//#define DEBUG
#include "JpegFunk.h"

#ifndef _DISPLAY_H_
#define _DISPLAY_H_
  class Display
  {
    public:
      Display();
      //  ~();

      void setupDisplay();
      void wipeScreen(boolean wipe);
      void setText(String text);
      void drawText(String _text, int _x, int _y, int _size, int _color);
      static int jpegDrawCallback(JPEGDRAW *pDraw);
      void drawImage(char* fileName);
      void DrawTriangle(int32_t peak, int32_t bottom_left, int32_t bottom_right, int32_t idk1, int32_t idk2, int32_t idk3, int32_t color);
      void DrawCircle(int32_t x, int32_t y, int32_t radius, int32_t color);
      void drawJpgAnimation(String name, String fileType, int frames, int times);

      static Arduino_DataBus *bus;
      static Arduino_GFX *gfx;
      static JpegFunk jpegFunk;
  };

#endif // _DISPLAY_H_
