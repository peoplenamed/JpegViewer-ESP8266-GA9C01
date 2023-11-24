/*******************************************************************************
 *     upload LittleFS data with ESP8266 LittleFS Data Upload:
 *     ESP32: https://github.com/lorol/arduino-esp32fs-plugin
 *     Ada was here
 *     MOM AND FAMILY ARE THE BEST!**************!!!!!!!!!!!!!!!!!
 *     https://thesolaruniverse.wordpress.com/2022/11/01/an-internet-synced-clock-circular-display-with-gc9a01-controller-powered-by-an-esp8266/
 ******************************************************************************/
#include "JpegFunc.h"
#include "colorStruct.h"
#include <Arduino_GFX_Library.h>
#define GFX_BL 5 // default backlight pin
#include <LittleFS.h>
//#define DEBUG

#ifdef DEBUG
  // List everything in LittleFS Storage
  #include "List_LittleFS.h"
#endif

#ifdef ESP8266
  // ESP8266 definitions
  Arduino_DataBus *bus = new Arduino_ESP8266SPI(D2 /* DC */, D8 /* CS */);
  Arduino_GFX *gfx = new Arduino_GC9A01(bus, 0 /* RST */, 0 /* rotation */, true /* IPS */);
#endif

#ifdef ESP32
  // ESP32 definitions
  Arduino_DataBus *bus = new Arduino_ESP8266SPI(D2 /* DC */, D8 /* CS */);
  Arduino_GFX *gfx = new Arduino_GC9A01(bus, 0 /* RST */, 0 /* rotation */, true /* IPS */);
#endif


String userInput;
const byte numChars = 32;
char receivedChars[numChars];
boolean newData = false;
int _height = 240;
int _width = 240;

void setup() {
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
    // void setRotation(uint8_t rotation);
  } else {
    splashScreen();
  }
}

void loop()
{
  #ifdef DEBUG
    listLittleFS();
  #endif
  while (!Serial.available()); 

  recvWithStartEndMarkers();
  showNewData();

  loop(); // I have no idea why I have to call this...
}

void recvWithStartEndMarkers() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char startMarker = '<';
  char endMarker = '>';
  char rc;

  while (Serial.available() > 0 && newData == false) {
    rc = Serial.read();

    if (recvInProgress == true) {
      if (rc != endMarker) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars) {
            ndx = numChars - 1;
        }
      }
      else {
        receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        newData = true;
      }
    }

    else if (rc == startMarker) {
      recvInProgress = true;
    }
  }
}

void showNewData() {
  if (newData == true) {
    runCommand();
    newData = false;
  }
}

void runCommand() {
  char firstChar = receivedChars[0];
  if (isDigit(firstChar)) {
    chooseImage(atoi(receivedChars));
  } else {
    processCustomMessage();
  }
}

void processCustomMessage() {
  // Example Messages
  //   <Howdy friend|0|110|3|3|1>
  //   <75%|20|140|3|3|0>
  String charsAsString = receivedChars;
  String _text = getValueFromDelimitedString(charsAsString, '|', 0);
  String _x = getValueFromDelimitedString(charsAsString, '|', 1);
  String _y = getValueFromDelimitedString(charsAsString, '|', 2);
  String _size = getValueFromDelimitedString(charsAsString, '|', 3);
  String _color = getValueFromDelimitedString(charsAsString, '|', 4);
  String _wipe = getValueFromDelimitedString(charsAsString, '|', 5);
  #ifdef DEBUG
    Serial.print("  _text = ");
    Serial.println(_text);
    Serial.print("  _x = ");
    Serial.println(_x);
    Serial.print("  _y = ");
    Serial.println(_y);
    Serial.print("  _size = ");
    Serial.println(_size);
    Serial.print("  _color = ");
    Serial.println(_color);
    Serial.print("  _wipe = ");
    Serial.println(_wipe);
  #endif
  
  if (_wipe == "1") {
    wipeScreen(true);
  }
  
  drawText(_text, _x.toInt(), _y.toInt(), _size.toInt(), _color.toInt());
}

String getValueFromDelimitedString(String stringData, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = stringData.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(stringData.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? stringData.substring(strIndex[0], strIndex[1]) : "";
}

void chooseImage(int imageSelect)
{
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
    case 30:
      drawRimCircle(120, false, 10);
      break;
    case 31:
      northText("North");
      southText("South");
      eastText("East");
      westText("West");
      centerText("100%");
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
void normalFace() { drawImage("normal_face.jpg"); }
void satisfiedFace() {
  normalFace();
  delay(400);
  drawImage("satisfied_face.jpg");
  delay(400);
  normalFace();
}

void splashScreen() {
  grumpyFace();
  delay(500);
  satisfiedFace();
}

void drawJpgAnimation(String name, String fileType, int frames, int times)
{
  for (int x=1; x <= times; x++)
  {
    for (int i=0; i <= frames-1; i++)
    {
      String filename = "";
      filename.concat(name);
  
      if (i < 10)
      {
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


void setText(String text) {
  int len = text.length() + 1;
  char charArray[len];
  text.toCharArray(charArray, len);

  gfx->println(charArray);
}

void drawText(String _text, int _x, int _y, int _size, int _color) {
  gfx->setCursor(_x, _y);
  gfx->setTextColor(getHexColor(_color));
  gfx->setTextSize(_size);
  setText(_text);
}

const int compassTextColor = 7;

void northText(String _text)
{
  drawText(_text, 85, 10, 3, compassTextColor);
}

void southText(String _text)
{
  drawText(_text, 85, 200, 3, compassTextColor);
}

void eastText(String _text)
{
  drawText(_text, 0, 110, 3, compassTextColor);
}

void westText(String _text)
{
  drawText(_text, 185, 110, 3, compassTextColor);
}

void centerText(String _text)
{
  drawText(_text, 85, 110, 3, compassTextColor);
}

void errorText(String _text)
{
  drawText(_text, 0, 105, 4, 3);
}

void successText(String _text)
{
  drawText(_text, 0, 105, 5, 4);
}

void userDefinedText(String _text, int _x, int _y, int _size, int _color)
{
    drawText(_text, _x, _y, _size, _color);
}

void drawRimCircle(int radius, boolean wipe, int maxWipe)
{
  wipeScreen(wipe);

  int _x = 120;  // radius/2
  int _y = 120;  // radius/2

  for (int y = 0; y < maxWipe; y++) {
    gfx->drawCircle(_x, _y, radius-y, getRandomColor());
  }
}

void circleWipe(int radius, boolean wipe)
{
  wipeScreen(wipe);
  int32_t w = _width;
  int32_t h = _height;
  uint32_t start;
  int32_t x, y;
  int32_t r2 = radius * 2;
  int32_t w1 = w + radius;
  int32_t h1 = h + radius;

  for (x = 0; x < w1; x += r2)
  {
    for (y = 0; y < h1; y += r2)
    {
      gfx->drawCircle(x, y, radius, getRandomColor());
    }
  }
}

void wipeScreen(boolean wipe)
{
  if (wipe) {
    gfx->fillScreen(BLACK);
  }
}

void triangleWipe(boolean wipe) {
  wipeScreen(wipe);
  int32_t i;
  int32_t cx = _width / 2;
  int32_t cy = _height / 2;
  int32_t cx1 = cx - 1;
  int32_t cy1 = cy - 1;
  int32_t cn = min(cx1, cy1);                                                 // digit size

  for (i = 0; i < cn; i += 5) {
    gfx->drawTriangle(
        cx1, cy1 - i,     // peak
        cx1 - i, cy1 + i, // bottom left
        cx1 + i, cy1 + i, // bottom right
        gfx->color565(0, 0, i));
  }
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

static int jpegDrawCallback(JPEGDRAW *pDraw) {
  #ifdef DEBUG
    Serial.printf("Draw pos = %d,%d. size = %d x %d\n", pDraw->x, pDraw->y, pDraw->iWidth, pDraw->iHeight);
  #endif
  gfx->draw16bitBeRGBBitmap(pDraw->x, pDraw->y, pDraw->pPixels, pDraw->iWidth, pDraw->iHeight);
  return 1;
}
