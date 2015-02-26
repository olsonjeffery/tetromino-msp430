// Copyright (c) 2015 Jeff Olson <olson.jeffery@gmail.com>
// This work is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
// See http://creativecommons.org/licenses/by-nc-sa/4.0/ for more information
//
// tetromino.c - tetromino game logic/state impl
#include <stdint.h>
#include "tetromino.h"

// This is the tetris game field.. each entry is a "column"
// with "rightward" bits being more "downward" from bits to their left.
// ...way longer than it needs to be.
static uint32_t field[FIELD_WIDTH] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void reset_field() {
  uint16_t i = 0;
  for (i=0;i < FIELD_WIDTH;i++) {
    field[i] = 0;
  }
}
