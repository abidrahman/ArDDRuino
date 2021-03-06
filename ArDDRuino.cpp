//
//  ArDDRuino
//  Fun and Addicting Arduino Based Music Game
//  Created by Kevin Wang and Abid Rahman
//

#include <Arduino.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>
#include <SD.h>
#include "lcd_image.h"
#include <math.h>
#include <avr/pgmspace.h>

#include "NoteSprite.h"
#include "songs.h"

// standard U of A library settings, assuming Atmel Mega SPI pins
#define SD_CS    5  // Chip select line for SD card
#define TFT_CS   6  // Chip select line for TFT display
#define TFT_DC   7  // Data/command line for TFT
#define TFT_RST  8  // Reset line for TFT (or connect to +5V)

// joystick pins
#define SEL      9  // digital input

// button pins
#define BTNPIN1 31
#define BTNPIN2 33
#define BTNPIN3 35
#define BTNPIN4 37

//Primary initializations.
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
Sd2Card card;

struct Joystick {
    boolean pushed;
    int pushcount;
    Joystick() : pushcount(-1) { }
};

struct Vector {
    int x;
    int y;
    Vector() : x(0), y(0) { }
};

struct Button {
    boolean pushed;
};

int btnPins[] = {BTNPIN1, BTNPIN2, BTNPIN3, BTNPIN4};
int btnState[] = {0, 0, 0, 0};
int lastBtnState[] = {0, 0, 0, 0};

Button Buttons[4];
Joystick joystick;
NoteSprite sprites[10];

boolean shouldExitState = false;

//State all the functions used in the program.
void initialization();
void loadMenuState();
void runMenuState();
void loadPlayState();
void runPlayState(unsigned long dt);
void loadScoreState();

void updateScore();
void updateMultiplier();
void updateBars();

void playSong(char *songName);
uint16_t color(int red, int green, int blue);

void animateBalls();
int getBallY(int i, int t);

//Start the timer.
unsigned long time = micros();
unsigned long game_time = 0;

int main() {
    
    initialization();
    
    //Three states for this game.
    typedef enum {MENUSTATE, PLAYSTATE, SCORESTATE} GameState;
    GameState state = MENUSTATE;
    
    int lastSelState = 0, selState = 0;

    unsigned long dt;
    unsigned long counter = 0;

    while (true) {

        selState = digitalRead(SEL);      // HIGH if not pressed, LOW otherwise

        joystick.pushed = false;
        
        if (selState != lastSelState) {
            if (selState == HIGH) {
                joystick.pushed = true;
                ++joystick.pushcount;
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
            shouldExitState = false;
            if (joystick.pushed == true && joystick.pushcount > 0) shouldExitState = true;
            if (shouldExitState) {
                shouldExitState = false;
                counter = 0;
                state = PLAYSTATE;
            }
        }

        if (state == PLAYSTATE) {
            if (counter == 0) loadPlayState();
            runPlayState(dt);
            ++counter;
            game_time += dt;
            if (shouldExitState && game_time > 20000000) {
                shouldExitState = false;
                counter = 0;
                state = SCORESTATE;
            }
        }

        if (state == SCORESTATE) {
            if (counter == 0) loadScoreState();
            ++counter;
            if (joystick.pushed == true && joystick.pushcount > 0) shouldExitState = true;
            if (shouldExitState) {
                counter = 0;
                state = MENUSTATE;
            }
        }
    }
    
    Serial.end();
    Serial3.end();
    
    return 0;
}

void initialization() {
    init();
    tft.initR(INITR_BLACKTAB); // initialize a ST7735R chip, black tab

    Serial.begin(9600);
    Serial3.begin(9600);

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


// MENU STATE

const int NUMBALLS = 20;
Vector balls[NUMBALLS];
int frame = 0;
const float BALLHEIGHT = 30;

void loadMenuState() {
    tft.fillScreen(tft.Color565(0x00, 0x00, 0x00));
    tft.setCursor(5, 50);
    tft.setTextColor(color(246,71,71));
    tft.setTextSize(2);
    tft.print("ArDDRuino!");
    tft.setCursor(20, 70);
    tft.setTextColor(0xFD20);
    tft.setTextSize(0.6);
    tft.print("Click to begin");
}

void runMenuState() {
    animateBalls();
}

void animateBalls() {
    for (int i = 0; i < NUMBALLS; ++i)
    {
        tft.fillCircle(balls[i].x, balls[i].y, 1, 0x0);
        balls[i].x = 7 * i;
        balls[i].y = getBallY(i, frame);
        tft.fillCircle(balls[i].x, balls[i].y, 1, color(34,167,240));
    }
    frame += 3;
}

int getBallY(int i, int frame) {
    return 100.0 + BALLHEIGHT / 2.0 * (1.0 + sin(fmod((frame * (float(i) / 500.0 + 0.02)), 2.0*3.1415926)));
}

// END MENU STATE

// PLAY STATE

const int NUMCIRCLES = 20;
const int BARS = 4;
NoteSprite Circles[NUMCIRCLES];

const int TAPZONE_ABOVE = 140;
const int TAPZONE_BELOW = 155;
const int totalNotes = 160;
int Score;
int conScore;
int multiplier;
int oldMultiplier;
int barColor;
int notesHit;

unsigned long nextEventTime;
int eventIndex;
boolean newEvent;

void loadPlayState() {

    //Initialize PlayState Background.
    tft.fillScreen(tft.Color565(0x00,0x00,0x00));

    tft.fillRect(0,TAPZONE_ABOVE - 2,128,2,tft.Color565(0x00,0xFF,0x00));
    tft.fillRect(0,TAPZONE_BELOW - 2,128,2,tft.Color565(0xFF,0x00,0x00));

    barColor = 0xFFFF;
    for (int i = 1; i < BARS + 1; ++i) {
        tft.fillRect(i*25 - 5,0,11,160,barColor);
    }
    
    //Initialize scores and game times.
    game_time = 0;
    nextEventTime = 0;
    eventIndex = 0;
    nextEventTime = pgm_read_dword(&song1[eventIndex]);
    
    Score = 0;
    conScore = 0;
    notesHit = 0;
    int multiplier;
    int oldMultiplier;
    updateScore();
    
    tft.setCursor(2, 5);
    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.print("x");
    updateMultiplier();
    
    playSong("Numb.wav");
}


int note;
void runPlayState(unsigned long dt) {

    // Checks the time of the next event.
    if (game_time >= nextEventTime) {
        newEvent = true;
        if (game_time >= song1_length) { 
			// If time is past the song length, exit the state
            if (game_time >= song1_end) {
                shouldExitState = true;
            }
            else {
                newEvent = false;
            }
        }
    }
    
    // Retrieves the note pattern and associates notes with sprites.
    if (newEvent) { 
        
        unsigned long eventTime = nextEventTime;
        if (eventTime >= song1_length) return;
        newEvent = false;
		// Loop through all events at the specified event time
        while (pgm_read_dword(&song1[eventIndex]) == eventTime) {

			// find the note corresponding to the event
			// "note" is the column that a circle should be rendered in 
            note = pgm_read_dword(&song1[eventIndex+1]);

			// increment the index to retrieve the next event
            eventIndex += 2;
            nextEventTime = pgm_read_dword(&song1[eventIndex]);

			// finds the first off-screen circle, sets its note, and puts it on screen
            for (int i = 0; i < NUMCIRCLES; ++i) {
                if (Circles[i].onScreen == false) {
                    Circles[i].note = note;
                    Circles[i].onScreen = true;
                    Circles[i].setY(-5);
                    Circles[i].setX(Circles[i].note * 25);
                    
                    break;
                }
            }
        }
    }
    
    //Checks for button pushes.
    for (int i = 0; i < 4; ++i) {
        Buttons[i].pushed = false;
        btnState[i] = digitalRead(btnPins[i]);
        if (btnState[i] != lastBtnState[i]) {
            if (btnState[i] == HIGH) {
                Buttons[i].pushed = true;
            }
        }
    
    }

    for (int i = 0; i < NUMCIRCLES; ++i) {
        if (Circles[i].onScreen == true) {

            //Draw the circles.
            tft.fillCircle(Circles[i].getX(), Circles[i].getY(), Circles[i].RADIUS, 0x0);
        
            // Update bars so that circle doesn't drag.
            tft.fillCircle(Circles[i].getX(), Circles[i].getY() - 5, Circles[i].RADIUS + 1, barColor);
            Circles[i].update(dt);
            // Make circle once it hits the bottom.
            if (Circles[i].getY() > (170 + Circles[i].RADIUS)) {
                Circles[i].onScreen = false;
            }
            // Check for button taps on circles within the lines.
            if (Circles[i].getY() > TAPZONE_ABOVE && Circles[i].getY() < TAPZONE_BELOW && Buttons[Circles[i].note -1].pushed == true) {
                Circles[i].onScreen = false;
                tft.fillCircle(Circles[i].getX(), Circles[i].getY(), Circles[i].RADIUS + 2, barColor);
                tft.fillRect(108,5,20,10,0x00);
                Score = Score + (multiplier + 1);
                notesHit++;
                conScore++;
                updateScore();
                
            }   
            // Set multiplier to ZERO if a circle is missed.
            if (Circles[i].getY() > TAPZONE_BELOW) {     
                conScore = 0;
            }
        }
        //Cap multiplier at 5.
        multiplier = conScore / 7;
        if (multiplier > 4) {
            multiplier = 4;
        }
    }
    //Check if multiplier has changed, if change bar colours.
    if (oldMultiplier != multiplier) {
        updateBars();
        oldMultiplier = multiplier;
        tft.fillRect(10,5,10,10,0x00);
        updateMultiplier();
    }
    
}

//Changes color of the bars depending on multiplier.
void updateBars() {
    if (multiplier == 0) {
       barColor = 0xFFFF;
    } else if (multiplier == 1) { barColor = color(0,255,0);
    } else if (multiplier == 2) { barColor = color(102, 255, 255);
    } else if (multiplier == 3) { barColor = color(255, 255, 102);
    } else if (multiplier == 4) { barColor = color(255, 204, 255);
    }
    for (int i = 1; i < BARS + 1; ++i) {
        tft.fillRect(i*25 - 5,0,11,160,barColor);
    }
}

//Display score on screen.
void updateScore() {
    tft.setCursor(108, 5);
    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.print(Score);
}

//Display multiplier on screen.
void updateMultiplier() {
    tft.setCursor(10, 5);
    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.print(multiplier+1);
}

//Send a signal to start the song.
void playSong(char *songName) {
    Serial3.write(10);

}

// END PLAY STATE

// START SCORE STATE

void loadScoreState() {
    tft.fillScreen(tft.Color565(0x00,0x00,0x00));
    tft.setCursor(14, 50);
    tft.setTextColor(color(246,71,71));
    tft.setTextSize(2);
    tft.print("Score: ");
    tft.setCursor(86, 50);
    tft.print(Score);  
    
    tft.setCursor(33, 70);
    tft.setTextColor(0xFFFF);
    tft.setTextSize(0.3);
    char text[50];
    int a = (int) (((float)notesHit / (float)totalNotes) * 100.0);
    sprintf(text, "You hit %i%%", a);
    tft.print(text);
    tft.setCursor(28,80);
    tft.print("of the notes!");
    
    tft.setCursor(8, 100);
    tft.setTextColor(0xFD20);
    tft.setTextSize(0.6);
    tft.print("Click to try again!");
}

//END SCORE STATE

//Useful function to find color hex code.
uint16_t color(int red, int green, int blue) {
    return (((31 * (red + 4)) / 255) << 11) |
        (((63 * (green + 2)) / 255) << 5) |
        ((31 * (blue + 4)) / 255);
}