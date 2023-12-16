#ifndef _HEX_COLORS_SERVICE_H_
#	define _HEX_COLORS_SERVICE_H_

/*********************
 *      INCLUDES
 *********************/
#	include "config.h"
#	include <Arduino.h>
#	include <ArduinoLog.h>

/*********************
 *      DEFINES
 *********************/
// #	define BLACK 0x0000
// #	define BLUE 0x001F
// #	define RED 0xF800
// #	define GREEN 0x07E0
// #	define CYAN 0x07FF
// #	define MAGENTA 0xF81F
// #	define YELLOW 0xFFE0
// #	define WHITE 0xFFFF

/**********************
 *      TYPEDEFS
 **********************/

// typedef struct
// {
// 	int id;
// 	String name;
// 	unsigned long hex;
// } HexColorStruct;

typedef struct
{
	int id;
	String name;
	uint16_t rgb;
} RgbColorStruct;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *      CLASS
 **********************/

class ColorsService
{
	public:
		ColorsService();

		// unsigned long black = 0x0000;
		// unsigned long blue = 0x001F;
		// unsigned long red = 0xF800;
		// unsigned long green = 0x07E0;
		// unsigned long cyan = 0x07FF;
		// unsigned long magenta = 0xF81F;
		// unsigned long yellow = 0xFFE0;
		// unsigned long white = 0xFFFF;
		// unsigned long getHexColor(int chosenColor);
		// unsigned long getRandomHexColor();


		uint16_t getRGBColor(int chosenColor);
		uint16_t getRandomRGBColor();
		uint16_t getNextRGB(uint16_t startColor);
		uint16_t getRGBColor(uint8_t red, uint8_t green, uint8_t blue);
		uint16_t trueHSV(int angle);
		uint16_t powerHSV(int angle);
		uint16_t sineLED(int angle);

		static const uint16_t red = 63488;
		static const uint16_t redOrange = 64128;
		static const uint16_t orange = 64800;
		static const uint16_t yellowOrange = 65152;
		static const uint16_t yellow = 65504;
		static const uint16_t yellowGreen = 34784;
		static const uint16_t green = 1024;
		static const uint16_t greenBlue = 1040;
		static const uint16_t blue = 31;
		static const uint16_t blueIndigo = 18463;
		static const uint16_t indigo = 18448;
		static const uint16_t indigoViolet = 34847;
		static const uint16_t violet = 60445;
		static const uint16_t black = 0;
		static const uint16_t white = 65535;
		// red = gfx->color565(255, 0, 0);
		// redOrange = gfx->color565(255, 80, 0);
		// orange = gfx->color565(255, 165, 0);
		// yellowOrange = gfx->color565(255, 210, 0);
		// yellow = gfx->color565(255, 255, 0);
		// yellowGreen = gfx->color565(128, 255, 0);
		// green = gfx->color565(0, 128, 0);
		// greenBlue = gfx->color565(0, 128, 128);
		// blue = gfx->color565(0, 0, 255);
		// blueIndigo = gfx->color565(75, 0, 255);
		// indigo = gfx->color565(75, 0, 130);
		// indigoViolet = gfx->color565(143, 0, 255);
		// violet = gfx->color565(238, 130, 238);
		
		static const int RGB_COLORS_SIZE = 14;
		RgbColorStruct RGB_COLORS[RGB_COLORS_SIZE] = {
			{1, "red", red},
			{2, "redOrange", redOrange},
			{3, "orange", orange},
			{4, "yellowOrange", yellowOrange},
			{5, "yellow", yellow},
			{6, "yellowGreen", yellowGreen},
			{7, "green", green},
			{8, "greenBlue", greenBlue},
			{9, "blue", blue},
			{10, "blueIndigo", blueIndigo},
			{11, "indigo", indigo},
			{12, "indigoViolet", indigoViolet},
			{13, "violet", violet}
		};
		RgbColorStruct MONO[2] = {
			{1, "black", black},
			{2, "white", white}
		};
		// HexColorStruct HEX_COLORS[8];
	private:

		const uint8_t lights[360]={
		0,   0,   0,   0,   0,   1,   1,   2, 
		2,   3,   4,   5,   6,   7,   8,   9, 
		11,  12,  13,  15,  17,  18,  20,  22, 
		24,  26,  28,  30,  32,  35,  37,  39, 
		42,  44,  47,  49,  52,  55,  58,  60, 
		63,  66,  69,  72,  75,  78,  81,  85, 
		88,  91,  94,  97, 101, 104, 107, 111, 
		114, 117, 121, 124, 127, 131, 134, 137, 
		141, 144, 147, 150, 154, 157, 160, 163, 
		167, 170, 173, 176, 179, 182, 185, 188, 
		191, 194, 197, 200, 202, 205, 208, 210, 
		213, 215, 217, 220, 222, 224, 226, 229, 
		231, 232, 234, 236, 238, 239, 241, 242, 
		244, 245, 246, 248, 249, 250, 251, 251, 
		252, 253, 253, 254, 254, 255, 255, 255, 
		255, 255, 255, 255, 254, 254, 253, 253, 
		252, 251, 251, 250, 249, 248, 246, 245, 
		244, 242, 241, 239, 238, 236, 234, 232, 
		231, 229, 226, 224, 222, 220, 217, 215, 
		213, 210, 208, 205, 202, 200, 197, 194, 
		191, 188, 185, 182, 179, 176, 173, 170, 
		167, 163, 160, 157, 154, 150, 147, 144, 
		141, 137, 134, 131, 127, 124, 121, 117, 
		114, 111, 107, 104, 101,  97,  94,  91, 
		88,  85,  81,  78,  75,  72,  69,  66, 
		63,  60,  58,  55,  52,  49,  47,  44, 
		42,  39,  37,  35,  32,  30,  28,  26, 
		24,  22,  20,  18,  17,  15,  13,  12, 
		11,   9,   8,   7,   6,   5,   4,   3, 
		2,   2,   1,   1,   0,   0,   0,   0, 
		0,   0,   0,   0,   0,   0,   0,   0, 
		0,   0,   0,   0,   0,   0,   0,   0, 
		0,   0,   0,   0,   0,   0,   0,   0, 
		0,   0,   0,   0,   0,   0,   0,   0, 
		0,   0,   0,   0,   0,   0,   0,   0, 
		0,   0,   0,   0,   0,   0,   0,   0, 
		0,   0,   0,   0,   0,   0,   0,   0, 
		0,   0,   0,   0,   0,   0,   0,   0, 
		0,   0,   0,   0,   0,   0,   0,   0, 
		0,   0,   0,   0,   0,   0,   0,   0, 
		0,   0,   0,   0,   0,   0,   0,   0, 
		0,   0,   0,   0,   0,   0,   0,   0, 
		0,   0,   0,   0,   0,   0,   0,   0, 
		0,   0,   0,   0,   0,   0,   0,   0, 
		0,   0,   0,   0,   0,   0,   0,   0};

		const uint8_t HSVlights[61] = 
		{0, 4, 8, 13, 17, 21, 25, 30, 34, 38, 42, 47, 51, 55, 59, 64, 68, 72, 76,
		81, 85, 89, 93, 98, 102, 106, 110, 115, 119, 123, 127, 132, 136, 140, 144,
		149, 153, 157, 161, 166, 170, 174, 178, 183, 187, 191, 195, 200, 204, 208,
		212, 217, 221, 225, 229, 234, 238, 242, 246, 251, 255};

		const uint8_t HSVpower[121] = 
		{0, 2, 4, 6, 8, 11, 13, 15, 17, 19, 21, 23, 25, 28, 30, 32, 34, 36, 38, 40,
		42, 45, 47, 49, 51, 53, 55, 57, 59, 62, 64, 66, 68, 70, 72, 74, 76, 79, 81, 
		83, 85, 87, 89, 91, 93, 96, 98, 100, 102, 104, 106, 108, 110, 113, 115, 117, 
		119, 121, 123, 125, 127, 130, 132, 134, 136, 138, 140, 142, 144, 147, 149, 
		151, 153, 155, 157, 159, 161, 164, 166, 168, 170, 172, 174, 176, 178, 181, 
		183, 185, 187, 189, 191, 193, 195, 198, 200, 202, 204, 206, 208, 210, 212, 
		215, 217, 219, 221, 223, 225, 227, 229, 232, 234, 236, 238, 240, 242, 244, 
		246, 249, 251, 253, 255};
};

#endif // _HEX_COLORS_SERVICE_H_

// const colorStruct COLORS[8] = {
//   {1, "BLACK", 0x0000},
//   {2, "BLUE", 0x001F},
//   {3, "RED", 0xF800},
//   {4, "GREEN", 0x07E0},
//   {5, "CYAN", 0x07FF},
//   {6, "MAGENTA", 0xF81F},
//   {7, "YELLOW", 0xFFE0},
//   {8, "WHITE", 0xFFFF}
// };


