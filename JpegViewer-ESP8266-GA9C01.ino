/*******************************************************************************
 *     upload LittleFS data with ESP8266 LittleFS Data Upload:
 *     ESP32: https://github.com/lorol/arduino-esp32fs-plugin
 *     Ada was here
 ******************************************************************************/
#include "JpegFunc.h"
#include <Arduino_GFX_Library.h>
#define GFX_BL 5 // default backlight pin
#include <LittleFS.h>
#define DEBUG false

#ifdef DEBUG
  // List everything in LittleFS Storage
  #include "List_LittleFS.h"
#endif

Arduino_DataBus *bus = new Arduino_ESP8266SPI(D2 /* DC */, D8 /* CS */);
Arduino_GFX *gfx = new Arduino_GC9A01(bus, 0 /* RST */, 0 /* rotation */, true /* IPS */);



int imageSelect = 1;

void setup()
{
  Serial.begin(115200);
  Serial.setTimeout(1);

  // Init Display
  if (!gfx->begin())
  {
    Serial.println("gfx->begin() failed!");
  } else {
    Serial.println("gfx->begin() initialized.");
    gfx->fillScreen(BLACK);
  }
  if (!LittleFS.begin())
  {
    Serial.println(F("ERROR: File System Mount Failed!"));
    gfx->println(F("ERROR: File System Mount Failed!"));
  }
}

void loop()
{
  #ifdef DEBUG
    listLittleFS();
  #endif
  while (!Serial.available()); 
  x = Serial.readString().toInt();

  runCommand();

  loop(); // I have no idea why I have to call this...
}

void runCommand() {
  switch (imageSelect) {
    case 1:
      octocat();
      break;
    case 2:
      calvinAndHobbes();
      break;
    default:
      dance(1);
      break;
  }
}

void calvinAndHobbes(){ drawImage("/download.jpeg"); }
void octocat(){ drawImage("/octocat.jpg"); }

void dance(int times) {
  String name = "1Ys_";
  String jpg = ".jpg";
  for (int x=1; x <= times; x++) {
    for (int i=0; i <= 19; i++) {
      String filename = "";
      filename.concat(name);
  
      if (i < 10) {
        filename.concat("00");
      } else {
        filename.concat("0");
      }
      filename.concat(i);
      filename.concat(jpg);
      int len = filename.length() + 1; 
  
      char charArray[len];
      filename.toCharArray(charArray, len);
  
      drawImage(charArray);
    }
  }
}

void drawImage(char fileName[]) {
  #ifdef DEBUG
    Serial.print("Drawing ");
    Serial.println(fileName);
  #endif
//  int _width = gfx->width();
//  int _height = gfx->height();
  int _width = 240;
  int _height = 240;

  jpegDraw(fileName, jpegDrawCallback, true /* useBigEndian */, 0, 0, _width /* widthLimit */, _height /* heightLimit */);
}

// pixel drawing callback
static int jpegDrawCallback(JPEGDRAW *pDraw)
{
  #ifdef DEBUG
    Serial.printf("Draw pos = %d,%d. size = %d x %d\n", pDraw->x, pDraw->y, pDraw->iWidth, pDraw->iHeight);
  #endif
  gfx->draw16bitBeRGBBitmap(pDraw->x, pDraw->y, pDraw->pPixels, pDraw->iWidth, pDraw->iHeight);
  return 1;
}
