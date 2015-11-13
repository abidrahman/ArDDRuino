#ifndef NOTESPRITE_CPP
#define NOTESPRITE_CPP

#include <Arduino.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>
#include <SD.h>
#include "lcd_image.h"

class NoteSprite
{
public:
    
	const static int RADIUS = 15;
	const static int VELOCITY = -10;

	boolean onScreen;

	int x;
	int y;

	void update(unsigned long dt);

};


#endif
