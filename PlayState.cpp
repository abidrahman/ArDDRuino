//
//  PlayState.cpp
//  
//
//  Created by Kevin Wang on 2015-11-12.
//
//

#include "PlayState.h"
#include "NoteSprite.h"

NoteSprite *ns = new NoteSprite(50, 100);

void updatePlayState(unsigned long dt) {

}

void renderPlayState(Adafruit_ST7735 &tft, Joystick joystick) {
    tft.fillCircle(ns->x, ns->y, 20, 0xFFFF);
    Serial.println(ns->x);
}

void renderPlayState() {

        
}



