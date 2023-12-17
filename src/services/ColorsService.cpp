/*********************
 *      INCLUDES
 *********************/
#include "ColorsService.h";

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
// HexColorStruct HEX_COLORS[8] = {{1, "black", 0x0000},
// 						 {2, "blue", 0x001F},
// 						 {3, "red", 0xF800},
// 						 {4, "green", 0x07E0},
// 						 {5, "cyan", 0x07FF},
// 						 {6, "magenta", 0xF81F},
// 						 {7, "yellow", 0xFFE0},
// 						 {8, "white", 0xFFFF}};

RgbColorStruct RGB_COLORS[14];
		
RgbColorStruct MONO[2];

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**********************
 *   CLASS
 **********************/

ColorsService::ColorsService()
{
	Log.trace("ColorsService initializer\n");
}

// unsigned long HexColors::getHexColor(int chosenColor) {
//   return COLORS[chosenColor - 1].hex;
// }

uint16_t ColorsService::getRGBColor(int chosenColor)
{
	switch(chosenColor)
	{
	case 1:
		return red;
		break;
	case 2:
		return redOrange;
		break;
	case 3:
		return orange;
		break;
	case 4:
		return yellowOrange;
		break;
	case 5:
		return yellow;
		break;
	case 6:
		return yellowGreen;
		break;
	case 7:
		return green;
		break;
	case 8:
		return greenBlue;
		break;
	case 9:
		return blue;
		break;
	case 10:
		return blueIndigo;
		break;
	case 11:
		return indigo;
		break;
	case 12:
		return indigoViolet;
		break;
	case 13:
		return violet;
		break;
	default:
		return blue;
		break;
	}
}

uint16_t ColorsService::getRandomRGBColor()
{
	int randomColor = random(0, 13);
	return getRGBColor(randomColor);
}

uint16_t ColorsService::getNextRGB(uint16_t startColor)
{
	return (startColor += 4680);
}

// the real HSV rainbow
uint16_t ColorsService::trueHSV(int angle)
{
  byte red, green, blue;

  if (angle<60) {red = 255; green = HSVlights[angle]; blue = 0;} else
  if (angle<120) {red = HSVlights[120-angle]; green = 255; blue = 0;} else 
  if (angle<180) {red = 0, green = 255; blue = HSVlights[angle-120];} else 
  if (angle<240) {red = 0, green = HSVlights[240-angle]; blue = 255;} else 
  if (angle<300) {red = HSVlights[angle-240], green = 0; blue = 255;} else 
                 {red = 255, green = 0; blue = HSVlights[360-angle];} 
    return gfx->color565(red, green, blue);
}

// the 'power-conscious' HSV rainbow
uint16_t ColorsService::powerHSV(int angle)
{
    byte red, green, blue;
    if (angle<120) {red = HSVpower[120-angle]; green = HSVpower[angle]; blue = 0;} else
    if (angle<240) {red = 0;  green = HSVpower[240-angle]; blue = HSVpower[angle-120];} else
                 {red = HSVpower[angle-240]; green = 0; blue = HSVpower[360-angle];}

    return gfx->color565(red, green, blue);
}

// sine wave rainbow
uint16_t ColorsService::sineLED(int angle)
{
    return gfx->color565(lights[(angle+120)%360], lights[angle], lights[(angle+240)%360]);
}


// uint16_t ColorsService::getHexColor(int chosenColor)
// {
// 	switch(chosenColor)
// 	{
// 	case 1:
// 		return black;
// 		break;
// 	case 2:
// 		return blue;
// 		break;
// 	case 3:
// 		return red;
// 		break;
// 	case 4:
// 		return green;
// 		break;
// 	case 5:
// 		return cyan;
// 		break;
// 	case 6:
// 		return magenta;
// 		break;
// 	case 7:
// 		return yellow;
// 		break;
// 	case 8:
// 		return white;
// 		break;
// 	default:
// 		return blue;
// 		break;
// 	}
// }

// uint16_t ColorsService::getRandomColor()
// {
// 	int randomColor = random(0, 7);
// 	return getHexColor(randomColor);
// }

// uint16_t ColorsService::getNextHex(uint16_t startColor)
// {
// 	if (startColor <= 0x001A) {
// 		startColor = 0x001A;
// 	}
// 	if (startColor >= 0xFFE0) {
// 		startColor = 0x001A;
// 	}
// 	Log.trace("Start Color: %X", (startColor + 0x0004));
// 	return startColor + 0x0004;
// }

