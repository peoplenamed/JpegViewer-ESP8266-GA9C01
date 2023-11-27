#ifndef _HEX_COLORS_SERVICE_H_
#define _HEX_COLORS_SERVICE_H_

/*********************
 *      INCLUDES
 *********************/

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef struct
{
    int id;
    String name;
    unsigned long hex;
} ColorStruct;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *      CLASS
 **********************/

class HexColors
{
public:
    HexColors();

    unsigned long black = 0x0000;
    unsigned long blue = 0x001F;
    unsigned long red = 0xF800;
    unsigned long green = 0x07E0;
    unsigned long cyan = 0x07FF;
    unsigned long magenta = 0xF81F;
    unsigned long yellow = 0xFFE0;
    unsigned long white = 0xFFFF;
    unsigned long getHexColor(int chosenColor);
    unsigned long getRandomColor();

private:
    ColorStruct COLORS[8];
};

#endif // _HEX_COLORS_SERVICE_H_

// typedef struct {
//    int id;
//    String name;
//    unsigned long hex;
// } colorStruct;

// #define BLACK    0x0000
// #define BLUE     0x001F
// #define RED      0xF800
// #define GREEN    0x07E0
// #define CYAN     0x07FF
// #define MAGENTA  0xF81F
// #define YELLOW   0xFFE0
// #define WHITE    0xFFFF

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
