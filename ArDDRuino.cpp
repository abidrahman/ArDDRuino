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

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void initialization() {
    init();
    tft.initR(INITR_BLACKTAB); // initialize a ST7735R chip, black tab
    
    Serial.begin(9600);
    
    Serial.print("Initializing SD card...");
    if (!SD.begin(SD_CS)) {
        Serial.println("failed!");
    }
    Serial.println("OK!");
    // Some more initialization
    Serial.print("Doing raw initialization...");
    if (!card.init(SPI_HALF_SPEED, SD_CS)) {
        Serial.println("failed!");
        while(true) {} // something is wrong
    } else {
        Serial.println("OK!");
    }
    
    // Initialize Joystick
    pinMode(SEL,INPUT);
    digitalWrite(SEL,HIGH);
    
    // clear to black
    tft.fillScreen(tft.Color565(0x00, 0x00, 0x00));
    
}

int main() {
    
    initialization();
    
    typedef enum {MenuState, PlayState, ScoreState} GameState;
    GameState = MenuState;
    
    MenuState menuState;
    PlayState playState;
    ScoreState scoreState;
    
    unsigned long time = micros();
    unsigned long dt; //change in time from previous loop
    
    while (true) {
        
        unsigned long currentTime = micros();
        dt = currentTime - time;
        time = currentTime;
        
        if (MenuState) {
            menuState.update(dt);
            menuState.render();
        }

        if (PlayState) {
            playState.update(dt);
            playState.render();
        }

        if (ScoreState) {
            scoreState.update(dt);
            scoreState.render();
        }
    
    return 0;
}