// copyright (c) 2015 jeff olson <olson.jeffery@gmail.com>
// this work is licensed under a creative commons attribution-noncommercial-sharealike 4.0 international license.
// see http://creativecommons.org/licenses/by-nc-sa/4.0/ for more information
//
// tests.c -- unit tests
#include <stdlib.h>

#include "setup.h"

#include "../src/base/tetromino.h"

START_TEST(test_tetromino_reset_game)
{
  TETROMINO_GAME game;
  reset_game(&game);
  ck_assert_int_eq(PIECE_NONE, game.current_piece);
}
END_TEST

START_TEST(test_tetromino_place_piece)
{
  TETROMINO_GAME game;
  reset_game(&game);
  place_piece(&game, PIECE_T, ROW01, COL4);
  ck_assert_int_eq(PIECE_T, game.current_piece);
}
END_TEST

Suite * tetromino_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("tetromino");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_tetromino_reset_game);
    tcase_add_test(tc_core, test_tetromino_place_piece);
    suite_add_tcase(s, tc_core);

    return s;
}
