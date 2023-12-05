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

/*********************
 *  GLOBAL VARIBLES
 *********************/

/*********************
 *  GLOBAL DEFINE
 *********************/

SerialManager serialManager;

void setup()
{
	Serial.begin(115200);
	while(!Serial)
		delay(10);

	Log.begin(LOG_LEVEL, &Serial);

	//Serial.println("Setup done");
	serialManager.setupDisplay();
	serialManager.splashScreen();
}

void loop()
{
	serialManager.processSerialCommands();
	switch(globalAniumationState.animationName)
	{
	case ANGRY_FACE_ANIMATION:
		break;
	case PUKE_FACE_ANIMATION:
		PukeRainbowFaceAnimation pukeRainbowFaceAnimation;
		pukeRainbowFaceAnimation.renderLoop();
		break;
	}
}