// Copyright (c) 2015 Jeff Olson <olson.jeffery@gmail.com>
// This work is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
// See http://creativecommons.org/licenses/by-nc-sa/4.0/ for more information
//
// tetris.c - tetris game logic/state impl
#include "tetromino.h"

// This is the tetris game field.. each entry is a "column"
// with "rightward" bits being more "downward" from bits to their left.
// ...way longer than it needs to be.
static long field[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
