/*
  Chat
 
  Simple chat program that lets one Arduino boss around another Arduino.
*/
#include <Arduino.h>
#include <SD.h>
#include "TMRpcm.h"
 
// standard U of A library settings, assuming Atmel Mega SPI pins
#define SD_CS    5  // Chip select line for SD card


Sd2Card card;
TMRpcm audio;

void playSong() {
  delay(2000);
  audio.speakerPin = 11;
  audio.play("Numb.wav");
  Serial.println("playing song");
}


int main() {
 // Initialise Arduino functionality
  init();
  
  // Attach USB for applicable processors
  #ifdef USBCON
     USBDevice.attach();
  #endif
  
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
  
  Serial.begin(9600); // Serial0: communication with the PC
  Serial3.begin(9600); // Serial3: communication with the other Arduino
  
  Serial.println("You are now connected.");
  // Chatting starts here
  int incomingByte = 0;
  
  while (true) {

    // Grab byte from other Arduino
    incomingByte = Serial3.read();
    
    if (incomingByte!=-1) {

      // Check for ENTER key; PLAY song if Enter key recieved.
      if (incomingByte == 10 || incomingByte == 13) {
        playSong();
        Serial.write('\n');  // LF
        Serial.write('\r');  // CR
      }
      else
        Serial.write((char)incomingByte); // print to the PC screen
      
    }
    
    // Grab byte from the PC
    incomingByte = Serial.read();
    if (incomingByte!=-1) {
      int byteToSend = Serial.read();
      Serial3.write((char)byteToSend); // send byte to other Arduino    
    }
  }

  Serial.end();
  Serial3.end();
  return 0;
}
