/*******************************************************************************
 *     upload LittleFS data with ESP8266 LittleFS Data Upload:
 *     ESP32: https://github.com/lorol/arduino-esp32fs-plugin
 *     Ada was here
 *     MOM AND FAMILY ARE THE BEST!**************!!!!!!!!!!!!!!!!!
 ******************************************************************************/
#include "JpegFunc.h"
#include <Arduino_GFX_Library.h>
#define GFX_BL 5 // default backlight pin
#include <LittleFS.h>
//#define DEBUG

#ifdef DEBUG
  // List everything in LittleFS Storage
  #include "List_LittleFS.h"
#endif

Arduino_DataBus *bus = new Arduino_ESP8266SPI(D2 /* DC */, D8 /* CS */);
Arduino_GFX *gfx = new Arduino_GC9A01(bus, 0 /* RST */, 0 /* rotation */, true /* IPS */);

int imageSelect = 1;
int _height = 240;
int _width = 240;

void setup()
{
  Serial.begin(115200);
  Serial.setTimeout(1);

  // Init Display
  if (!gfx->begin())
  {
    Serial.println("gfx->begin() failed!");
  } else {
    #ifdef DEBUG
      Serial.println("gfx->begin() initialized.");
    #endif
    wipeScreen(true);
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
  imageSelect = Serial.readString().toInt();

  runCommand();

  loop(); // I have no idea why I have to call this...
}

void runCommand() {
  switch (imageSelect) {
    case 0:
      octocat();
      break;
    case 1:
      calvinAndHobbes();
      break;
    case 2:
      grumpyFace();
      break;
    case 3:
      winkFace();
      break;
    case 4:
      disappointedFace();
      break;
    case 5:
      satisfiedFace();
      break;
    case 6:
      normalFace();
      break;
    case 20:
      circleWipe(10, false);
      break;
    case 21:
      circleWipe(10, true);
      break;
    case 22:
      triangleWipe(true);
      break;
    case 23:
      triangleWipe(false);
      break;
    default:
      calvinDuplicator();
      break;
  }
}

/** STATIC IMAGES **/
void calvinAndHobbes(){ drawImage("/download.jpeg"); }
void octocat(){ drawImage("/octocat.jpg"); }

/** ANIMATIONS **/
void calvinDuplicator() { drawJpgAnimation("1Ys_", ".jpg", 19, 3); }

/** FACES **/
void grumpyFace() { drawJpgAnimation("grumpy_face_0", ".jpg", 4, 20); }
void winkFace() { drawJpgAnimation("wink_face_", ".jpg", 5, 1); }
void disappointedFace() { drawJpgAnimation("disappointed_face_", ".jpg", 5, 1); }
void normalFace() { drawImage("normal_face"); }
void satisfiedFace() {
  normalFace();
  delay(400);
  drawImage("satisfied_face");
  delay(400);
  normalFace();
}

void drawJpgAnimation(String name, String fileType, int frames, int times) {
  for (int x=1; x <= times; x++) {
    for (int i=0; i <= frames-1; i++) {
      String filename = "";
      filename.concat(name);
  
      if (i < 10) {
        filename.concat("00");
      } else {
        filename.concat("0");
      }
      filename.concat(i);
      filename.concat(fileType);
  
      int len = filename.length() + 1; 
      char charArray[len];
      filename.toCharArray(charArray, len);
  
      drawImage(charArray);
    }
  }
}

void circleWipe(int radius, boolean wipe) {
  wipeScreen(wipe);
  int32_t w = _width;
  int32_t h = _height;
  uint32_t start;
  int32_t x, y;
  int32_t r2 = radius * 2;
  int32_t w1 = w + radius;
  int32_t h1 = h + radius;

  for (x = 0; x < w1; x += r2) {
    for (y = 0; y < h1; y += r2) {
      gfx->drawCircle(x, y, radius, WHITE);
    }
  }
}

void wipeScreen(boolean wipe) {
  if (wipe) {
    gfx->fillScreen(BLACK);
  }
}

void triangleWipe(boolean wipe) {
  wipeScreen(wipe);
  int32_t i;
//  int32_t n = min(w, h);
//  int32_t n1 = n - 1;
  int32_t cx = _width / 2;
  int32_t cy = _height / 2;
  int32_t cx1 = cx - 1;
  int32_t cy1 = cy - 1;
  int32_t cn = min(cx1, cy1);
//  int32_t cn1 = cn - 1;
//  int32_t tsa = ((w <= 176) || (h <= 160)) ? 1 : (((w <= 240) || (h <= 240)) ? 2 : 3); // text size A
//  int32_t tsb = ((w <= 272) || (h <= 220)) ? 1 : 2;                                    // text size B
//  int32_t tsc = ((w <= 220) || (h <= 220)) ? 1 : 2;                                    // text size C
//  int32_t ds = (w <= 160) ? 9 : 12;                                                    // digit size


  for (i = 0; i < cn; i += 5) {
    gfx->drawTriangle(
        cx1, cy1 - i,     // peak
        cx1 - i, cy1 + i, // bottom left
        cx1 + i, cy1 + i, // bottom right
        gfx->color565(0, 0, i));
  }
}

void setText(String text, int size=9) {
  int len = text.length() + 1;
  char charArray[len];
  text.toCharArray(charArray, len);

  gfx->setTextSize(size);
  gfx->setTextColor(BLUE);
  gfx->println(charArray);
}

void drawImage(char* fileName) {
  #ifdef DEBUG
    Serial.print("Drawing ");
    Serial.println(fileName);
  #endif
//  int _width = gfx->width();
//  int _height = gfx->height();

  jpegDraw(fileName, jpegDrawCallback, true /* useBigEndian */, 0, 0, _width /* widthLimit */, _height /* heightLimit */);
  //setText("Hello Mars!", 3);
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
