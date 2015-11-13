#ifndef ____MenuState__
#define ____MenuState__

#include <Arduino.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>
#include <SD.h>
#include "lcd_image.h"

#include "TypeDeclarations.h"


void updateMenuState(unsigned long dt);
void renderMenuState(Adafruit_ST7735 &tft, Joystick joystick);

#endif /* defined(____MenuState__) */
