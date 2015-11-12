//
//  PlayState.cpp
//  
//
//  Created by Kevin Wang on 2015-11-12.
//
//

#include "PlayState.h"

void updatePlayState(unsigned long dt) {
    
    
}

void renderPlayState() {
    makeCircle(NoteSprite.RADIUS + 1, NoteSprite.RADIUS + 1);
    makeCircle(NoteSprite.RADIUS*3 + 3, NoteSprite.RADIUS + 1);
    makeCircle(NoteSprite.RADIUS*5 + 5, NoteSprite.RADIUS + 1);
    makeCircle(NoteSprite.RADIUS*7 + 7, NoteSprite.RADIUS + 1);
        
}

void makeCircle(int x, int y) {
	tft.fillCircle(x,y,NoteSprite.RADIUS,0xffff);
}
