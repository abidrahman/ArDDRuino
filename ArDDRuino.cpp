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
#include <math.h>
#include "TMRpcm.h"

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

struct Vector {
	int x;
	int y;
	Vector() : x(0), y(0) { }
};

Joystick joystick;
NoteSprite sprites[10];
Vector cursor, old_cursor;

TMRpcm audio;

boolean shouldExitState = false;

void initialization();

void loadMenuState();
void runMenuState();
void updatePlayState(unsigned long dt);
void renderPlayState();
void updateScoreState(unsigned long dt);
void renderScoreState();

uint16_t color(int red, int green, int blue);

void animateBalls();
int getBallY(int i, int t);

int main() {
    
    initialization();
    
    typedef enum {MENUSTATE, PLAYSTATE, SCORESTATE} GameState;
    GameState state = PLAYSTATE;
    
    int vertical, horizontal;
    int init_joystick_vert, init_joystick_horiz;
    init_joystick_vert = analogRead(VERT);
    init_joystick_horiz = analogRead(HORIZ);
    int lastSelState = 0, selState = 0;

	cursor.x = 64;
	cursor.y = 80;

	unsigned long time = micros();
	unsigned long dt;

	unsigned long counter = 0;

    while (true) {
        
        vertical = analogRead(VERT);      // will be 0-1023
        horizontal = analogRead(HORIZ);   // will be 0-1023
        selState = digitalRead(SEL);      // HIGH if not pressed, LOW otherwise
        
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
			if (counter == 0) loadMenuState();
            runMenuState();
			++counter;
			if (shouldExitState) {
				state = PLAYSTATE;
				shouldExitState = false;
			}
        }

        if (state == PLAYSTATE) {
			renderPlayState();
			
			updatePlayState(dt);
			
           
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

	audio.speakerPin = 11;
	audio.play("hello.wav");
}

void loadMenuState() {
	tft.setCursor(5, 50);
	tft.setTextColor(0x780F);
	tft.setTextSize(2);
	tft.print("ArDDRuino!");
	tft.setCursor(20, 70);
	tft.setTextColor(0xFD20);
	tft.setTextSize(0.6);
	tft.print("Click to begin");
}

void runMenuState() {
	/*old_cursor.x = cursor.x;
	old_cursor.y = cursor.y;
	tft.fillRect(old_cursor.x, old_cursor.y, 3, 3, 0x0);
	cursor.x = cursor.x + joystick.delta_horiz / 100;
	cursor.y = cursor.y + joystick.delta_vert / 100;
	tft.fillRect(cursor.x, cursor.y, 3, 3, 0xF800);*/
	animateBalls();
}


const int NUMBALLS = 20;
Vector balls[NUMBALLS];
int frame = 0;
const float BALLHEIGHT = 30;
void animateBalls() {
	
	for (int i = 0; i < NUMBALLS; ++i)
	{
		tft.fillCircle(balls[i].x, balls[i].y, 1, 0x0);
		balls[i].x = 7 * i;
		balls[i].y = getBallY(i, frame);
		tft.fillCircle(balls[i].x, balls[i].y, 1, 0x03EF);

	}
	frame += 3;
	
}

int getBallY(int i, int frame) {
	return 100.0 + BALLHEIGHT / 2.0 * (1.0 + sin(fmod((frame * (float(i) / 500.0 + 0.02)), 2.0*3.1415926)));
}


const int NUMCIRCLES = 4;
Vector Circles[NUMCIRCLES];
const int RADIUS = 15;
void updatePlayState(unsigned long dt) {

	
}


void renderPlayState() {
	
	tft.fillRect(0,0,32,168,tft.Color565(0x00,0xFF,0x00));
	tft.fillRect(32,0,32,168,tft.Color565(0xFF,0x00,0x00));
	tft.fillRect(64,0,32,168,tft.Color565(0x00,0xFF,0xFF));
	tft.fillRect(96,0,32,168,tft.Color565(0x00,0x00,0xFF));
	
	for (int i = 1; i < NUMCIRCLES*2; ++i) {
		Circles[i].x = RADIUS*i + i;
		Circles[i].y = RADIUS;
		tft.fillCircle(Circles[i].x, Circles[i].y, RADIUS, 0xffff);
		++i;		
	}
}

void updateScoreState(unsigned long dt) {

}

void renderScoreState() {

}

uint16_t color(int red, int green, int blue) {
	return (((31 * (red + 4)) / 255) << 11) |
		(((63 * (green + 2)) / 255) << 5) |
		((31 * (blue + 4)) / 255);
}
