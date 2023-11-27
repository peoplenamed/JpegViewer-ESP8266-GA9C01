/*********************
 *      INCLUDES
 *********************/
#include <Arduino.h>
#include "HexColorsService.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

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

ColorStruct COLORS[8] = {
    {1, "black", 0x0000},
    {2, "blue", 0x001F},
    {3, "red", 0xF800},
    {4, "green", 0x07E0},
    {5, "cyan", 0x07FF},
    {6, "magenta", 0xF81F},
    {7, "yellow", 0xFFE0},
    {8, "white", 0xFFFF}};

HexColors::HexColors()
{
    Serial.println("HexColors initializer");
}

// unsigned long HexColors::getHexColor(int chosenColor) {
//   return COLORS[chosenColor - 1].hex;
// }

unsigned long HexColors::getHexColor(int chosenColor)
{
    switch (chosenColor)
    {
    case 1:
        return this->black;
        break;
    case 2:
        return this->blue;
        break;
    case 3:
        return this->red;
        break;
    case 4:
        return this->green;
        break;
    case 5:
        return this->cyan;
        break;
    case 6:
        return this->magenta;
        break;
    case 7:
        return this->yellow;
        break;
    case 8:
        return this->white;
        break;
    default:
        return this->blue;
        break;
    }
}

unsigned long HexColors::getRandomColor()
{
    int randomColor = random(0, 7);
    return this->getHexColor(randomColor);
}
