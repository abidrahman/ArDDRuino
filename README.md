# ArDDRuino

Video Demonstration: https://www.youtube.com/watch?v=Xo-vxv4seTk

## Description
ArDDRuino is a Arduino port of music rhythm games like DDR (Dance Dance Revolution).
Players try to tap the buttons in a pattern specified by the falling notes, 
which are synced with the rhythm of a song. The music is played with the 
TMRpcm audio library from an SD card by another connected Arduino.

Two Arduinos required. First Arduino runs the code in the main directory.
Second Arduino runs in code in the ~/audioslave folder. To play music, you
must connect a speaker to the 2nd Arduino. However, the main program
will work without a 2nd connected Arduino.

__Wiring Instructions for Arduino 1__  
__Wiring Instructions for Arduino 2__

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

#### States
The program is organized by states: MenuState, PlayState, and ScoreState.
The main program runs a while(true) loop, and the control is passed to the
state that the program is currently in.

__MenuState__  
The Menu State welcomes you to the game and displays a neat animation
to tickle your fancies. Press the joystick to move into the Play State.

__PlayState__  
PlayState retrieves song data, updates the coordinates of sprites, renders
sprites, and checks for button pushes.

PlayState retrieves the note pattern from the songs.h file using a loop
algorithm. The events in songs.h are stored in an array, with pairs of 
numbers specifying the time for an event ("event time") and the "note" 
(or the column that a sprite should render in). The algorithm works by moving
an index pointer. When the game time has surpassed an event time, the pointer
will increment and search for the note of the next event.

Twenty sprite objects (NoteSprite) are instantiated. However, they are only
rendered if their bool onScreen is true. The program will set onScreen to
true only when a sprite is required; otherwise it will be false.

The sprites are rendered by first redrawing over the sprite's current position
with the background colour (i.e. undrawing them). Then, their position 
is updated with a constant and the sprite is redrawn at the new position.
The program will check for boundary conditions and button pushes to see
whether a sprite should be removed from the screen.

The game also features a multipler when the player hits seven notes 
consecutively, and a score counter.

__ScoreState__  
The player's score and hit percentage is displayed.

#### Song Data (songs.h)  
The song data is stored in an array in the Arduino's flash memory using
the PROGMEM flag. The reason is that a long song would require a large 
amount of storage, and the Arduino RAM is very limited. The data is stored 
as events: pairs of numbers. The first number stores the time of the event 
in microseconds. This is calculated according to the rhythm of the song. 
The second number is the note, or the column that the sprite should be rendered in.

#### AudioSlave  
When the main program loads PlayState, a message will be send to the 2nd
Arduino over serial communication. Then, the song will begin playing. The 
audio playback is done by the TMRpcm library, which uses timer interrupts
to play wav audio from the SD card. Music playback requires an analog speaker
to be hooked up to pin 11. This can be done easily with some headphones 
by connecting the right/left channels to pin 11 and the ground channel to
the Arduino's ground.
