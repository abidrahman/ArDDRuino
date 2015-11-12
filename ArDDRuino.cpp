//
//  ArDDRuino.cpp
//  
//

#include <Arduino.h>
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

// joystick pins
#define VERT     0  // analog input
#define HORIZ    1  // analog input
#define SEL      9  // digital input

unsigned long startTime;


int main() {
    typedef enum {MenuState, PlayState, ScoreState} GameState;
    GameState = MenuState;
    
    while (true) {

        MenuState menuState;
        PlayState playState;
        ScoreState scoreState;

        if (MenuState) {
            menuState.update();
            menuState.render();
        }

        if (PlayState) {
            playState.update();
            playState.render();
        }

        if (ScoreState) {
            scoreState.update();
            scoreState.render();
        }
    
    return 0;
}