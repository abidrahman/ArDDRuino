/*
  Chat
 
  Simple chat program that lets one Arduino boss around another Arduino.
*/
#include <Arduino.h>
#include <SD.h>
#include "TMRpcm.h"
 

TMRpcm audio;


void playSong() {
  audio.speakerPin = 11;
  audio.play("Numb.wav");
}


int main() {
 // Initialise Arduino functionality
  init();
  
  // Attach USB for applicable processors
  #ifdef USBCON
     USBDevice.attach();
  #endif
  
  Serial.begin(9600); // Serial0: communication with the PC
  Serial3.begin(9600); // Serial3: communication with the other Arduino
  
  Serial.println("You are now connected.");
  // Chatting starts here
  uint32_t incomingByte = 0;
  while (true) {

    // Grab byte from other Arduino
    incomingByte = Serial3.read();
    
    if (incomingByte!=-1) {

      // Check for ENTER key; PLAY song if Enter key recieved.
      if (incomingByte==10 || incomingByte==13) {
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
