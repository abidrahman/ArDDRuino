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

#include "NoteSprite.h"

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
Sd2Card card;

struct Joystick {
	int delta_vert;
	int delta_horiz;
	boolean pushed;
};

struct Cursor {
	int x;
	int y;
};

Joystick joystick;
NoteSprite sprites[10];
Cursor cursor, old_cursor;

int cursor_x = 64;
int cursor_y = 80;
int old_cursor_x, old_cursor_y;

void runMenuState();
void updateMenuState(unsigned long dt);
void renderPlayState();
void updateScoreState(unsigned long dt);
void renderScoreState();

void initialization();

int main() {
    
    initialization();
    
    typedef enum {MENUSTATE, PLAYSTATE, SCORESTATE} GameState;
    GameState state = MENUSTATE;
    
    int vertical, horizontal;
    int init_joystick_vert, init_joystick_horiz;
    init_joystick_vert = analogRead(VERT);
    init_joystick_horiz = analogRead(HORIZ);
    int lastSelState = 0, selState = 0;

	unsigned long time = micros();
	unsigned long dt;

    while (true) {
        
        vertical = analogRead(VERT);      // will be 0-1023
        horizontal = analogRead(HORIZ);   // will be 0-1023
        selState = digitalRead(SEL);        // HIGH if not pressed, LOW otherwise
        
        //Compute the change in the joystick.
        joystick.delta_vert = vertical - init_joystick_vert;
        joystick.delta_horiz = horizontal - init_joystick_horiz;
        joystick.pushed = false;
        
        if (selState != lastSelState) {
            if (selState == HIGH) {
                joystick.pushed = true;
            }
        }
        lastSelState = selState;
        
        unsigned long currentTime = micros();
        dt = currentTime - time;
        time = currentTime;
        
        // STATES
        
        if (state == MENUSTATE) {
            runMenuState();
        }

        if (state == PLAYSTATE) {
            updatePlayState(dt);
            renderPlayState();
        }

        if (state == SCORESTATE) {
            updateScoreState(dt);
            renderScoreState();
        }
    }
    
    return 0;
}

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
		while (true) {} // something is wrong
	}
	else {
		Serial.println("OK!");
	}

	// Initialize Joystick
	pinMode(SEL, INPUT);
	digitalWrite(SEL, HIGH);

	// clear to black
	tft.fillScreen(tft.Color565(0x00, 0x00, 0x00));
}

void runMenuState() {
	old_cursor.x = cursor.x;
	old_cursor.y = cursor.y;
	cursor_x = cursor_x + joystick.delta_horiz / 100;
	cursor_y = cursor_y + joystick.delta_vert / 100;
	tft.fillRect(cursor.x, cursor.y, 3, 3, 0xF800);
	tft.fillRect(old_cursor.x, old_cursor.y, 3, 3, 0xF800);
}

void updatePlayState(unsigned long dt) {

}

void renderPlayState() {

}

void updateScoreState(unsigned long dt) {

}

void renderScoreState() {

}
