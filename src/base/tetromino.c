// Copyright (c) 2015 Jeff Olson <olson.jeffery@gmail.com>
// This work is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
// See http://creativecommons.org/licenses/by-nc-sa/4.0/ for more information
//
// tetromino.c - tetromino game logic/state impl
#include "tetromino.h"

void reset_game(TETROMINO_GAME* game) {
  uint16_t i = 0;
  for (i=0;i < FIELD_WIDTH;i++) {
    game->field[i] = 0;
    game->score = 0;
    game->status = 0;
    game->current_piece = PIECE_NONE;
    game->bit0_col = COL0;
    game->bit0_row = ROW00;
    game->bit1_col = COL0;
    game->bit1_row = ROW00;
    game->bit2_col = COL0;
    game->bit2_row = ROW00;
    game->bit3_col = COL0;
    game->bit3_row = ROW00;
  }
}

void seed_rng() {
}

#define BAD_ADDR 0
TETROMINO_PIECE get_random_piece() {
}

void new_game(TETROMINO_GAME* game) {
  reset_game(game);
  //game->current_piece = piece;
}
