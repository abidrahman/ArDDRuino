//
//  ScoreState.cpp
//  
//
//  Created by Kevin Wang on 2015-11-12.
//
//

#include "ScoreState.h"

ScoreState::ScoreState {
    tft.fillScreen(0x0000); // fill with black background
    tft.setCursor(50,50); // set the cursor, indicates where to display
    tft.print("HELLO");
}

void ScoreState::update(unsigned long dt) {
    
}