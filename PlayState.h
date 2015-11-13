//
//  PlayState.h
//  
//
//  Created by Kevin Wang on 2015-11-12.
//
//

#ifndef ____PlayState__
#define ____PlayState__

#include <Arduino.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>
#include <SD.h>
#include "lcd_image.h"

#include "TypeDeclarations.h"

void updatePlayState(unsigned long dt);
void renderPlayState(Adafruit_ST7735 &tft, Joystick joystick);


#endif /* defined(____PlayState__) */
