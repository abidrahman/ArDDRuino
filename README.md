# ArDDRuino

## Description
ArDDRuino is a Arduino port of music rhythm games like DDR (Dance Dance Revolution).
Players try to tap the buttons in a pattern specified by the falling notes, 
which are synced with the rhythm of a song. The music is played with the 
TMRpcm audio library from an SD card by another connected Arduino.

Two Arduinos required. First Arduino runs the code in the main directory.
Second Arduino runs in code in the ~/audioslave folder. To play music, you
must connect a speaker to the 2nd Arduino. However, the main program
will work without a 2nd connected Arduino.

Wiring Instructions for Arduino 1
Wiring Instructions for Arduino 2

## File Organization
__ARDUINO 1__
- ArDDRuino.cpp: main program for graphics, game, and I/O
- NoteSprite.cpp/h: class for storing information of a falling note object
- songs.h: file for storing song data in an array. Uses PROGMEM flag to store
		  data in Arduino flash memory (to conserve RAM)
__ARDUINO 2__
- AudioSlave.cpp: program for playback of music from SD card using the
				  TMRpcm audio library.
- TMRpcm/pcmRF.cpp/h: files for the TMRpcm audio library

## How It Works

__States__
The program is organized by states: MenuState, PlayState, and ScoreState.

