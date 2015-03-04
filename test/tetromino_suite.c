// copyright (c) 2015 jeff olson <olson.jeffery@gmail.com>
// this work is licensed under a creative commons attribution-noncommercial-sharealike 4.0 international license.
// see http://creativecommons.org/licenses/by-nc-sa/4.0/ for more information
//
// tests.c -- unit tests
#include <stdlib.h>

#include "setup.h"

#include "../src/base/tetromino.h"

START_TEST(test_reset_game)
{
  TETROMINO_GAME game;
  new_game(&game);
  // should result in game being reset
  ck_assert_int_eq(PIECE_NONE, game.current_piece);
}
END_TEST

START_TEST(test_place_piece_valid)
{
  TETROMINO_GAME game;
  new_game(&game);
  priv_place_piece(&game, PIECE_T, ROT_0, COL4, ROW01);
  // should result in piece being placed
  ck_assert_int_eq(PIECE_T, game.current_piece);

  ck_assert_int_eq(COL4, game.bit0_col);
  ck_assert_int_eq(ROW01, game.bit0_row);
  ck_assert_int_eq(COL4, game.bit1_col);
  ck_assert_int_eq(ROW00, game.bit1_row);
  ck_assert_int_eq(COL3, game.bit2_col);
  ck_assert_int_eq(ROW01, game.bit2_row);
  ck_assert_int_eq(COL5, game.bit3_col);
  ck_assert_int_eq(ROW01, game.bit3_row);
}
END_TEST

START_TEST(test_identity_valid_placement)
{
  TETROMINO_GAME game;
  new_game(&game);
  // should indicate its a valid placement
  ck_assert_int_eq(TRUE, priv_placement_is_valid(&game, PIECE_T, ROT_0, COL4, ROW01));
}
END_TEST

START_TEST(test_get_placement_piece_t)
{
  TETROMINO_PLACEMENT placement = priv_get_placement(PIECE_T, ROT_0, COL4, ROW01);
  ck_assert_int_eq(COL4, placement.bit0_col);
  ck_assert_int_eq(ROW01, placement.bit0_row);
  ck_assert_int_eq(COL4, placement.bit1_col);
  ck_assert_int_eq(ROW00, placement.bit1_row);
  ck_assert_int_eq(COL3, placement.bit2_col);
  ck_assert_int_eq(ROW01, placement.bit2_row);
  ck_assert_int_eq(COL5, placement.bit3_col);
  ck_assert_int_eq(ROW01, placement.bit3_row);

  placement = priv_get_placement(PIECE_T, ROT_1, COL4, ROW01);
  ck_assert_int_eq(COL4, placement.bit0_col);
  ck_assert_int_eq(ROW01, placement.bit0_row);
  ck_assert_int_eq(COL5, placement.bit1_col);
  ck_assert_int_eq(ROW01, placement.bit1_row);
  ck_assert_int_eq(COL4, placement.bit2_col);
  ck_assert_int_eq(ROW00, placement.bit2_row);
  ck_assert_int_eq(COL4, placement.bit3_col);
  ck_assert_int_eq(ROW02, placement.bit3_row);

  placement = priv_get_placement(PIECE_T, ROT_2, COL4, ROW01);
  ck_assert_int_eq(COL4, placement.bit0_col);
  ck_assert_int_eq(ROW01, placement.bit0_row);
  ck_assert_int_eq(COL4, placement.bit1_col);
  ck_assert_int_eq(ROW02, placement.bit1_row);
  ck_assert_int_eq(COL5, placement.bit2_col);
  ck_assert_int_eq(ROW01, placement.bit2_row);
  ck_assert_int_eq(COL3, placement.bit3_col);
  ck_assert_int_eq(ROW01, placement.bit3_row);

  placement = priv_get_placement(PIECE_T, ROT_3, COL4, ROW01);
  ck_assert_int_eq(COL4, placement.bit0_col);
  ck_assert_int_eq(ROW01, placement.bit0_row);
  ck_assert_int_eq(COL3, placement.bit1_col);
  ck_assert_int_eq(ROW01, placement.bit1_row);
  ck_assert_int_eq(COL4, placement.bit2_col);
  ck_assert_int_eq(ROW02, placement.bit2_row);
  ck_assert_int_eq(COL4, placement.bit3_col);
  ck_assert_int_eq(ROW00, placement.bit3_row);
}
END_TEST

Suite * tetromino_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("tetromino");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_reset_game);
    tcase_add_test(tc_core, test_place_piece_valid);
    tcase_add_test(tc_core, test_identity_valid_placement);
    tcase_add_test(tc_core, test_get_placement_piece_t);
    suite_add_tcase(s, tc_core);

    return s;
}
