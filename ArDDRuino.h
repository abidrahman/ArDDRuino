#ifndef ____ArDDRuino__
#define ____ArDDRuino__

#include <Arduino.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>
#include <SD.h>
#include "lcd_image.h"

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
Sd2Card card;

struct Joystick {
	int delta_vert;
	int delta_horiz;
	boolean pushed;
};

#endif