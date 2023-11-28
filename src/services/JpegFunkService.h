/*******************************************************************************
 * JPEGDEC related function
 *
 * Dependent libraries:
 * JPEGDEC: https://github.com/bitbank2/JPEGDEC.git
 ******************************************************************************/

#define USE_LittleFS

#ifndef _JPEGFUNK_SERVICE_H_
#define _JPEGFUNK_SERVICE_H_

/*********************
 *      INCLUDES
 *********************/
#include "../../config.h"
#include <JPEGDEC.h>

#ifdef ESP8826
#include <LittleFS.h>
#endif

#ifdef ESP32
#include <FS.h>
#ifdef USE_LittleFS
#define SPIFFS LITTLEFS
#include <LITTLEFS.h>
#else
#include <SPIFFS.h>
#endif
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *      CLASS
 **********************/
class JpegFunk
{
public:
    JpegFunk();
    static int _height;
    static int _width;
    static JPEGDEC _jpeg;
    static File _f;
    static int _x, _y, _x_bound, _y_bound;
    //      static File *jpegOpenFile(const char *szFilename, int32_t *pFileSize);
    static void *jpegOpenFile(const char *szFilename, int32_t *pFileSize);
    static void jpegCloseFile(void *pHandle);
    static int32_t jpegReadFile(JPEGFILE *pFile, uint8_t *pBuf, int32_t iLen);
    static int32_t jpegSeekFile(JPEGFILE *pFile, int32_t iPosition);
    static void jpegDraw(const char *filename, JPEG_DRAW_CALLBACK *jpegDrawCallback, bool useBigEndian, int x, int y, int widthLimit, int heightLimit);
    static void debugJpeg(const char *filename, bool useBigEndian, int x, int y, int _x, int _y, int widthLimit, int heightLimit, int _scale, int iMaxMCUs, float ratio);
};

#endif // _JPEGFUNK_SERVICE_H_
