//
//  ScoreState.h
//  
//
//  Created by Kevin Wang on 2015-11-12.
//
//

#ifndef ____ScoreState__
#define ____ScoreState__

struct Joystick {
    int delta_vert;
    int delta_horiz;
    boolean pushed;
};

void updateScoreState(unsigned long dt);
void renderScoreState(Adafruit_ST7735 &tft, Joystick &joystick);

#endif /* defined(____ScoreState__) */
