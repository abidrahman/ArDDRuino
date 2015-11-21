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
    
	NoteSprite() :
		x(-1),
		y(-1),
		onScreen(false)
	{ }

	const static int RADIUS = 3;
	const static int VELOCITY = 80;

	boolean onScreen;
    
    int getNote();
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    
	void update(unsigned long dt);
    
    int note;
    
private:
    float x;
    float y;
};


#endif
