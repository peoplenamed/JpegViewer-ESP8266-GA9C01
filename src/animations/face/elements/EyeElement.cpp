/*********************
 *      INCLUDES
 *********************/
#include "EyeElement.h"

/*********************
 *      DEFINES
 *********************/

EyeElement::EyeElement(int x, int y)
{
	this->x = x;
	this->y = y;
};

const unsigned char EyeElement::eye_angry_r[] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xf8, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xf8, 0x00,
	0x00, 0x00, 0x00, 0x3f, 0xff, 0xf1, 0xfc, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x81, 0xfc, 0x00,
	0x00, 0x00, 0x0f, 0xff, 0xfe, 0x01, 0xfc, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xf0, 0x01, 0xfc, 0x00,
	0x00, 0x03, 0xff, 0xff, 0x80, 0x01, 0xfc, 0x00, 0x00, 0x1f, 0xff, 0xfc, 0x00, 0x01, 0xfc, 0x00,
	0x00, 0x3f, 0xff, 0xe0, 0x00, 0x03, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0x00, 0x00, 0x03, 0xf8, 0x00,
	0x00, 0x3f, 0xf8, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x03, 0xf8, 0x00,
	0x00, 0x3f, 0x80, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x00, 0x0f, 0xf0, 0x00,
	0x00, 0x1f, 0xe0, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x1f, 0xe0, 0x00,
	0x00, 0x0f, 0xf0, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x7f, 0xc0, 0x00,
	0x00, 0x07, 0xfe, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x03, 0xff, 0x00, 0x03, 0xff, 0x00, 0x00,
	0x00, 0x03, 0xff, 0xf8, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xe0, 0x00, 0x00,
	0x00, 0x00, 0x07, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xfe, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const unsigned char EyeElement::eye_angry_l[] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x0f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x1f, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00,
	0x00, 0x3f, 0x8f, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x81, 0xff, 0xff, 0x80, 0x00, 0x00,
	0x00, 0x3f, 0x80, 0x7f, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x0f, 0xff, 0xfe, 0x00, 0x00,
	0x00, 0x3f, 0x80, 0x01, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x3f, 0xff, 0xf8, 0x00,
	0x00, 0x3f, 0xc0, 0x00, 0x07, 0xff, 0xfc, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0xff, 0xfc, 0x00,
	0x00, 0x1f, 0xc0, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x03, 0xfc, 0x00,
	0x00, 0x0f, 0xe0, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x01, 0xf8, 0x00,
	0x00, 0x07, 0xf8, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x07, 0xf8, 0x00,
	0x00, 0x03, 0xfc, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x03, 0xfe, 0x00, 0x00, 0x3f, 0xf0, 0x00,
	0x00, 0x01, 0xff, 0x80, 0x00, 0x7f, 0xe0, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x00, 0xff, 0xc0, 0x00,
	0x00, 0x00, 0x7f, 0xff, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x80, 0x00,
	0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xfc, 0x00, 0x00,
	0x00, 0x00, 0x03, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xc0, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const unsigned char EyeElement::eye_disappointed_lr[] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00,
	0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00,
	0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00,
	0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00,
	0x00, 0x3f, 0x80, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x00, 0x01, 0xfc, 0x00,
	0x00, 0x3f, 0x80, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x03, 0xf8, 0x00,
	0x00, 0x1f, 0xe0, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x07, 0xf8, 0x00,
	0x00, 0x0f, 0xf0, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x0f, 0xf8, 0x00, 0x00, 0x1f, 0xf0, 0x00,
	0x00, 0x07, 0xfe, 0x00, 0x00, 0x7f, 0xe0, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0xff, 0xc0, 0x00,
	0x00, 0x01, 0xff, 0xc0, 0x03, 0xff, 0x80, 0x00, 0x00, 0x00, 0xff, 0xfc, 0x3f, 0xff, 0x00, 0x00,
	0x00, 0x00, 0x7f, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00,
	0x00, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const unsigned char EyeElement::eye_satisfied_lr[] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00,
	0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00,
	0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00,
	0x00, 0x3f, 0x00, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x00, 0x03, 0xf8, 0x00,
	0x00, 0x3f, 0x80, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x00, 0x03, 0xf8, 0x00,
	0x00, 0x1f, 0xc0, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x07, 0xf0, 0x00,
	0x00, 0x1f, 0xe0, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x1f, 0xe0, 0x00,
	0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00,
	0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00,
	0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const unsigned char EyeElement::eye_dimond_lr[] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x3f, 0x80, 0x00, 0x00,
	0x00, 0x00, 0x03, 0xfc, 0x1f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf8, 0x0f, 0xe0, 0x00, 0x00,
	0x00, 0x00, 0x0f, 0xf0, 0x07, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 0x03, 0xf8, 0x00, 0x00,
	0x00, 0x00, 0x3f, 0xc0, 0x01, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x80, 0x00, 0xfe, 0x00, 0x00,
	0x00, 0x00, 0xff, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x3f, 0x80, 0x00,
	0x00, 0x03, 0xfc, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x0f, 0xe0, 0x00,
	0x00, 0x0f, 0xf0, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x03, 0xf8, 0x00,
	0x00, 0x0f, 0xe0, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x0f, 0xf0, 0x00,
	0x00, 0x03, 0xf8, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x00, 0x3f, 0xc0, 0x00,
	0x00, 0x00, 0xfe, 0x00, 0x00, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0xff, 0x00, 0x00,
	0x00, 0x00, 0x3f, 0x80, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xc0, 0x03, 0xfc, 0x00, 0x00,
	0x00, 0x00, 0x0f, 0xe0, 0x07, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x0f, 0xf0, 0x00, 0x00,
	0x00, 0x00, 0x03, 0xf8, 0x1f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfc, 0x3f, 0xc0, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xfe, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x3f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const unsigned char EyeElement::eye_closing_lr[] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00,
	0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00,
	0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00,
	0x00, 0x1f, 0xe0, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x07, 0xf8, 0x00,
	0x00, 0x1f, 0xc0, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x00, 0x01, 0xfc, 0x00,
	0x00, 0x3f, 0x80, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x00, 0x01, 0xfc, 0x00,
	0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00,
	0x00, 0x3f, 0x80, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x00, 0x01, 0xfc, 0x00,
	0x00, 0x3f, 0x80, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x03, 0xf8, 0x00,
	0x00, 0x1f, 0xe0, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x07, 0xf8, 0x00,
	0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00,
	0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00,
	0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const unsigned char EyeElement::eye_closed_lr[] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,
	0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,
	0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const unsigned char EyeElement::eye_open_lr[] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xe0, 0x00, 0x00,
	0x00, 0x00, 0x07, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xfc, 0x00, 0x00,
	0x00, 0x00, 0x3f, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x3f, 0xff, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xe0, 0x03, 0xff, 0x80, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0xff, 0xc0, 0x00,
	0x00, 0x03, 0xff, 0x00, 0x00, 0x7f, 0xe0, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x00, 0x1f, 0xe0, 0x00,
	0x00, 0x07, 0xf8, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x0f, 0xf0, 0x00,
	0x00, 0x0f, 0xf0, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x03, 0xf8, 0x00,
	0x00, 0x0f, 0xe0, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x01, 0xfc, 0x00,
	0x00, 0x1f, 0xc0, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x01, 0xfc, 0x00,
	0x00, 0x1f, 0x80, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x00, 0x00, 0xfc, 0x00,
	0x00, 0x1f, 0xc0, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x01, 0xfc, 0x00,
	0x00, 0x1f, 0xc0, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x03, 0xf8, 0x00,
	0x00, 0x0f, 0xe0, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x07, 0xf8, 0x00,
	0x00, 0x07, 0xf8, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x0f, 0xf0, 0x00,
	0x00, 0x03, 0xfc, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x7f, 0xe0, 0x00,
	0x00, 0x01, 0xff, 0x80, 0x00, 0xff, 0xc0, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x03, 0xff, 0x80, 0x00,
	0x00, 0x00, 0x7f, 0xfe, 0x3f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfe, 0x00, 0x00,
	0x00, 0x00, 0x1f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xf0, 0x00, 0x00,
	0x00, 0x00, 0x03, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const unsigned char EyeElement::eye_pop_one_lr[] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
	0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00,
	0x00, 0x07, 0xff, 0xfc, 0x3f, 0xff, 0xe0, 0x00, 0x00, 0x0f, 0xff, 0x80, 0x01, 0xff, 0xf0, 0x00,
	0x00, 0x0f, 0xff, 0x80, 0x01, 0xff, 0xf0, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x3f, 0xfc, 0x00,
	0x00, 0x7f, 0xf8, 0x00, 0x00, 0x1f, 0xfe, 0x00, 0x00, 0xff, 0xe0, 0x00, 0x00, 0x07, 0xff, 0x00,
	0x00, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0x00,
	0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0x80, 0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0x80,
	0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x80, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x80,
	0x03, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc0, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc0,
	0x03, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc0, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xc0,
	0x03, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xc0, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xc0,
	0x03, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc0, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc0,
	0x03, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc0, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc0,
	0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x80, 0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0x80,
	0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0x80, 0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0x80,
	0x00, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0xff, 0xe0, 0x00, 0x00, 0x07, 0xff, 0x00,
	0x00, 0x7f, 0xf8, 0x00, 0x00, 0x1f, 0xfe, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x3f, 0xfc, 0x00,
	0x00, 0x3f, 0xfc, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x0f, 0xff, 0x80, 0x01, 0xff, 0xf0, 0x00,
	0x00, 0x07, 0xff, 0xfc, 0x3f, 0xff, 0xe0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00,
	0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00,
	0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x00,
	0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const unsigned char EyeElement::eye_pop_two_lr[] PROGMEM = {
	0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x7f, 0xfe, 0x40, 0x00, 0x00,
	0x00, 0x00, 0x3f, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xfc, 0x00, 0x00,
	0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00,
	0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00,
	0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x1f, 0xff, 0xfc, 0x3f, 0xff, 0xf8, 0x00,
	0x00, 0x1f, 0xff, 0x80, 0x01, 0xff, 0xf8, 0x00, 0x00, 0xff, 0xff, 0x80, 0x01, 0xff, 0xfe, 0x00,
	0x00, 0xff, 0xf8, 0x00, 0x00, 0x3f, 0xfe, 0x00, 0x01, 0xff, 0xf8, 0x00, 0x00, 0x1f, 0xff, 0x00,
	0x03, 0xff, 0xc0, 0x00, 0x00, 0x07, 0xff, 0xc0, 0x03, 0xff, 0x80, 0x00, 0x00, 0x03, 0xff, 0xc0,
	0x03, 0xff, 0x80, 0x00, 0x00, 0x03, 0xff, 0xc0, 0x03, 0xff, 0x80, 0x00, 0x00, 0x03, 0xff, 0xc0,
	0x07, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x07, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xc0,
	0x07, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xc0, 0x07, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xc0,
	0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xe0, 0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xe0,
	0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xe0, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0,
	0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0,
	0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xe0, 0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xe0,
	0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xe0, 0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xe0,
	0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xe0, 0x07, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xc0,
	0x07, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x07, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0,
	0x07, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x03, 0xff, 0x80, 0x00, 0x00, 0x03, 0xff, 0xc0,
	0x03, 0xff, 0xc0, 0x00, 0x00, 0x07, 0xff, 0xc0, 0x03, 0xff, 0xc0, 0x00, 0x00, 0x07, 0xff, 0x80,
	0x01, 0xff, 0xf8, 0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0xff, 0xf8, 0x00, 0x00, 0x3f, 0xfe, 0x00,
	0x00, 0xff, 0xff, 0x80, 0x01, 0xff, 0xfe, 0x00, 0x00, 0x1f, 0xff, 0x80, 0x01, 0xff, 0xf8, 0x00,
	0x00, 0x1f, 0xff, 0xfc, 0x3f, 0xff, 0xf8, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00,
	0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00,
	0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00,
	0x00, 0x00, 0x3f, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x00,
	0x00, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00};

const unsigned char EyeElement::eye_spiral_one_lr[] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x3f, 0xff, 0x00, 0x00, 0x00,
	0x00, 0x0c, 0x00, 0xf0, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x0c, 0x01, 0xc0, 0x00, 0x70, 0x00, 0x00,
	0x00, 0x18, 0x07, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x30, 0x0e, 0x00, 0x00, 0x0e, 0x00, 0x00,
	0x00, 0x30, 0x1c, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x60, 0x18, 0x00, 0x00, 0x03, 0x00, 0x00,
	0x00, 0x60, 0x30, 0x03, 0xf0, 0x01, 0x80, 0x00, 0x00, 0x40, 0x60, 0x0f, 0xfe, 0x00, 0xc0, 0x00,
	0x00, 0xc0, 0x60, 0x1c, 0x07, 0x00, 0x40, 0x00, 0x00, 0xc0, 0xc0, 0x30, 0x01, 0x80, 0x60, 0x00,
	0x00, 0x80, 0xc0, 0x60, 0x00, 0xc0, 0x20, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x00, 0x60, 0x30, 0x00,
	0x01, 0x81, 0x80, 0x80, 0x00, 0x20, 0x30, 0x00, 0x01, 0x81, 0x81, 0x80, 0x00, 0x30, 0x10, 0x00,
	0x01, 0x81, 0x81, 0x80, 0xe0, 0x10, 0x10, 0x00, 0x01, 0x81, 0x81, 0x81, 0x30, 0x18, 0x18, 0x00,
	0x01, 0x81, 0x81, 0x81, 0x18, 0x18, 0x18, 0x00, 0x01, 0x81, 0x81, 0x80, 0x18, 0x18, 0x18, 0x00,
	0x01, 0x81, 0x80, 0x80, 0x18, 0x18, 0x18, 0x00, 0x01, 0x80, 0x80, 0xc0, 0x18, 0x18, 0x18, 0x00,
	0x00, 0x80, 0xc0, 0x60, 0x10, 0x18, 0x18, 0x00, 0x00, 0x80, 0xc0, 0x70, 0x30, 0x10, 0x18, 0x00,
	0x00, 0xc0, 0x40, 0x3f, 0xe0, 0x30, 0x10, 0x00, 0x00, 0xc0, 0x60, 0x0f, 0x80, 0x30, 0x10, 0x00,
	0x00, 0x40, 0x30, 0x00, 0x00, 0x60, 0x30, 0x00, 0x00, 0x60, 0x30, 0x00, 0x00, 0x60, 0x30, 0x00,
	0x00, 0x20, 0x18, 0x00, 0x00, 0xc0, 0x60, 0x00, 0x00, 0x30, 0x0e, 0x00, 0x01, 0x80, 0x60, 0x00,
	0x00, 0x18, 0x07, 0x00, 0x07, 0x00, 0xc0, 0x00, 0x00, 0x18, 0x01, 0xc0, 0x1e, 0x00, 0xc0, 0x00,
	0x00, 0x0c, 0x00, 0x7f, 0xf8, 0x01, 0x80, 0x00, 0x00, 0x06, 0x00, 0x0f, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x03, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x0c, 0x00, 0x00,
	0x00, 0x00, 0xe0, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00,
	0x00, 0x00, 0x1c, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x0f, 0x80, 0x00, 0x00,
	0x00, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const unsigned char EyeElement::eye_spiral_two_lr[] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x07, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xc0, 0x00, 0x00,
	0x00, 0x00, 0x03, 0xf0, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x3c, 0x00, 0x00,
	0x00, 0x00, 0x1e, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x03, 0x80, 0x00,
	0x00, 0x00, 0x70, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0x00,
	0x00, 0x01, 0x80, 0x07, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x3f, 0xff, 0x00, 0x00, 0x00,
	0x00, 0x07, 0x00, 0xf8, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x0e, 0x01, 0xe0, 0x00, 0xf0, 0x00, 0x00,
	0x00, 0x0c, 0x03, 0x80, 0x00, 0x38, 0x00, 0x00, 0x00, 0x1c, 0x07, 0x00, 0x00, 0x1c, 0x00, 0x00,
	0x00, 0x18, 0x0e, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x18, 0x1c, 0x00, 0x00, 0x07, 0x00, 0x00,
	0x00, 0x30, 0x18, 0x03, 0xf0, 0x03, 0x00, 0x00, 0x00, 0x30, 0x30, 0x0f, 0xfc, 0x01, 0x80, 0x00,
	0x00, 0x30, 0x30, 0x1c, 0x0f, 0x01, 0x80, 0x00, 0x00, 0x60, 0x30, 0x38, 0x03, 0x80, 0xc0, 0x00,
	0x00, 0x60, 0x60, 0x30, 0x01, 0x80, 0xc0, 0x00, 0x00, 0x60, 0x60, 0x60, 0x00, 0xc0, 0xc0, 0x00,
	0x00, 0x60, 0x60, 0x60, 0x00, 0xc0, 0x60, 0x00, 0x00, 0x60, 0x60, 0x60, 0x00, 0x60, 0x60, 0x00,
	0x00, 0x60, 0x60, 0x60, 0xe0, 0x60, 0x60, 0x00, 0x00, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x00,
	0x00, 0x60, 0x60, 0x30, 0x60, 0x60, 0x60, 0x00, 0x00, 0x60, 0x20, 0x38, 0x60, 0x60, 0x60, 0x00,
	0x00, 0x20, 0x30, 0x1f, 0xc0, 0x60, 0x60, 0x00, 0x00, 0x30, 0x30, 0x0f, 0x80, 0x60, 0x60, 0x00,
	0x00, 0x30, 0x18, 0x00, 0x00, 0xc0, 0x40, 0x00, 0x00, 0x30, 0x1c, 0x00, 0x00, 0xc0, 0xc0, 0x00,
	0x00, 0x18, 0x0c, 0x00, 0x01, 0x80, 0xc0, 0x00, 0x00, 0x18, 0x07, 0x00, 0x03, 0x00, 0xc0, 0x00,
	0x00, 0x0c, 0x03, 0x80, 0x0f, 0x01, 0x80, 0x00, 0x00, 0x0e, 0x01, 0xe0, 0x3c, 0x03, 0x80, 0x00,
	0x00, 0x06, 0x00, 0x7f, 0xf8, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x1f, 0xc0, 0x06, 0x00, 0x00,
	0x00, 0x03, 0x80, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x00, 0x1c, 0x00, 0x00,
	0x00, 0x00, 0xf0, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0xf0, 0x00, 0x00,
	0x00, 0x00, 0x1e, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x0f, 0x80, 0x00, 0x00,
	0x00, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xe0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const unsigned char EyeElement::eye_spiral_three_lr[] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x07, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0x80, 0x00, 0x00,
	0x00, 0x00, 0x01, 0xf0, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x7c, 0x00, 0x00,
	0x00, 0x00, 0x0e, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x07, 0x00, 0x00,
	0x00, 0x00, 0x70, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xc0, 0x00,
	0x00, 0x00, 0xc0, 0x03, 0xf8, 0x00, 0x60, 0x00, 0x00, 0x01, 0x80, 0x1f, 0xff, 0x00, 0x30, 0x00,
	0x00, 0x03, 0x80, 0x78, 0x07, 0xc0, 0x38, 0x00, 0x00, 0x03, 0x00, 0xe0, 0x00, 0xe0, 0x18, 0x00,
	0x00, 0x06, 0x01, 0xc0, 0x00, 0x70, 0x0c, 0x00, 0x00, 0x06, 0x03, 0x00, 0x00, 0x38, 0x0e, 0x00,
	0x00, 0x0c, 0x07, 0x00, 0x00, 0x1c, 0x06, 0x00, 0x00, 0x0c, 0x06, 0x00, 0x00, 0x0e, 0x06, 0x00,
	0x00, 0x0c, 0x0c, 0x01, 0xf0, 0x06, 0x03, 0x00, 0x00, 0x18, 0x0c, 0x07, 0xfc, 0x07, 0x03, 0x00,
	0x00, 0x18, 0x18, 0x0e, 0x0e, 0x03, 0x03, 0x00, 0x00, 0x18, 0x18, 0x1c, 0x07, 0x03, 0x01, 0x00,
	0x00, 0x18, 0x18, 0x18, 0x03, 0x01, 0x81, 0x80, 0x00, 0x18, 0x18, 0x18, 0x01, 0x81, 0x81, 0x80,
	0x00, 0x18, 0x18, 0x18, 0x01, 0x81, 0x81, 0x80, 0x00, 0x18, 0x18, 0x18, 0x81, 0x81, 0x81, 0x80,
	0x00, 0x18, 0x18, 0x0f, 0x81, 0x81, 0x81, 0x80, 0x00, 0x18, 0x0c, 0x07, 0x81, 0x81, 0x81, 0x80,
	0x00, 0x08, 0x0c, 0x00, 0x01, 0x81, 0x81, 0x80, 0x00, 0x0c, 0x0e, 0x00, 0x03, 0x01, 0x81, 0x80,
	0x00, 0x0c, 0x06, 0x00, 0x03, 0x01, 0x01, 0x80, 0x00, 0x06, 0x03, 0x00, 0x06, 0x03, 0x01, 0x00,
	0x00, 0x06, 0x03, 0x80, 0x0e, 0x03, 0x03, 0x00, 0x00, 0x07, 0x00, 0xe0, 0x3c, 0x06, 0x03, 0x00,
	0x00, 0x03, 0x00, 0x7f, 0xf0, 0x06, 0x03, 0x00, 0x00, 0x01, 0x80, 0x1f, 0xc0, 0x0c, 0x06, 0x00,
	0x00, 0x01, 0xc0, 0x00, 0x00, 0x1c, 0x06, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x38, 0x0c, 0x00,
	0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x0c, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0xe0, 0x18, 0x00,
	0x00, 0x00, 0x0e, 0x00, 0x03, 0xc0, 0x38, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x1f, 0x00, 0x70, 0x00,
	0x00, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const unsigned char EyeElement::eye_spiral_four_lr[] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x07, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0x80, 0x00, 0x00,
	0x00, 0x00, 0x01, 0xf0, 0x03, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x78, 0x00, 0x00,
	0x00, 0x00, 0x0f, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x0f, 0x00, 0x00,
	0x00, 0x00, 0x38, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x01, 0xc0, 0x00,
	0x00, 0x00, 0x60, 0x03, 0xf8, 0x00, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0x1f, 0xfe, 0x00, 0x60, 0x00,
	0x00, 0x01, 0xc0, 0x3c, 0x07, 0x80, 0x70, 0x00, 0x00, 0x01, 0x80, 0xf0, 0x01, 0xc0, 0x30, 0x00,
	0x00, 0x03, 0x00, 0xc0, 0x00, 0x60, 0x18, 0x00, 0x00, 0x03, 0x01, 0x80, 0x00, 0x30, 0x18, 0x00,
	0x00, 0x03, 0x03, 0x00, 0x00, 0x38, 0x0c, 0x00, 0x00, 0x02, 0x03, 0x00, 0x00, 0x18, 0x0c, 0x00,
	0x00, 0x06, 0x02, 0x01, 0xf0, 0x0c, 0x0c, 0x00, 0x00, 0x06, 0x06, 0x03, 0xf8, 0x0c, 0x04, 0x00,
	0x00, 0x06, 0x06, 0x06, 0x1c, 0x04, 0x06, 0x00, 0x00, 0x06, 0x06, 0x06, 0x0c, 0x06, 0x06, 0x00,
	0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x06, 0x06, 0x07, 0x06, 0x06, 0x06, 0x00,
	0x00, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x00, 0x00, 0x06, 0x03, 0x00, 0x06, 0x06, 0x06, 0x00,
	0x00, 0x03, 0x03, 0x00, 0x06, 0x06, 0x06, 0x00, 0x00, 0x03, 0x01, 0x80, 0x0c, 0x06, 0x06, 0x00,
	0x00, 0x03, 0x01, 0xc0, 0x1c, 0x0c, 0x06, 0x00, 0x00, 0x01, 0x80, 0xf0, 0x38, 0x0c, 0x0c, 0x00,
	0x00, 0x01, 0x80, 0x3f, 0xf0, 0x0c, 0x0c, 0x00, 0x00, 0x00, 0xc0, 0x0f, 0xc0, 0x18, 0x0c, 0x00,
	0x00, 0x00, 0xe0, 0x00, 0x00, 0x38, 0x18, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x18, 0x00,
	0x00, 0x00, 0x38, 0x00, 0x00, 0xe0, 0x38, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x01, 0xc0, 0x30, 0x00,
	0x00, 0x00, 0x0f, 0x00, 0x07, 0x80, 0x70, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x1f, 0x00, 0xe0, 0x00,
	0x00, 0x00, 0x00, 0xff, 0xfc, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 0x01, 0x80, 0x00,
	0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x0e, 0x00, 0x00,
	0x00, 0x01, 0xc0, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x78, 0x00, 0x00,
	0x00, 0x00, 0x3c, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x0f, 0xc0, 0x00, 0x00,
	0x00, 0x00, 0x03, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xe0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

void EyeElement::render(EyeType type, uint16_t foreground, uint16_t background, bool _drawBackgroundColor)
{
	drawBackgroundColor = _drawBackgroundColor;
	const unsigned char* bitmapImage;

	switch(type)
	{
	case EYE_OPEN_LR:
		drawBitmap(x, y, eye_open_lr, 64, 54, foreground, background);
		break;
	case EYE_ANGRY_R:
		drawBitmap(x, y, eye_angry_r, 64, 54, foreground, background);
		break;
	case EYE_ANGRY_L:
		drawBitmap(x, y, eye_angry_l, 64, 54, foreground, background);
		break;
	case EYE_DISAPPOINTED_LR:
		drawBitmap(x, y, eye_disappointed_lr, 64, 54, foreground, background);
		break;
	case EYE_SATISFIED_LR:
		drawBitmap(x, y, eye_satisfied_lr, 64, 54, foreground, background);
		break;
	case EYE_DIAMOND_LR:
		drawBitmap(x, y, eye_dimond_lr, 64, 54, foreground, background);
		break;
	case EYE_CLOSING_LR:
		drawBitmap(x, y, eye_closing_lr, 64, 54, foreground, background);
		break;
	case EYE_CLOSED_LR:
		drawBitmap(x, y, eye_closed_lr, 64, 54, foreground, background);
		break;
	case EYE_POP_ONE_LR:
		drawBitmap(x, y, eye_pop_one_lr, 64, 54, foreground, background);
		break;
	case EYE_POP_TWO_LR:
		drawBitmap(x, y, eye_pop_two_lr, 64, 54, foreground, background);
		break;
	case EYE_SPIRAL_ONE_LR:
		drawBitmap(x, y, eye_spiral_one_lr, 64, 54, foreground, background);
		break;
	case EYE_SPIRAL_TWO_LR:
		drawBitmap(x, y, eye_spiral_two_lr, 64, 54, foreground, background);
		break;
	case EYE_SPIRAL_THREE_LR:
		drawBitmap(x, y, eye_spiral_three_lr, 64, 54, foreground, background);
		break;
	case EYE_SPIRAL_FOUR_LR:
		drawBitmap(x, y, eye_spiral_four_lr, 64, 54, foreground, background);
		break;
	default:
		drawBitmap(x, y, eye_open_lr, 64, 54, foreground, background);
		break;
	}
}

void EyeElement::drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap,
							int16_t w, int16_t h, uint16_t color, uint16_t bg) {
    if (drawBackgroundColor) {
        gfx->drawBitmap(x, y, bitmap, w, h, color, bg);
    } else {
        gfx->drawBitmap(x, y, bitmap, w, h, color);
    }
}