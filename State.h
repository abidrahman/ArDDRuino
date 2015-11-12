//
//  State.h
//  
//
//  Created by Kevin Wang on 2015-11-12.
//
//

#ifndef ____State__
#define ____State__

#include <Arduino.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>
#include <SD.h>
#include "lcd_image.h"

class State {
public:
    State(Adafruit_ST7735& tft);
    virtual void update(unsigned long dt) = 0;
    virtual void render() = 0;
protected:
    Adafruit_ST7735 tft;
};



#endif /* defined(____State__) */
