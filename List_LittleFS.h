/***************************************************************************************
** Function name:           listLittleFS
** Description:             Listing LittleFS files
***************************************************************************************/
//#define USE_LittleFS
#include "Arduino.h"
#ifdef ESP8266
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


void listLittleFS(void) {
  Serial.println(F("\r\nListing LittleFS files:"));
  static const char line[] PROGMEM =  "=================================================";

  Serial.println(FPSTR(line));
  Serial.println(F("  File name                              Size"));
  Serial.println(FPSTR(line));

  fs::File root;

  #ifdef ESP32
    Serial.println("OPTION 1 <--");
    root = LITTLEFS.open("/", "r");
    Serial.print("root open");
    Serial.println("--");
    Serial.println(root);
  #endif
  #ifdef ESP8826
    Serial.println("OPTION 2 <--");
    root = LittleFS.open("/", "r");
  #endif

    Serial.println("OPTION 1a <--");
  if (!root) {
    Serial.println(F("Failed to open directory"));
    return;
  }

    Serial.println("OPTION 1b <--");
  if (!root.isDirectory()) {
    Serial.println(F("Not a directory"));
    return;
  }

    Serial.println("OPTION 1v <--");
  fs::File file = root.openNextFile();
  while (file) {

    Serial.println("OPTION 1d <--");
    if (file.isDirectory()) {
      Serial.print("DIR : ");
      String fileName = file.name();
      Serial.print(fileName);
    } else {
      String fileName = file.name();
      Serial.print("  " + fileName);
      // File path can be 31 characters maximum in LittleFS
      int spaces = 33 - fileName.length(); // Tabulate nicely
      if (spaces < 1) spaces = 1;
      while (spaces--) Serial.print(" ");
      String fileSize = (String) file.size();
      spaces = 10 - fileSize.length(); // Tabulate nicely
      if (spaces < 1) spaces = 1;
      while (spaces--) Serial.print(" ");
      Serial.println(fileSize + " bytes");
    }

    file = root.openNextFile();
  }

  Serial.println(FPSTR(line));
  Serial.println();
  delay(1000);
}
