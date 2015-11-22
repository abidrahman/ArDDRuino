//
//  ArDDRuino.cpp
//  
//

#include <Arduino.h>
#include <avr/pgmspace.h>

#include "songs.h"


int main() {
    
    init();
    
    Serial.begin(9600);
    Serial.println("setup done");
    
    for (int i = 0; i < 50; ++i) {
        unsigned long num = pgm_read_dword(&song1[i]);
        Serial.println(num);
    }
    
    Serial.end();
}