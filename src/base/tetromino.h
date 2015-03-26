// Copyright (c) 2015 Jeff Olson <olson.jeffery@gmail.com>
// This work is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
// See http://creativecommons.org/licenses/by-nc-sa/4.0/ for more information
//
// tetromino.h - tetromino game API
#ifndef TETROMINO_H
#define TETROMINO_H

#include <stdint.h>
#include "../api.h"

#define CHECK_ROW(var, pos) !!((var) & (1 << (pos)))
#define GET_ROW(row) (1 << (row))

#define TRUE 1
#define FALSE 0

#define PLACEMENT_COUNT 4
#define FIELD_WIDTH 10
#define FIELD_HEIGHT 20
#define GAME_ACTIVE 0
#define GAME_OVER 1
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
  // status of the game field, apart from the current piece
  uint32_t field[FIELD_WIDTH];
  // status of the current piece
  TETROMINO_PLACEMENT curr_placement[PLACEMENT_COUNT];
  uint8_t curr_rot;
  TETROMINO_PIECE curr_piece;
  // 0 = new game, 1 = game started, 2 = game over
  uint8_t game_status;
  // these are the two score metrics
  // score: get 1 point for every soft/hard drop, 10 points for every line cleared
  uint32_t score;
  // lines_cleared: just a counter of lines cleared. could be used to narrow the soft drop ticks over time
  uint32_t lines_cleared;
} TETROMINO_GAME;

void new_game(TETROMINO_GAME* game);
void reset_game(TETROMINO_GAME* game);

// let "gravity have its effect", pulling the current tetromino down 1 space
// returns 0 if the piece is still free-falling, non-zero if the piece has landed
void do_soft_drop(TETROMINO_GAME* game);

// do a "hard drop" (make piece fall down until it "lands")
void do_hard_drop(TETROMINO_GAME* game);

// try to move a piece left/right
// returns 0 for success, non-zero for failure
uint8_t do_move_left(TETROMINO_GAME* game);
uint8_t do_move_right(TETROMINO_GAME* game);

// rotate current piece clockwise
uint8_t do_rotate_clockwise(TETROMINO_GAME* game);
#endif
