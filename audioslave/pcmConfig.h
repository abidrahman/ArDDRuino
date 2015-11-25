
/*
This library was intended to be a simple and user friendly wav audio player using standard
Arduino libraries, playing bare-bones standard format WAV files.

Many of the extra features have been added due to user request, and are enabled
optionally only to preserve the out of the box simplicity and performance initially
intended.

Code/Updates: https://github.com/TMRh20/TMRpcm
Wiki: https://github.com/TMRh20/TMRpcm/wiki
Blog: https://tmrh20.blogspot.com/

*/


#ifndef pcmConfig_h   // if x.h hasn't been included yet...
#define pcmConfig_h   //   #define this so the compiler knows it has been included

#include <Arduino.h>



/****************** GENERAL USER DEFINES *********************************
 See https://github.com/TMRh20/TMRpcm/wiki for info on usage

   Override the default size of the buffers (MAX 254). There are 2 buffers, so memory usage will be double this number
   Defaults to 64bytes for Uno etc. 254 for Mega etc. note: In multi mode there are 4 buffers*/
#define SD_FULLSPEED



#endif
