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
}

void* JpegFunk::jpegOpenFile(const char* szFilename, int32_t* pFileSize)
{
	#ifdef DEBUG
		Log.info("jpegOpenFile: %s\n");
		Log.info(szFilename);
	#endif
	LittleFS.begin();
	_f = LittleFS.open(szFilename, "r");
	*pFileSize = _f.size();

	#ifdef DEBUG
		Log.info("JPEG file size: %i\n"), _f.size();
	#endif
	return &_f;
}

void JpegFunk::jpegCloseFile(void* pHandle)
{
	#ifdef DEBUG
		Log.info("jpegCloseFile\n");
	#endif
	File* f = static_cast<File*>(pHandle);
	f->close();
}

int32_t JpegFunk::jpegReadFile(JPEGFILE* pFile, uint8_t* pBuf, int32_t iLen)
{
	#ifdef DEBUG
		Log.info("jpegReadFile, iLen: %d\n", iLen);
	#endif
	File* f = static_cast<File*>(pFile->fHandle);
	size_t r = f->read(pBuf, iLen);
	return r;
}

int32_t JpegFunk::jpegSeekFile(JPEGFILE* pFile, int32_t iPosition)
{
#ifdef DEBUG
	Log.info("jpegSeekFile, pFile->iPos: %d, iPosition: %d\n", pFile->iPos, iPosition);
#endif

	File* f = static_cast<File*>(pFile->fHandle);
	f->seek(iPosition);
	return iPosition;
}

void JpegFunk::jpegDraw(const char* filename,
						JPEG_DRAW_CALLBACK* jpegDrawCallback,
						bool useBigEndian,
						int x,
						int y,
						int widthLimit,
						int heightLimit)
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

	if(ratio <= 1)
	{
		_scale = 0;
		iMaxMCUs = widthLimit / 16;
	}
	else if(ratio <= 2)
	{
		_scale = JPEG_SCALE_HALF;
		iMaxMCUs = widthLimit / 8;
	}
	else if(ratio <= 4)
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
		debugJpeg(filename, useBigEndian, x, y, _x, _y, widthLimit, heightLimit, _scale, iMaxMCUs, ratio);
	#endif

	_jpeg.setMaxOutputSize(iMaxMCUs);

	if(useBigEndian)
	{
		_jpeg.setPixelType(RGB565_BIG_ENDIAN);
	}

	_jpeg.decode(x, y, _scale);
	_jpeg.close();
}

void JpegFunk::debugJpeg(const char* filename,
						 bool useBigEndian,
						 int x,
						 int y,
						 int _x,
						 int _y,
						 int widthLimit,
						 int heightLimit,
						 int _scale,
						 int iMaxMCUs,
						 float ratio)
{
	Log.info("[JpegFunkService]<debugJpeg> filename: %s, useBigEndian: %b, x: %i, y: %i, _x: %i, _y: %i, _x_bound: %i, _y_bound: %i, widthLimit: %i, heightLimit: %i, _scale: %i, ratio: %f, iMaxMCUs: %i\n", filename, useBigEndian, x, y, _x, _y, _x_bound,_y_bound, widthLimit, heightLimit, _scale, ratio, iMaxMCUs);
}
