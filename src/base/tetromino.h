// Copyright (c) 2015 Jeff Olson <olson.jeffery@gmail.com>
// This work is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
// See http://creativecommons.org/licenses/by-nc-sa/4.0/ for more information
//
// tetromino.h - tetromino game API
#include <stdint.h>

// bitmasks to index into each location in the field
// all locations are starting in the upper-left corner and moving right/down
#define COL0 0
#define COL1 1
#define COL2 2
#define COL3 3
#define COL4 4
#define COL5 5
#define COL6 6
#define COL7 7
#define COL8 8
#define COL9 9
#define ROW00 0x00000001
#define ROW01 0x00000002
#define ROW02 0x00000004
#define ROW03 0x00000008
#define ROW04 0x00000010
#define ROW05 0x00000020
#define ROW06 0x00000040
#define ROW07 0x00000080
#define ROW08 0x00000100
#define ROW09 0x00000200
#define ROW10 0x00000400
#define ROW11 0x00000800
#define ROW12 0x00001000
#define ROW13 0x00002000
#define ROW14 0x00004000
#define ROW15 0x00008000
#define ROW16 0x00010000
#define ROW17 0x00020000
#define ROW18 0x00040000
#define ROW19 0x00080000
#define FIELD_WIDTH 10

// different types of pieces
typedef enum TETROMINO_PIECE {
  PIECE_T,
  PIECE_O,
  PIECE_I,
  PIECE_L,
  PIECE_J,
  PIECE_S,
  PIECE_Z
} TETROMINO_PIECE;

// the complete game state
typedef struct TETROMINO_GAME {
  uint32_t field[FIELD_WIDTH];
  uint32_t score;
  uint32_t bit0_row;
  uint32_t bit1_row;
  uint32_t bit2_row;
  uint32_t bit3_row;
  uint8_t  bit0_col;
  uint8_t  bit1_col;
  uint8_t  bit2_col;
  uint8_t  bit3_col;
  TETROMINO_PIECE current_piece;
} TETROMINO_GAME;

// clear the game field to its original, blank state
void reset_game(TETROMINO_GAME* game);

// UNIMPLEMENTED

// place a new piece on the gameboard, with the "pivot" at the provided location..
void place_piece(TETROMINO_GAME* game, TETROMINO_PIECE piece, uint8_t row, uint32_t col);

// try to move a piece left/right
// returns 0 for success, non-zero for failure
int try_move_piece_left(TETROMINO_GAME* game);
int try_move_piece_right(TETROMINO_GAME* game);

// rotate current piece clockwise
void rotate_piece_clockwise(TETROMINO_GAME* game);

// do a "hard drop" (make piece fall down until it "lands")
void do_hard_drop(TETROMINO_GAME* game);

// let "gravity have its effect", pulling the current tetromino down 1 space
// returns 0 if the piece is still free-falling, non-zero if the piece has landed
int do_soft_drop(TETROMINO_GAME* game);