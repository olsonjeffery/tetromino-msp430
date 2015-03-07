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

TETROMINO_PIECE priv_get_random_piece() {
  return PIECE_NONE;
}

void new_game(TETROMINO_GAME* game) {
  reset_game(game);
}

void priv_place_piece(TETROMINO_GAME* game, TETROMINO_PIECE piece, uint8_t rot, uint8_t col, uint32_t row) {
  //
}

uint8_t priv_placement_is_valid(TETROMINO_GAME* game, TETROMINO_PIECE piece, uint8_t rot, uint8_t col, uint32_t row) {
  TETROMINO_PLACEMENT placement = priv_get_placement(piece, rot, col, row);
  unsigned short ctr = 0;
  uint32_t curr_rows[] = { placement.bit0_row, placement.bit1_row, placement.bit2_row, placement.bit3_row };
  uint8_t curr_cols[] = { placement.bit0_col, placement.bit1_col, placement.bit2_col, placement.bit3_col };
  uint32_t curr_row;
  uint8_t curr_col;
  for(ctr = 0;ctr < 4;ctr++) {
    curr_row = curr_rows[ctr];
    curr_col = curr_cols[ctr];
    // top/bottom bounds
    if (curr_row < ROW00 || curr_row > ROW19) {
      return FALSE;
    }
    // left/right bounds
    if (curr_col < COL0 || curr_col > COL9) {
      return FALSE;
    }
  }
  return TRUE;
}

TETROMINO_PLACEMENT priv_get_placement(TETROMINO_PIECE piece, uint8_t rot, uint8_t col, uint32_t row) {
  TETROMINO_PLACEMENT placement;
  if (piece == PIECE_T) {
    if (rot == ROT_0) {
      // .1.
      // 203
      // ...
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col;
      placement.bit1_row = row >> 1;
      placement.bit2_col = col - 1;
      placement.bit2_row = row;
      placement.bit3_col = col + 1;
      placement.bit3_row = row;
    }
    else if (rot == ROT_1) {
      //  .2.
      //  .01
      //  .3.
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col + 1;
      placement.bit1_row = row;
      placement.bit2_col = col;
      placement.bit2_row = row >> 1;
      placement.bit3_col = col;
      placement.bit3_row = row << 1;
    }
    else if (rot == ROT_2) {
      // ...
      // 302
      // .1.
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col;
      placement.bit1_row = row << 1;
      placement.bit2_col = col + 1;
      placement.bit2_row = row;
      placement.bit3_col = col - 1;
      placement.bit3_row = row;
    }
    else if (rot == ROT_3) {
      // .3.
      // 10.
      // .2.
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col - 1;
      placement.bit1_row = row;
      placement.bit2_col = col;
      placement.bit2_row = row << 1;
      placement.bit3_col = col;
      placement.bit3_row = row >> 1;
    }
    else {
      // failure
    }
  }
  else if (piece == PIECE_I) {
    if (rot == ROT_0) {
      // ....
      // 1023
      // ....
      // ....
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col - 1;
      placement.bit1_row = row;
      placement.bit2_col = col + 1;
      placement.bit2_row = row;
      placement.bit3_col = col + 2;
      placement.bit3_row = row ;
    }
    else if (rot == ROT_1) {
      // ..1.
      // ..0.
      // ..2.
      // ..3.
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col;
      placement.bit1_row = row >> 1;
      placement.bit2_col = col;
      placement.bit2_row = row << 1;
      placement.bit3_col = col;
      placement.bit3_row = row << 2;
    }
    else if (rot == ROT_2) {
      // ....
      // ....
      // 3201
      // ....
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col + 1;
      placement.bit1_row = row;
      placement.bit2_col = col - 1;
      placement.bit2_row = row;
      placement.bit3_col = col - 2;
      placement.bit3_row = row ;
    }
    else if (rot == ROT_3) {
      // .3..
      // .2..
      // .0..
      // .1..
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col;
      placement.bit1_row = row << 1;
      placement.bit2_col = col;
      placement.bit2_row = row >> 1;
      placement.bit3_col = col;
      placement.bit3_row = row >> 2;
    }
    else {
      // failure
    }
  }
  else if (piece == PIECE_O) {
    // .01.
    // .23.
    placement.bit0_col = col;
    placement.bit0_row = row;
    placement.bit1_col = col + 1;
    placement.bit1_row = row;
    placement.bit2_col = col;
    placement.bit2_row = row << 1;
    placement.bit3_col = col + 1;
    placement.bit3_row = row << 1;
  }
  else if (piece == PIECE_J) {
    if (rot == ROT_0) {
      // ...
      // 102
      // ..3
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col - 1;
      placement.bit1_row = row;
      placement.bit2_col = col + 1;
      placement.bit2_row = row;
      placement.bit3_col = col + 1;
      placement.bit3_row = row << 1;
    }
    else if (rot == ROT_1) {
      // .1.
      // .0.
      // 32.
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col;
      placement.bit1_row = row >> 1;
      placement.bit2_col = col;
      placement.bit2_row = row << 1;
      placement.bit3_col = col - 1;
      placement.bit3_row = row << 1;
    }
    else if (rot == ROT_2) {
      // 3..
      // 201
      // ...
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col + 1;
      placement.bit1_row = row;
      placement.bit2_col = col - 1;
      placement.bit2_row = row;
      placement.bit3_col = col - 1;
      placement.bit3_row = row >> 1;
    }
    else if (rot == ROT_3) {
      // .23
      // .0.
      // .1.
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col;
      placement.bit1_row = row << 1;
      placement.bit2_col = col;
      placement.bit2_row = row >> 1;
      placement.bit3_col = col + 1;
      placement.bit3_row = row >> 1;
    }
    else {
      // failure
    }
  }
  else if (piece == PIECE_L) {
    if (rot == ROT_0) {
      // ..3
      // 201
      // ...
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col + 1;
      placement.bit1_row = row;
      placement.bit2_col = col - 1;
      placement.bit2_row = row;
      placement.bit3_col = col + 1;
      placement.bit3_row = row >> 1;
    }
    else if (rot == ROT_1) {
      // .2.
      // .0.
      // .13
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col;
      placement.bit1_row = row << 1;
      placement.bit2_col = col;
      placement.bit2_row = row >> 1;
      placement.bit3_col = col + 1;
      placement.bit3_row = row << 1;
    }
    else if (rot == ROT_2) {
      // ...
      // 102
      // 3..
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col - 1;
      placement.bit1_row = row;
      placement.bit2_col = col + 1;
      placement.bit2_row = row;
      placement.bit3_col = col - 1;
      placement.bit3_row = row << 1;
    }
    else if (rot == ROT_3) {
      // 31.
      // .0.
      // .2.
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col;
      placement.bit1_row = row >> 1;
      placement.bit2_col = col;
      placement.bit2_row = row << 1;
      placement.bit3_col = col - 1;
      placement.bit3_row = row >> 1;
    }
    else {
      // failure
    }
  }
  else if (piece == PIECE_S) {
    if (rot == ROT_0) {
      // .12
      // 30.
      // ...
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col;
      placement.bit1_row = row >> 1;
      placement.bit2_col = col + 1;
      placement.bit2_row = row >> 1;
      placement.bit3_col = col - 1;
      placement.bit3_row = row;
    }
    else if (rot == ROT_1) {
      // .3.
      // .01
      // ..2
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col + 1;
      placement.bit1_row = row;
      placement.bit2_col = col + 1;
      placement.bit2_row = row << 1;
      placement.bit3_col = col;
      placement.bit3_row = row >> 1;
    }
    else if (rot == ROT_2) {
      // ...
      // .03
      // 21.
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col;
      placement.bit1_row = row << 1;
      placement.bit2_col = col - 1;
      placement.bit2_row = row << 1;
      placement.bit3_col = col + 1;
      placement.bit3_row = row;
    }
    else if (rot == ROT_3) {
      // 2..
      // 10.
      // .3.
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col - 1;
      placement.bit1_row = row;
      placement.bit2_col = col - 1;
      placement.bit2_row = row >> 1;
      placement.bit3_col = col;
      placement.bit3_row = row << 1;
    }
    else {
      // failure
    }
  }
  else if (piece == PIECE_Z) {
    if (rot == ROT_0) {
      // 12.
      // .03
      // ...
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col - 1;
      placement.bit1_row = row >> 1;
      placement.bit2_col = col;
      placement.bit2_row = row >> 1;
      placement.bit3_col = col + 1;
      placement.bit3_row = row;
    }
    else if (rot == ROT_1) {
      // ..1
      // .02
      // .3.
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col + 1;
      placement.bit1_row = row >> 1;
      placement.bit2_col = col + 1;
      placement.bit2_row = row;
      placement.bit3_col = col;
      placement.bit3_row = row << 1;
    }
    else if (rot == ROT_2) {
      // ...
      // 30.
      // .21
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col + 1;
      placement.bit1_row = row << 1;
      placement.bit2_col = col;
      placement.bit2_row = row << 1;
      placement.bit3_col = col - 1;
      placement.bit3_row = row;
    }
    else if (rot == ROT_3) {
      // .3.
      // 20.
      // 1..
      placement.bit0_col = col;
      placement.bit0_row = row;
      placement.bit1_col = col - 1;
      placement.bit1_row = row << 1;
      placement.bit2_col = col - 1;
      placement.bit2_row = row;
      placement.bit3_col = col;
      placement.bit3_row = row >> 1;
    }
    else {
      // failure
    }
  }
  else {
    // failure
  }
  return placement;
}
