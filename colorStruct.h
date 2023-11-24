typedef struct {
   int id;
   String name;
   unsigned long hex;
} colorStruct;

//#define BLACK    0x0000
//#define BLUE     0x001F
//#define RED      0xF800
//#define GREEN    0x07E0
//#define CYAN     0x07FF
//#define MAGENTA  0xF81F
//#define YELLOW   0xFFE0 
//#define WHITE    0xFFFF

const colorStruct COLORS[8] = {
  {1, "BLACK", 0x0000},
  {2, "BLUE", 0x001F},
  {3, "RED", 0xF800},
  {4, "GREEN", 0x07E0},
  {5, "CYAN", 0x07FF},
  {6, "MAGENTA", 0xF81F},
  {7, "YELLOW", 0xFFE0},
  {8, "WHITE", 0xFFFF}
};

unsigned long getHexColor(int chosenColor) {
//  colorStruct color;
//  for (int x = 0; x <= 7; x++) {
//    if (chosenColor == COLORS[x].id) {
//      color = COLORS[x];
//    }
//  }
//  return color.hex
  return COLORS[chosenColor - 1].hex;
}

unsigned long getRandomColor() {
  int randomColor = random(0,7);
  return getHexColor(randomColor);
}
