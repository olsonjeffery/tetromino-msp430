// Copyright (c) 2015 Jeff Olson <olson.jeffery@gmail.com>
// This work is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
// See http://creativecommons.org/licenses/by-nc-sa/4.0/ for more information
//
// tetromino_priv.h - tetromino private API, used from test suite and tetromino.c,
// but not in the actual application
#ifndef TETROMINO_PRIV_H
#define TETROMINO_PRIV_H

#include "tetromino.h"

// indicates whether moving the current piece to the requested location is possible
uint8_t priv_placement_is_valid(TETROMINO_GAME* game, TETROMINO_PIECE piece, uint8_t rot, uint8_t col, uint32_t row);

// place a new piece on the gameboard, with the "pivot" at the provided location..
void priv_place_piece(TETROMINO_GAME* game, TETROMINO_PIECE piece, uint8_t rot, uint8_t col, uint32_t row);

void priv_get_placement(TETROMINO_PLACEMENT* placement, TETROMINO_PIECE piece, uint8_t rot, uint8_t col, uint32_t row);

// sets the provided placement/rot pointers, based on the piece (each piece has a "default" placement)
void priv_set_initial_placement_for(TETROMINO_PLACEMENT* placement, TETROMINO_PIECE piece, uint8_t* rot_ptr);

// return a random TETROMINO_PIECE
TETROMINO_PIECE priv_get_random_piece();

// take the current_placement, in the provided game, and apply it to the field
void priv_land_placement(TETROMINO_GAME* game);

// process line clearing on the provided game and its current_placement
void priv_do_line_clearing_check(TETROMINO_GAME* game);

#endif
