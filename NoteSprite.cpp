#include <NoteSprite.h>

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>
#include <SD.h>

#include "lcd_image.h"

// standard U of A library settings, assuming Atmel Mega SPI pins
#define SD_CS    5  // Chip select line for SD card
#define TFT_CS   6  // Chip select line for TFT display
#define TFT_DC   7  // Data/command line for TFT
#define TFT_RST  8  // Reset line for TFT (or connect to +5V)

//Constants for NoteSprite
const int radius = 15;

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void makeCircle(int x, int y) {
	tft.fillCircle(x,y,radius,0xffff);
}


void render () {
	NoteSprite circle1;
	circle1.makeCircle(radius + 1, y1);
	NoteSprite circle2;
	circle2.makeCircle(radius*3 + 3, y2);
	NoteSprite circle3;
	circle3.makeCircle(radius*5 + 5, y3);
	NoteSprite circle4;
	circle4.makeCircle(radius*7 + 7, y4);

}

void update (int dt) {
	
}


