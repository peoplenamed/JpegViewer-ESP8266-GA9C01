/*******************************************************************************
 * JPEGDEC related function
 *
 * Dependent libraries:
 * JPEGDEC: https://github.com/bitbank2/JPEGDEC.git
 ******************************************************************************/
#ifndef _JPEGFUNC_H_
#define _JPEGFUNC_H_
#include <JPEGDEC.h>
#include <Arduino_GFX_Library.h>

#define USE_LittleFS
//#define DEBUG


#ifdef ESP8826
  #include <LittleFS.h>
  #define TFT_CS D8
  #define TFT_DC D2
  #define TFT_RST D4
  #define TFT_MISO -1  // no data coming back
  Arduino_DataBus *bus = new Arduino_ESP8266SPI(TFT_DC /* DC */, TFT_CS /* CS */);
  Arduino_GFX *gfx = new Arduino_GC9A01(bus, TFT_RST /* RST */, 0 /* rotation */, true /* IPS */);
#endif

#ifdef ESP32
  #include <FS.h>
  #ifdef USE_LittleFS
    #define SPIFFS LITTLEFS
    #include <LITTLEFS.h> 
  #else
    #include <SPIFFS.h>
  #endif 

  #define TFT_CS 22
  #define TFT_DC 16
  #define TFT_RST 4
  #define TFT_MISO -1  // no data coming back

  Arduino_DataBus *bus = new Arduino_ESP32SPI(TFT_DC, TFT_CS);
  Arduino_GFX *gfx = new Arduino_GC9A01(bus, TFT_RST, 0 /* rotation */, true /* IPS */);
#endif

int _height = 240;
int _width = 240;
static JPEGDEC _jpeg;
static File _f;
static int _x, _y, _x_bound, _y_bound;
//Arduino_GFX *gfx;

static void *jpegOpenFile(const char *szFilename, int32_t *pFileSize)
{
  #ifdef DEBUG
      Serial.print("jpegOpenFile: ");
      Serial.println(szFilename);
  #endif
  #ifdef ESP8826
    _f = LittleFS.open(szFilename, "r");
  #endif
  #ifdef ESP32
    #ifdef USE_LittleFS
      _f = LITTLEFS.open(szFilename, "r");
    #else
      _f = SPIFFS.open(szFilename, "r");
    #endif
  #endif
  *pFileSize = _f.size();
  
  #ifdef DEBUG
    Serial.print("JPEG file size: ");
    Serial.println(_f.size());
  #endif
  return &_f;
}

static void jpegCloseFile(void *pHandle)
{
  #ifdef DEBUG
    Serial.println("jpegCloseFile");
  #endif
  File *f = static_cast<File *>(pHandle);
  f->close();
}

static int32_t jpegReadFile(JPEGFILE *pFile, uint8_t *pBuf, int32_t iLen)
{
  #ifdef DEBUG
    Serial.printf("jpegReadFile, iLen: %d\n", iLen);
  #endif
  File *f = static_cast<File *>(pFile->fHandle);
  size_t r = f->read(pBuf, iLen);
  return r;
}

static int32_t jpegSeekFile(JPEGFILE *pFile, int32_t iPosition)
{
  #ifdef DEBUG
    Serial.printf("jpegSeekFile, pFile->iPos: %d, iPosition: %d\n", pFile->iPos, iPosition);
  #endif

  File *f = static_cast<File *>(pFile->fHandle);
  f->seek(iPosition);
  return iPosition;
}

static void jpegDraw(
    const char *filename, JPEG_DRAW_CALLBACK *jpegDrawCallback, bool useBigEndian,
    int x, int y, int widthLimit, int heightLimit)
{
  _x = x;
  _y = y;
  _x_bound = _x + widthLimit - 1;
  _y_bound = _y + heightLimit - 1;

  _jpeg.open(filename, jpegOpenFile, jpegCloseFile, jpegReadFile, jpegSeekFile, jpegDrawCallback);

  // scale to fit height
  int _scale;
  int iMaxMCUs;
  float ratio = (float)_jpeg.getHeight() / heightLimit;
    
  if (ratio <= 1)
  {
    _scale = 0;
    iMaxMCUs = widthLimit / 16;
  }
  else if (ratio <= 2)
  {
    _scale = JPEG_SCALE_HALF;
    iMaxMCUs = widthLimit / 8;
  }
  else if (ratio <= 4)
  {
    _scale = JPEG_SCALE_QUARTER;
    iMaxMCUs = widthLimit / 4;
  }
  else
  {
    _scale = JPEG_SCALE_EIGHTH;
    iMaxMCUs = widthLimit / 2;
  }
  #ifdef DEBUG
    debugJpeg(*filename, useBigEndian,x, y, _x, _y, widthLimit,
      heightLimit, _scale, iMaxMCUs, ratio)
  #endif

  _jpeg.setMaxOutputSize(iMaxMCUs);

  if (useBigEndian)
  {
    _jpeg.setPixelType(RGB565_BIG_ENDIAN);
  }

  _jpeg.decode(x, y, _scale);
  _jpeg.close();
}

void debugJpeg(
    const char *filename, bool useBigEndian,
    int x, int y, int _x, int _y, int widthLimit, int heightLimit,
    int _scale, int iMaxMCUs, float ratio) {
    Serial.print("== filename: ");
    Serial.println(filename);
    Serial.print("== *filename: ");
    Serial.println(*filename);
    Serial.print("== useBigEndian: ");
    Serial.println(useBigEndian);
    Serial.print("== x: ");
    Serial.println(x);
    Serial.print("== y: ");
    Serial.println(y);
    Serial.print("== _x: ");
    Serial.println(_x);
    Serial.print("== _y: ");
    Serial.println(_y);
    Serial.print("== _x_bound: ");
    Serial.println(_x_bound);
    Serial.print("== _y_bound: ");
    Serial.println(_y_bound);
    Serial.print("== widthLimit: ");
    Serial.println(widthLimit);
    Serial.print("== heightLimit: ");
    Serial.println(heightLimit);
    Serial.print("== _scale: ");
    Serial.println(_scale);
    Serial.print("== ratio: ");
    Serial.println(ratio);
    Serial.print("== iMaxMCUs: ");
    Serial.println(iMaxMCUs);
}


static int jpegDrawCallback(JPEGDRAW *pDraw) {
  #ifdef DEBUG
    Serial.printf("Draw pos = %d,%d. size = %d x %d\n", pDraw->x, pDraw->y, pDraw->iWidth, pDraw->iHeight);
  #endif
  gfx->draw16bitBeRGBBitmap(pDraw->x, pDraw->y, pDraw->pPixels, pDraw->iWidth, pDraw->iHeight);
  return 1;
}

void drawImage(char* fileName) {
  #ifdef DEBUG
    Serial.print("Drawing ");
    Serial.println(fileName);
  #endif
//  int _width = gfx->width();
//  int _height = gfx->height();

  jpegDraw(fileName, jpegDrawCallback, true /* useBigEndian */, 0, 0, _width /* widthLimit */, _height /* heightLimit */);
}

#endif // _JPEGFUNC_H_
