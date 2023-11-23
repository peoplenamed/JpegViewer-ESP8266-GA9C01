/*******************************************************************************
 * JPEGDEC related function
 *
 * Dependent libraries:
 * JPEGDEC: https://github.com/bitbank2/JPEGDEC.git
 ******************************************************************************/
#ifndef _JPEGFUNC_H_
#define _JPEGFUNC_H_
//#define DEBUG
#include <JPEGDEC.h>
#include <LittleFS.h>

static JPEGDEC _jpeg;
static File _f;
static int _x, _y, _x_bound, _y_bound;

static void *jpegOpenFile(const char *szFilename, int32_t *pFileSize)
{
    #ifdef DEBUG
        Serial.println("jpegOpenFile");
    #endif
    _f = LittleFS.open(szFilename, "r");
    *pFileSize = _f.size();
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
        Serial.printf("== filename: %d\n", filename);
        Serial.printf("== *filename: %d\n", *filename);
        Serial.printf("== useBigEndian: %d\n", useBigEndian);
        Serial.printf("== x: %d\n", x);
        Serial.printf("== y: %d\n", y);
        Serial.printf("== _x: %d\n", _x);
        Serial.printf("== _y: %d\n", _y);
        Serial.printf("== _x_bound: %d\n", _x_bound);
        Serial.printf("== _y_bound: %d\n", _y_bound);
        Serial.printf("== widthLimit: %d\n", widthLimit);
        Serial.printf("== heightLimit: %d\n", heightLimit);
        Serial.printf("== _scale: %d\n", _scale);
        Serial.printf("== ratio: %d\n", ratio);
        Serial.printf("== _scale: %d\n", _scale);
        Serial.printf("== iMaxMCUs: %d\n", iMaxMCUs);
    #endif

    _jpeg.setMaxOutputSize(iMaxMCUs);

    if (useBigEndian)
    {
        _jpeg.setPixelType(RGB565_BIG_ENDIAN);
    }

    _jpeg.decode(x, y, _scale);
    _jpeg.close();
}

#endif // _JPEGFUNC_H_
