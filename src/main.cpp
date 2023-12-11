/*******************************************************************************
 *     upload LittleFS data with ESP8266 LittleFS Data Upload:
 *     ESP32: https://github.com/lorol/arduino-esp32fs-plugin
 *     Ada was here
 *     MOM AND FAMILY ARE THE BEST!**************!!!!!!!!!!!!!!!!!
 *     https://thesolaruniverse.wordpress.com/2022/11/01/an-internet-synced-clock-circular-display-with-gc9a01-controller-powered-by-an-esp8266/
 ******************************************************************************/
/*********************
 *  GLOBAL INCLUDES
 *********************/
#include "config.h"
#include "controllers/SerialManagerController.h"
#include "controllers/AnimationsController.h"

/*********************
 *  GLOBAL VARIBLES
 *********************/
int imageSelect = -1;
boolean commandReceived = false;

/*********************
 *  GLOBAL DEFINE
 *********************/

SerialManager serialManager;
AnimationsController anitmationsController;

void setup()
{
	Serial.begin(115200);
	while(!Serial)
		delay(10);

	Log.begin(LOG_LEVEL, &Serial);

    anitmationsController.init(&imageSelect, &commandReceived);
    serialManager.init(&imageSelect, &commandReceived);
}

void loop()
{

}