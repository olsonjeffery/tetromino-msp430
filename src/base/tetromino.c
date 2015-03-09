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
    game->game_status = 0;
    game->curr_rot = 0;
    game->curr_piece = PIECE_NONE;
    game->curr_placement[0].col = 0;
    game->curr_placement[0].row = 0;
    game->curr_placement[1].col = 0;
    game->curr_placement[1].row = 0;
    game->curr_placement[2].col = 0;
    game->curr_placement[2].row = 0;
    game->curr_placement[3].col = 0;
    game->curr_placement[3].row = 0;
  }
}

static uint8_t rand_initialized = FALSE;
TETROMINO_PIECE priv_get_random_piece() {
  if(!rand_initialized) {
    seed_rng();
    rand_initialized = TRUE;
  }
  return (TETROMINO_PIECE)get_random_number() % 7;
}

void priv_set_initial_placement_for(TETROMINO_PLACEMENT* placement, TETROMINO_PIECE piece, uint8_t* rot_ptr) {
  switch (piece) {
    case PIECE_T:
      *rot_ptr = ROT_2;
      priv_get_placement(placement, piece, *rot_ptr, 4, 0);
      break;
    case PIECE_I:
      *rot_ptr = ROT_0;
      priv_get_placement(placement, piece, *rot_ptr, 4, 0);
      break;
    case PIECE_O:
      *rot_ptr = ROT_0;
      priv_get_placement(placement, piece, *rot_ptr, 4, 0);
      break;
    case PIECE_L:
      *rot_ptr = ROT_2;
      priv_get_placement(placement, piece, *rot_ptr, 4, 0);
      break;
    case PIECE_J:
      *rot_ptr = ROT_0;
      priv_get_placement(placement, piece, *rot_ptr, 4, 0);
      break;
    case PIECE_S:
      *rot_ptr = ROT_2;
      priv_get_placement(placement, piece, *rot_ptr, 4, 0);
      break;
    case PIECE_Z:
      *rot_ptr = ROT_2;
      priv_get_placement(placement, piece, *rot_ptr, 4, 0);
      break;
    default:
      // failure
      break;
  }
}

void new_game(TETROMINO_GAME* game) {
  reset_game(game);
  game->curr_piece = priv_get_random_piece();
  priv_set_initial_placement_for(game->curr_placement, game->curr_piece, &game->curr_rot);
}

void priv_place_piece(TETROMINO_GAME* game, TETROMINO_PIECE piece, uint8_t rot, uint8_t col, uint32_t row) {
  //
  if(priv_placement_is_valid(game, piece, rot, col, row)) {
    // FIXME : save this redcl of the placement... should be able to capture the initial computation
    // in priv_placement_is_valid() ?
    TETROMINO_PLACEMENT placement[PLACEMENT_COUNT];
    priv_get_placement(placement, piece, rot, col, row);
    game->curr_piece = piece;
    game->curr_placement[0] = placement[0];
    game->curr_placement[1] = placement[1];
    game->curr_placement[2] = placement[2];
    game->curr_placement[3] = placement[3];
  }
}

uint8_t priv_placement_is_valid(TETROMINO_GAME* game, TETROMINO_PIECE piece, uint8_t rot, uint8_t col, uint32_t row) {
  TETROMINO_PLACEMENT placement[PLACEMENT_COUNT];
  priv_get_placement(placement, piece, rot, col, row);
  unsigned short ctr = 0;
  uint8_t curr_row;
  uint8_t curr_col;
  for(ctr = 0;ctr < PLACEMENT_COUNT;ctr++) {
    curr_row = placement[ctr].row;
    curr_col = placement[ctr].col;
    // top/bottom bounds
    if (curr_row > 19) {
      return FALSE;
    }
    // left/right bounds
    if (curr_col > 9) {
      return FALSE;
    }
    // we look at this placement and examine the current field.. is there anything there?
    if(CHECK_ROW(game->field[curr_col], curr_row)) {
      return FALSE;
    }
  }
  return TRUE;
}

void priv_get_placement(TETROMINO_PLACEMENT* placement, TETROMINO_PIECE piece, uint8_t rot, uint8_t col, uint32_t row) {
  if (piece == PIECE_T) {
    if (rot == ROT_0) {
      // .1.
      // 203
      // ...
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col;
      placement[1].row = row - 1;
      placement[2].col = col - 1;
      placement[2].row = row;
      placement[3].col = col + 1;
      placement[3].row = row;
    }
    else if (rot == ROT_1) {
      //  .2.
      //  .01
      //  .3.
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col + 1;
      placement[1].row = row;
      placement[2].col = col;
      placement[2].row = row - 1;
      placement[3].col = col;
      placement[3].row = row + 1;
    }
    else if (rot == ROT_2) {
      // ...
      // 302
      // .1.
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col;
      placement[1].row = row + 1;
      placement[2].col = col + 1;
      placement[2].row = row;
      placement[3].col = col - 1;
      placement[3].row = row;
    }
    else if (rot == ROT_3) {
      // .3.
      // 10.
      // .2.
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col - 1;
      placement[1].row = row;
      placement[2].col = col;
      placement[2].row = row + 1;
      placement[3].col = col;
      placement[3].row = row - 1;
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
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col - 1;
      placement[1].row = row;
      placement[2].col = col + 1;
      placement[2].row = row;
      placement[3].col = col + 2;
      placement[3].row = row ;
    }
    else if (rot == ROT_1) {
      // ..1.
      // ..0.
      // ..2.
      // ..3.
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col;
      placement[1].row = row - 1;
      placement[2].col = col;
      placement[2].row = row + 1;
      placement[3].col = col;
      placement[3].row = row + 2;
    }
    else if (rot == ROT_2) {
      // ....
      // ....
      // 3201
      // ....
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col + 1;
      placement[1].row = row;
      placement[2].col = col - 1;
      placement[2].row = row;
      placement[3].col = col - 2;
      placement[3].row = row ;
    }
    else if (rot == ROT_3) {
      // .3..
      // .2..
      // .0..
      // .1..
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col;
      placement[1].row = row + 1;
      placement[2].col = col;
      placement[2].row = row - 1;
      placement[3].col = col;
      placement[3].row = row - 2;
    }
    else {
      // failure
    }
  }
  else if (piece == PIECE_O) {
    // .01.
    // .23.
    placement[0].col = col;
    placement[0].row = row;
    placement[1].col = col + 1;
    placement[1].row = row;
    placement[2].col = col;
    placement[2].row = row + 1;
    placement[3].col = col + 1;
    placement[3].row = row + 1;
  }
  else if (piece == PIECE_J) {
    if (rot == ROT_0) {
      // ...
      // 102
      // ..3
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col - 1;
      placement[1].row = row;
      placement[2].col = col + 1;
      placement[2].row = row;
      placement[3].col = col + 1;
      placement[3].row = row + 1;
    }
    else if (rot == ROT_1) {
      // .1.
      // .0.
      // 32.
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col;
      placement[1].row = row - 1;
      placement[2].col = col;
      placement[2].row = row + 1;
      placement[3].col = col - 1;
      placement[3].row = row + 1;
    }
    else if (rot == ROT_2) {
      // 3..
      // 201
      // ...
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col + 1;
      placement[1].row = row;
      placement[2].col = col - 1;
      placement[2].row = row;
      placement[3].col = col - 1;
      placement[3].row = row - 1;
    }
    else if (rot == ROT_3) {
      // .23
      // .0.
      // .1.
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col;
      placement[1].row = row + 1;
      placement[2].col = col;
      placement[2].row = row - 1;
      placement[3].col = col + 1;
      placement[3].row = row - 1;
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
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col + 1;
      placement[1].row = row;
      placement[2].col = col - 1;
      placement[2].row = row;
      placement[3].col = col + 1;
      placement[3].row = row - 1;
    }
    else if (rot == ROT_1) {
      // .2.
      // .0.
      // .13
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col;
      placement[1].row = row + 1;
      placement[2].col = col;
      placement[2].row = row - 1;
      placement[3].col = col + 1;
      placement[3].row = row + 1;
    }
    else if (rot == ROT_2) {
      // ...
      // 102
      // 3..
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col - 1;
      placement[1].row = row;
      placement[2].col = col + 1;
      placement[2].row = row;
      placement[3].col = col - 1;
      placement[3].row = row + 1;
    }
    else if (rot == ROT_3) {
      // 31.
      // .0.
      // .2.
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col;
      placement[1].row = row - 1;
      placement[2].col = col;
      placement[2].row = row + 1;
      placement[3].col = col - 1;
      placement[3].row = row - 1;
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
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col;
      placement[1].row = row - 1;
      placement[2].col = col + 1;
      placement[2].row = row - 1;
      placement[3].col = col - 1;
      placement[3].row = row;
    }
    else if (rot == ROT_1) {
      // .3.
      // .01
      // ..2
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col + 1;
      placement[1].row = row;
      placement[2].col = col + 1;
      placement[2].row = row + 1;
      placement[3].col = col;
      placement[3].row = row - 1;
    }
    else if (rot == ROT_2) {
      // ...
      // .03
      // 21.
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col;
      placement[1].row = row + 1;
      placement[2].col = col - 1;
      placement[2].row = row + 1;
      placement[3].col = col + 1;
      placement[3].row = row;
    }
    else if (rot == ROT_3) {
      // 2..
      // 10.
      // .3.
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col - 1;
      placement[1].row = row;
      placement[2].col = col - 1;
      placement[2].row = row - 1;
      placement[3].col = col;
      placement[3].row = row + 1;
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
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col - 1;
      placement[1].row = row - 1;
      placement[2].col = col;
      placement[2].row = row - 1;
      placement[3].col = col + 1;
      placement[3].row = row;
    }
    else if (rot == ROT_1) {
      // ..1
      // .02
      // .3.
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col + 1;
      placement[1].row = row - 1;
      placement[2].col = col + 1;
      placement[2].row = row;
      placement[3].col = col;
      placement[3].row = row + 1;
    }
    else if (rot == ROT_2) {
      // ...
      // 30.
      // .21
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col + 1;
      placement[1].row = row + 1;
      placement[2].col = col;
      placement[2].row = row + 1;
      placement[3].col = col - 1;
      placement[3].row = row;
    }
    else if (rot == ROT_3) {
      // .3.
      // 20.
      // 1..
      placement[0].col = col;
      placement[0].row = row;
      placement[1].col = col - 1;
      placement[1].row = row + 1;
      placement[2].col = col - 1;
      placement[2].row = row;
      placement[3].col = col;
      placement[3].row = row - 1;
    }
    else {
      // failure
    }
  }
  else {
    // failure
  }
}
