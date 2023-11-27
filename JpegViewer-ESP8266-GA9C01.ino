/*******************************************************************************
 *     upload LittleFS data with ESP8266 LittleFS Data Upload:
 *     ESP32: https://github.com/lorol/arduino-esp32fs-plugin
 *     Ada was here
 *     MOM AND FAMILY ARE THE BEST!**************!!!!!!!!!!!!!!!!!
 *     https://thesolaruniverse.wordpress.com/2022/11/01/an-internet-synced-clock-circular-display-with-gc9a01-controller-powered-by-an-esp8266/
 ******************************************************************************/
#include "Arduino.h"
#include "config.h"
#include "src/controllers/SerialManagerController.h"
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

#ifdef DEBUG
#ifdef USE_LittleFS
    //      listLittleFS(); // Not working atm...
#endif
#endif

    serialManager.setupDisplay();
    serialManager.splashScreen();
}

void loop()
{
    while (!Serial.available())
        ;

    serialManager.processSerialCommands();
}
