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
    makeCircle(NoteSprite.radius + 1, NoteSprite.radius + 1);
    makeCircle(NoteSprite.radius*3 + 3, NoteSprite.radius + 1);
    makeCircle(NoteSprite.radius*5 + 5, NoteSprite.radius + 1);
    makeCircle(NoteSprite.radius*7 + 7, NoteSprite.radius + 1);
        
}

void makeCircle(int x, int y) {
	tft.fillCircle(x,y,NoteSprite.radius,0xffff);
}
