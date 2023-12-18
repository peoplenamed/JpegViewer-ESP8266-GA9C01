/*********************
 *      INCLUDES
 *********************/
#include "ColorsService.h"

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
	Log.trace("[ColorsService]<initializer>\n");
}

// unsigned long HexColors::getHexColor(int chosenColor) {
//   return COLORS[chosenColor - 1].hex;
// }

const uint16_t ColorsService::COLOR_WHEEL[361] = {63488, 63520, 63552, 63584, 63616, 63648, 63680, 63712, 63744, 63776, 63808, 63840, 63872, 63904, 63936, 64000, 64032, 64064, 64096, 64128, 64160, 64192, 64224, 64256, 64288, 64320, 64352, 64384, 64416, 64448, 64480, 64544, 64576, 64608, 64640, 64672, 64704, 64736, 64768, 64800, 64832, 64864, 64896, 64928, 64960, 64992, 65024, 65088, 65120, 65152, 65184, 65216, 65248, 65280, 65312, 65344, 65376, 65408, 65440, 65472, 65504, 65504, 63456, 63456, 61408, 61408, 59360, 59360, 57312, 57312, 55264, 55264, 53216, 53216, 51168, 49120, 49120, 47072, 47072, 45024, 45024, 42976, 42976, 40928, 40928, 38880, 38880, 36832, 36832, 34784, 32736, 32736, 30688, 30688, 28640, 28640, 26592, 26592, 24544, 24544, 22496, 22496, 20448, 20448, 18400, 18400, 16352, 14304, 14304, 12256, 12256, 10208, 10208, 8160, 8160, 6112, 6112, 4064, 4064, 2016, 2016, 2016, 2017, 2017, 2018, 2018, 2019, 2019, 2020, 2020, 2021, 2021, 2022, 2022, 2023, 2024, 2024, 2025, 2025, 2026, 2026, 2027, 2027, 2028, 2028, 2029, 2029, 2030, 2030, 2031, 2031, 2032, 2033, 2033, 2034, 2034, 2035, 2035, 2036, 2036, 2037, 2037, 2038, 2038, 2039, 2039, 2040, 2041, 2041, 2042, 2042, 2043, 2043, 2044, 2044, 2045, 2045, 2046, 2046, 2047, 2047, 2015, 1983, 1951, 1919, 1887, 1855, 1823, 1791, 1759, 1727, 1695, 1663, 1631, 1567, 1535, 1503, 1471, 1439, 1407, 1375, 1343, 1311, 1279, 1247, 1215, 1183, 1151, 1119, 1087, 1023, 991, 959, 927, 895, 863, 831, 799, 767, 735, 703, 671, 639, 607, 575, 543, 479, 447, 415, 383, 351, 319, 287, 255, 223, 191, 159, 127, 95, 63, 31, 31, 2079, 2079, 4127, 4127, 6175, 6175, 8223, 8223, 10271, 10271, 12319, 12319, 14367, 16415, 16415, 18463, 18463, 20511, 20511, 22559, 22559, 24607, 24607, 26655, 26655, 28703, 28703, 30751, 30751, 32799, 34847, 34847, 36895, 36895, 38943, 38943, 40991, 40991, 43039, 43039, 45087, 45087, 47135, 47135, 49183, 51231, 51231, 53279, 53279, 55327, 55327, 57375, 57375, 59423, 59423, 61471, 61471, 63519, 63519, 63519, 63518, 63518, 63517, 63517, 63516, 63516, 63515, 63515, 63514, 63514, 63513, 63513, 63512, 63511, 63511, 63510, 63510, 63509, 63509, 63508, 63508, 63507, 63507, 63506, 63506, 63505, 63505, 63504, 63503, 63503, 63502, 63502, 63501, 63501, 63500, 63500, 63499, 63499, 63498, 63498, 63497, 63497, 63496, 63496, 63495, 63494, 63494, 63493, 63493, 63492, 63492, 63491, 63491, 63490, 63490, 63489, 63489, 63488, 63488};

uint16_t ColorsService::getColorWheelByDegrees(int degrees)
{
	return COLOR_WHEEL[degrees];
}

uint16_t ColorsService::getRGBColor(int chosenColor)
{
	switch(chosenColor)
	{
	case 1:
		#ifdef DEBUG
			Log.info("[ColorService]<getRGBColor>  red");
		#endif
		return red;
		break;
	case 2:
		#ifdef DEBUG
			Log.info("[ColorService]<getRGBColor>  redOrange");
		#endif
		return redOrange;
		break;
	case 3:
		#ifdef DEBUG
			Log.info("[ColorService]<getRGBColor>  orange");
		#endif
		return orange;
		break;
	case 4:
		#ifdef DEBUG
			Log.info("[ColorService]<getRGBColor>  yellowOrange");
		#endif
		return yellowOrange;
		break;
	case 5:
		#ifdef DEBUG
			Log.info("[ColorService]<getRGBColor>  yellow");
		#endif
		return yellow;
		break;
	case 6:
		#ifdef DEBUG
			Log.info("[ColorService]<getRGBColor>  yellowGreen");
		#endif
		return yellowGreen;
		break;
	case 7:
		#ifdef DEBUG
			Log.info("[ColorService]<getRGBColor>  green");
		#endif
		return green;
		break;
	case 8:
		#ifdef DEBUG
			Log.info("[ColorService]<getRGBColor>  greenBlue");
		#endif
		return greenBlue;
		break;
	case 9:
		#ifdef DEBUG
			Log.info("[ColorService]<getRGBColor>  blue");
		#endif
		return blue;
		break;
	case 10:
		#ifdef DEBUG
			Log.info("[ColorService]<getRGBColor>  blueIndigo");
		#endif
		return blueIndigo;
		break;
	case 11:
		#ifdef DEBUG
			Log.info("[ColorService]<getRGBColor>  indigo");
		#endif
		return indigo;
		break;
	case 12:
		#ifdef DEBUG
			Log.info("[ColorService]<getRGBColor>  indigoViolet");
		#endif
		return indigoViolet;
		break;
	case 13:
		#ifdef DEBUG
			Log.info("[ColorService]<getRGBColor>  violet");
		#endif
		return violet;
		break;
	default:
		#ifdef DEBUG
			Log.info("[ColorService]<getRGBColor>  blue");
		#endif
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

