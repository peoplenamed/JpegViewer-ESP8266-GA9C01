#include "DrawingService.h"

DrawingService::DrawingService() {
}

// Draw the image from the frame buffer
void DrawingService::drawImageFromBuffer() {
  for (int y = 0; y < _SCREEN_HEIGHT; y++) {
    for (int x = 0; x < _SCREEN_WIDTH; x++) {
      uint16_t color = frameBuffer[y][x];
      gfx->drawPixel(x, y, color);
    }
  }
}

// Draw the image from external frame buffer
void DrawingService::drawImageFromExternalBuffer(Pixel* externalBuffer) {
  for (int y = 0; y < _SCREEN_HEIGHT; y++) {
    for (int x = 0; x < _SCREEN_WIDTH; x++) {
      int i = y * _SCREEN_WIDTH + x;
      uint16_t color = externalBuffer[i].color;
      gfx->drawPixel(x, y, color);
    }
  }
}

// Function to set multiple pixels in the frame buffer
void DrawingService::setPixels(Pixel* pixels, size_t count) {
  for (size_t i = 0; i < count; i++) {
    setPixel(pixels[i].x, pixels[i].y, pixels[i].color);
  }
}

// Function to set a pixel in the frame buffer
void DrawingService::setPixel(int x, int y, uint16_t color) {
  if (x >= 0 && x < _SCREEN_WIDTH && y >= 0 && y < _SCREEN_HEIGHT) {
    frameBuffer[y][x] = color;
  }
}

// Function to get a pixel from the frame buffer
uint16_t DrawingService::getPixel(int x, int y) {
  if (x >= 0 && x < _SCREEN_WIDTH && y >= 0 && y < _SCREEN_HEIGHT) {
    return frameBuffer[y][x];
  } else {
    return 0;  // Return black for out-of-bounds coordinates
  }
}