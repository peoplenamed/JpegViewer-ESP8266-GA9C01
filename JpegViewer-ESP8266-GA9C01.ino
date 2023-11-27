/*******************************************************************************
 *     upload LittleFS data with ESP8266 LittleFS Data Upload:
 *     ESP32: https://github.com/lorol/arduino-esp32fs-plugin
 *     Ada was here
 *     MOM AND FAMILY ARE THE BEST!**************!!!!!!!!!!!!!!!!!
 *     https://thesolaruniverse.wordpress.com/2022/11/01/an-internet-synced-clock-circular-display-with-gc9a01-controller-powered-by-an-esp8266/
 ******************************************************************************/
#include "config.h"
#include "Arduino.h"
#include "SerialManager.h"

#define USE_LittleFS
#define DEBUG

#ifdef DEBUG
#ifdef USE_LittleFS
// List everything in LittleFS Storage
//    #include "List_LittleFS.h"
#endif
#endif

SerialManager serialManager;

void setup()
{
    Serial.begin(115200);
    Serial.setTimeout(1);
    //  serialManager = new SerialManager();

#ifdef DEBUG
#ifdef USE_LittleFS
    //      listLittleFS();
#endif
#endif
    Serial.println("serialManager call");

    serialManager.setupDisplay();
    serialManager.splashScreen();
}

void loop()
{
    while (!Serial.available())
        ;

    serialManager.processSerialCommands();

    // loop(); // I have no idea why I have to call this...
}
