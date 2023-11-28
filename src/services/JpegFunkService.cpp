/*********************
 *      INCLUDES
 *********************/
#include "JpegFunkService.h"

/*********************
 *      DEFINES
 *********************/
int JpegFunk::_height = 240;
int JpegFunk::_width = 240;
JPEGDEC JpegFunk::_jpeg;
File JpegFunk::_f;
int JpegFunk::_x;
int JpegFunk::_y;
int JpegFunk::_x_bound;
int JpegFunk::_y_bound;

/**********************
 *      CLASS
 **********************/
JpegFunk::JpegFunk()
{
    Log.info("JpegFunk initializer" CR);
#ifdef ESP32
#ifdef USE_LittleFS
    if (!LITTLEFS.begin(true))
    {
        Serial.println("An Error has occurred while mounting LITTLEFS");
        return;
    }
#else
    if (!SPIFFS.begin(true))
    {
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }
#endif
#endif

#ifdef ESP8826
    if (!LittleFS.begin())
    {
        Serial.println(F("ERROR: File System Mount Failed!"));
        gfx->println(F("ERROR: File System Mount Failed!"));
        // gfx->setRotation(uint8_t rotation);
    }
#endif
}

void *JpegFunk::jpegOpenFile(const char *szFilename, int32_t *pFileSize)
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

void JpegFunk::jpegCloseFile(void *pHandle)
{
#ifdef DEBUG
    Serial.println("jpegCloseFile");
#endif
    File *f = static_cast<File *>(pHandle);
    f->close();
}

int32_t JpegFunk::jpegReadFile(JPEGFILE *pFile, uint8_t *pBuf, int32_t iLen)
{
#ifdef DEBUG
    Serial.printf("jpegReadFile, iLen: %d\n", iLen);
#endif
    File *f = static_cast<File *>(pFile->fHandle);
    size_t r = f->read(pBuf, iLen);
    return r;
}

int32_t JpegFunk::jpegSeekFile(JPEGFILE *pFile, int32_t iPosition)
{
#ifdef DEBUG
    Serial.printf("jpegSeekFile, pFile->iPos: %d, iPosition: %d\n", pFile->iPos, iPosition);
#endif

    File *f = static_cast<File *>(pFile->fHandle);
    f->seek(iPosition);
    return iPosition;
}

void JpegFunk::jpegDraw(
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
    debugJpeg(filename, useBigEndian, x, y, _x, _y, widthLimit,
              heightLimit, _scale, iMaxMCUs, ratio);
#endif

    _jpeg.setMaxOutputSize(iMaxMCUs);

    if (useBigEndian)
    {
        _jpeg.setPixelType(RGB565_BIG_ENDIAN);
    }

    _jpeg.decode(x, y, _scale);
    _jpeg.close();
}

void JpegFunk::debugJpeg(
    const char *filename, bool useBigEndian,
    int x, int y, int _x, int _y, int widthLimit, int heightLimit,
    int _scale, int iMaxMCUs, float ratio)
{
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
