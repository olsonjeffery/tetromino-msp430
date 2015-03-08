// Copyright (c) 2015 Jeff Olson <olson.jeffery@gmail.com>
// This work is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
// See http://creativecommons.org/licenses/by-nc-sa/4.0/ for more information
//
// tetromino.h - tetromino game API
#include <stdint.h>
#include "../api.h"

#define CHECK_ROW(var, pos) ((var) & (1 << (pos)))
#define GET_ROW(row) (1 << (row))

#define TRUE 1
#define FALSE 0

#define PLACEMENT_COUNT 4
#define FIELD_WIDTH 10
#define GAME_ACTIVE = 0
#define GAME_OVER = 1
#define ROT_0 0
#define ROT_1 1
#define ROT_2 2
#define ROT_3 3

// different types of pieces
typedef enum TETROMINO_PIECE {
  PIECE_NONE = -1,
  PIECE_T = 0,
  PIECE_O = 1,
  PIECE_I = 2,
  PIECE_L = 3,
  PIECE_J = 4,
  PIECE_S = 5,
  PIECE_Z = 6
} TETROMINO_PIECE;

typedef struct TETROMINO_PLACEMENT {
  uint8_t row;
  uint8_t  col;
} TETROMINO_PLACEMENT;

// the complete game state
typedef struct TETROMINO_GAME {
  uint32_t field[FIELD_WIDTH];
  uint32_t score;
  TETROMINO_PLACEMENT curr_placement[PLACEMENT_COUNT];
  // BIT0: Game-in-progress status 0 = initial state, game active 1 = game over
  // BIT1 & BIT2: rotation: 00, 01, 10 & 11  
  uint8_t cp_rot;
  uint8_t game_status;
  TETROMINO_PIECE current_piece;
} TETROMINO_GAME;

// public API

void new_game(TETROMINO_GAME* game);
void reset_game(TETROMINO_GAME* game);

// indicates whether moving the current piece to the requested location is possible
uint8_t priv_placement_is_valid(TETROMINO_GAME* game, TETROMINO_PIECE piece, uint8_t rot, uint8_t col, uint32_t row);

// place a new piece on the gameboard, with the "pivot" at the provided location..
void priv_place_piece(TETROMINO_GAME* game, TETROMINO_PIECE piece, uint8_t rot, uint8_t col, uint32_t row);

void priv_get_placement(TETROMINO_PLACEMENT* placement, TETROMINO_PIECE piece, uint8_t rot, uint8_t col, uint32_t row);

/////////
// UNIMPLEMENTED
////////

// return a random TETROMINO_PIECE
TETROMINO_PIECE priv_get_random_piece();

// try to move a piece left/right
// returns 0 for success, non-zero for failure
int do_move_left(TETROMINO_GAME* game);
int do_move_right(TETROMINO_GAME* game);

// rotate current piece clockwise
void do_rotate_clockwise(TETROMINO_GAME* game);

// do a "hard drop" (make piece fall down until it "lands")
void do_hard_drop(TETROMINO_GAME* game);

// let "gravity have its effect", pulling the current tetromino down 1 space
// returns 0 if the piece is still free-falling, non-zero if the piece has landed
void do_soft_drop(TETROMINO_GAME* game);
