// Copyright (c) 2015 Jeff Olson <olson.jeffery@gmail.com>
// This work is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
// See http://creativecommons.org/licenses/by-nc-sa/4.0/ for more information
//
// main.c - application entry point

#include <msp430.h>
#include "../base/tetromino.h"

int main(void) {
   unsigned int count;
   WDTCTL = WDTPW + WDTHOLD; //Stop watchdog timer

   P4OUT = 0; //Configure P4 to output on P4.7
   P4DIR |= 0x80;

   TETROMINO_GAME game;
   reset_game(&game);

   for(;;){
      P4OUT ^= 0x80; //Toggle P4.7 using exclusive-OR
      for(count=0; count<20000; count++){ /* Insert some delay */ }
   }
}
