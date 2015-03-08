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
START_TEST(test_get_placement_piece_t)
{
  TETROMINO_PLACEMENT placement[PLACEMENT_COUNT];
  priv_get_placement(placement, PIECE_T, ROT_0, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(4, placement[1].col);
  ck_assert_int_ne(GET_ROW(0) & placement[1].row, 0);
  ck_assert_int_eq(3, placement[2].col);
  ck_assert_int_ne(GET_ROW(1) & placement[2].row, 0);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_ne(GET_ROW(1) & placement[3].row, 0);

  priv_get_placement(placement, PIECE_T, ROT_1, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_ne(GET_ROW(1) & placement[1].row, 0);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_ne(GET_ROW(0) & placement[2].row, 0);
  ck_assert_int_eq(4, placement[3].col);
  ck_assert_int_ne(GET_ROW(2) & placement[3].row, 0);

  priv_get_placement(placement, PIECE_T, ROT_2, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(4, placement[1].col);
  ck_assert_int_ne(GET_ROW(2) & placement[1].row, 0);
  ck_assert_int_eq(5, placement[2].col);
  ck_assert_int_ne(GET_ROW(1) & placement[2].row, 0);
  ck_assert_int_eq(3, placement[3].col);
  ck_assert_int_ne(GET_ROW(1) & placement[3].row, 0);

  priv_get_placement(placement, PIECE_T, ROT_3, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(3, placement[1].col);
  ck_assert_int_ne(GET_ROW(1) & placement[1].row, 0);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_ne(GET_ROW(2) & placement[2].row, 0);
  ck_assert_int_eq(4, placement[3].col);
  ck_assert_int_ne(GET_ROW(0) & placement[3].row, 0);
}
END_TEST

START_TEST(test_get_placement_piece_i)
{
  TETROMINO_PLACEMENT placement[4];
  priv_get_placement(placement, PIECE_I, ROT_0, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(3, placement[1].col);
  ck_assert_int_ne(GET_ROW(1) & placement[1].row, 0);
  ck_assert_int_eq(5, placement[2].col);
  ck_assert_int_ne(GET_ROW(1) & placement[2].row, 0);
  ck_assert_int_eq(6, placement[3].col);
  ck_assert_int_ne(GET_ROW(1) & placement[3].row, 0);

  priv_get_placement(placement, PIECE_I, ROT_1, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(4, placement[1].col);
  ck_assert_int_ne(GET_ROW(0) & placement[1].row, 0);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_ne(GET_ROW(2) & placement[2].row, 0);
  ck_assert_int_eq(4, placement[3].col);
  ck_assert_int_ne(GET_ROW(3) & placement[3].row, 0);

  priv_get_placement(placement, PIECE_I, ROT_2, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_ne(GET_ROW(1) & placement[1].row, 0);
  ck_assert_int_eq(3, placement[2].col);
  ck_assert_int_ne(GET_ROW(1) & placement[2].row, 0);
  ck_assert_int_eq(2, placement[3].col);
  ck_assert_int_ne(GET_ROW(1) & placement[3].row, 0);

  priv_get_placement(placement, PIECE_I, ROT_3, 4, GET_ROW(2));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(2) & placement[0].row, 0);
  ck_assert_int_eq(4, placement[1].col);
  ck_assert_int_ne(GET_ROW(3) & placement[1].row, 0);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_ne(GET_ROW(1) & placement[2].row, 0);
  ck_assert_int_eq(4, placement[3].col);
  ck_assert_int_ne(GET_ROW(0) & placement[3].row, 0);
}
END_TEST

START_TEST(test_get_placement_piece_o)
{
  TETROMINO_PLACEMENT placement[4];
  priv_get_placement(placement, PIECE_O, ROT_0, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_ne(GET_ROW(1) & placement[1].row, 0);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_ne(GET_ROW(2) & placement[2].row, 0);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_ne(GET_ROW(2) & placement[3].row, 0);

  priv_get_placement(placement, PIECE_O, ROT_1, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_ne(GET_ROW(1) & placement[1].row, 0);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_ne(GET_ROW(2) & placement[2].row, 0);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_ne(GET_ROW(2) & placement[3].row, 0);

  priv_get_placement(placement, PIECE_O, ROT_2, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_ne(GET_ROW(1) & placement[1].row, 0);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_ne(GET_ROW(2) & placement[2].row, 0);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_ne(GET_ROW(2) & placement[3].row, 0);

  priv_get_placement(placement, PIECE_O, ROT_3, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_ne(GET_ROW(1) & placement[1].row, 0);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_ne(GET_ROW(2) & placement[2].row, 0);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_ne(GET_ROW(2) & placement[3].row, 0);
}
END_TEST

START_TEST(test_get_placement_piece_j)
{
  TETROMINO_PLACEMENT placement[4];
  priv_get_placement(placement, PIECE_J, ROT_0, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(3, placement[1].col);
  ck_assert_int_ne(GET_ROW(1) & placement[1].row, 0);
  ck_assert_int_eq(5, placement[2].col);
  ck_assert_int_ne(GET_ROW(1) & placement[2].row, 0);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_ne(GET_ROW(2) & placement[3].row, 0);

  priv_get_placement(placement, PIECE_J, ROT_1, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(4, placement[1].col);
  ck_assert_int_ne(GET_ROW(0) & placement[1].row, 0);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_ne(GET_ROW(2) & placement[2].row, 0);
  ck_assert_int_eq(3, placement[3].col);
  ck_assert_int_ne(GET_ROW(2) & placement[3].row, 0);

  priv_get_placement(placement, PIECE_J, ROT_2, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_ne(GET_ROW(1) & placement[1].row, 0);
  ck_assert_int_eq(3, placement[2].col);
  ck_assert_int_ne(GET_ROW(1) & placement[2].row, 0);
  ck_assert_int_eq(3, placement[3].col);
  ck_assert_int_ne(GET_ROW(0) & placement[3].row, 0);

  priv_get_placement(placement, PIECE_J, ROT_3, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(4, placement[1].col);
  ck_assert_int_ne(GET_ROW(2) & placement[1].row, 0);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_ne(GET_ROW(0) & placement[2].row, 0);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_ne(GET_ROW(0) & placement[3].row, 0);
}
END_TEST

START_TEST(test_get_placement_piece_l)
{
  TETROMINO_PLACEMENT placement[PLACEMENT_COUNT];
  priv_get_placement(placement, PIECE_L, ROT_0, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_ne(GET_ROW(1) & placement[1].row, 0);
  ck_assert_int_eq(3, placement[2].col);
  ck_assert_int_ne(GET_ROW(1) & placement[2].row, 0);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_ne(GET_ROW(0) & placement[3].row, 0);

  priv_get_placement(placement, PIECE_L, ROT_1, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(4, placement[1].col);
  ck_assert_int_ne(GET_ROW(2) & placement[1].row, 0);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_ne(GET_ROW(0) & placement[2].row, 0);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_ne(GET_ROW(2) & placement[3].row, 0);

  priv_get_placement(placement, PIECE_L, ROT_2, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(3, placement[1].col);
  ck_assert_int_ne(GET_ROW(1) & placement[1].row, 0);
  ck_assert_int_eq(5, placement[2].col);
  ck_assert_int_ne(GET_ROW(1) & placement[2].row, 0);
  ck_assert_int_eq(3, placement[3].col);
  ck_assert_int_ne(GET_ROW(2) & placement[3].row, 0);

  priv_get_placement(placement, PIECE_L, ROT_3, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(4, placement[1].col);
  ck_assert_int_ne(GET_ROW(0) & placement[1].row, 0);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_ne(GET_ROW(2) & placement[2].row, 0);
  ck_assert_int_eq(3, placement[3].col);
  ck_assert_int_ne(GET_ROW(0) & placement[3].row, 0);
}
END_TEST

START_TEST(test_get_placement_piece_s)
{
  TETROMINO_PLACEMENT placement[PLACEMENT_COUNT];
  priv_get_placement(placement ,PIECE_S, ROT_0, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(4, placement[1].col);
  ck_assert_int_ne(GET_ROW(0) & placement[1].row, 0);
  ck_assert_int_eq(5, placement[2].col);
  ck_assert_int_ne(GET_ROW(0) & placement[2].row, 0);
  ck_assert_int_eq(3, placement[3].col);
  ck_assert_int_ne(GET_ROW(1) & placement[3].row, 0);

  priv_get_placement(placement, PIECE_S, ROT_1, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_ne(GET_ROW(1) & placement[1].row, 0);
  ck_assert_int_eq(5, placement[2].col);
  ck_assert_int_ne(GET_ROW(2) & placement[2].row, 0);
  ck_assert_int_eq(4, placement[3].col);
  ck_assert_int_ne(GET_ROW(0) & placement[3].row, 0);

  priv_get_placement(placement, PIECE_S, ROT_2, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(4, placement[1].col);
  ck_assert_int_ne(GET_ROW(2) & placement[1].row, 0);
  ck_assert_int_eq(3, placement[2].col);
  ck_assert_int_ne(GET_ROW(2) & placement[2].row, 0);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_ne(GET_ROW(1) & placement[3].row, 0);

  priv_get_placement(placement, PIECE_S, ROT_3, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(3, placement[1].col);
  ck_assert_int_ne(GET_ROW(1) & placement[1].row, 0);
  ck_assert_int_eq(3, placement[2].col);
  ck_assert_int_ne(GET_ROW(0) & placement[2].row, 0);
  ck_assert_int_eq(4, placement[3].col);
  ck_assert_int_ne(GET_ROW(2) & placement[3].row, 0);
}
END_TEST

START_TEST(test_get_placement_piece_z)
{
  TETROMINO_PLACEMENT placement[PLACEMENT_COUNT];
  priv_get_placement(placement, PIECE_Z, ROT_0, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(3, placement[1].col);
  ck_assert_int_ne(GET_ROW(0) & placement[1].row, 0);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_ne(GET_ROW(0) & placement[2].row, 0);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_ne(GET_ROW(1) & placement[3].row, 0);

  priv_get_placement(placement, PIECE_Z, ROT_1, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_ne(GET_ROW(0) & placement[1].row, 0);
  ck_assert_int_eq(5, placement[2].col);
  ck_assert_int_ne(GET_ROW(1) & placement[2].row, 0);
  ck_assert_int_eq(4, placement[3].col);
  ck_assert_int_ne(GET_ROW(2) & placement[3].row, 0);

  priv_get_placement(placement, PIECE_Z, ROT_2, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_ne(GET_ROW(2) & placement[1].row, 0);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_ne(GET_ROW(2) & placement[2].row, 0);
  ck_assert_int_eq(3, placement[3].col);
  ck_assert_int_ne(GET_ROW(1) & placement[3].row, 0);

  priv_get_placement(placement, PIECE_Z, ROT_3, 4, GET_ROW(1));
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_ne(GET_ROW(1) & placement[0].row, 0);
  ck_assert_int_eq(3, placement[1].col);
  ck_assert_int_ne(GET_ROW(2) & placement[1].row, 0);
  ck_assert_int_eq(3, placement[2].col);
  ck_assert_int_ne(GET_ROW(1) & placement[2].row, 0);
  ck_assert_int_eq(4, placement[3].col);
  ck_assert_int_ne(GET_ROW(0) & placement[3].row, 0);
}
END_TEST

START_TEST(test_place_piece_valid)
{
  TETROMINO_GAME game;
  new_game(&game);
  priv_place_piece(&game, PIECE_T, ROT_0, 4, GET_ROW(1));
  // should result in piece being placed
  ck_assert_int_eq(PIECE_T, game.current_piece);

  ck_assert_int_eq(4, game.curr_placement[0].col);
  ck_assert_int_eq(GET_ROW(1), game.curr_placement[0].row);
  ck_assert_int_eq(4, game.curr_placement[1].col);
  ck_assert_int_eq(GET_ROW(0), game.curr_placement[1].row);
  ck_assert_int_eq(3, game.curr_placement[2].col);
  ck_assert_int_eq(GET_ROW(1), game.curr_placement[2].row);
  ck_assert_int_eq(5, game.curr_placement[3].col);
  ck_assert_int_eq(GET_ROW(1), game.curr_placement[3].row);
}
END_TEST

START_TEST(test_placement_validity_bounds)
{
  TETROMINO_GAME game;
  new_game(&game);
  // valid placement, in-bounds and unobstructed
  ck_assert_int_eq(TRUE, priv_placement_is_valid(&game, PIECE_T, ROT_0, 4, GET_ROW(1)));

  // invalid placement, out-of-bounds on the top
  ck_assert_int_eq(FALSE, priv_placement_is_valid(&game, PIECE_T, ROT_0, 4, GET_ROW(0)));
  // invalid placement, out-of-bounds on the bottom
  ck_assert_int_eq(FALSE, priv_placement_is_valid(&game, PIECE_T, ROT_2, 4, GET_ROW(19)));
  // invalid placement, out-of-bounds on the left
  ck_assert_int_eq(FALSE, priv_placement_is_valid(&game, PIECE_T, ROT_2, 0, GET_ROW(1)));
  // invalid placement, out-of-bounds on the right
  ck_assert_int_eq(FALSE, priv_placement_is_valid(&game, PIECE_T, ROT_2, 9, GET_ROW(19)));
}
END_TEST

START_TEST(test_placement_validity_obstruction)
{
  TETROMINO_GAME game;
  new_game(&game);
  // valid placement, in-bounds and unobstructed
  ck_assert_int_eq(FALSE, priv_placement_is_valid(&game, PIECE_T, ROT_0, 4, GET_ROW(1)));
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
    tcase_add_test(tc_core, test_placement_validity_bounds);
    tcase_add_test(tc_core, test_placement_validity_obstruction);
    tcase_add_test(tc_core, test_get_placement_piece_t);
    tcase_add_test(tc_core, test_get_placement_piece_i);
    tcase_add_test(tc_core, test_get_placement_piece_o);
    tcase_add_test(tc_core, test_get_placement_piece_l);
    tcase_add_test(tc_core, test_get_placement_piece_j);
    tcase_add_test(tc_core, test_get_placement_piece_s);
    tcase_add_test(tc_core, test_get_placement_piece_z);
    suite_add_tcase(s, tc_core);

    return s;
}
