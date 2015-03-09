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
  reset_game(&game);
  // should result in game being reset
  ck_assert_int_eq(PIECE_NONE, game.curr_piece);
}
END_TEST
START_TEST(test_get_placement_piece_t)
{
  TETROMINO_PLACEMENT placement[PLACEMENT_COUNT];
  priv_get_placement(placement, PIECE_T, ROT_0, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(4, placement[1].col);
  ck_assert_int_eq(0, placement[1].row);
  ck_assert_int_eq(3, placement[2].col);
  ck_assert_int_eq(1, placement[2].row);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_eq(1, placement[3].row);

  priv_get_placement(placement, PIECE_T, ROT_1, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_eq(1, placement[1].row);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_eq(0, placement[2].row);
  ck_assert_int_eq(4, placement[3].col);
  ck_assert_int_eq(2, placement[3].row);

  priv_get_placement(placement, PIECE_T, ROT_2, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(4, placement[1].col);
  ck_assert_int_eq(2, placement[1].row);
  ck_assert_int_eq(5, placement[2].col);
  ck_assert_int_eq(1, placement[2].row);
  ck_assert_int_eq(3, placement[3].col);
  ck_assert_int_eq(1, placement[3].row);

  priv_get_placement(placement, PIECE_T, ROT_3, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(3, placement[1].col);
  ck_assert_int_eq(1, placement[1].row);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_eq(2, placement[2].row);
  ck_assert_int_eq(4, placement[3].col);
  ck_assert_int_eq(0, placement[3].row);
}
END_TEST

START_TEST(test_get_placement_piece_i)
{
  TETROMINO_PLACEMENT placement[4];
  priv_get_placement(placement, PIECE_I, ROT_0, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(3, placement[1].col);
  ck_assert_int_eq(1, placement[1].row);
  ck_assert_int_eq(5, placement[2].col);
  ck_assert_int_eq(1, placement[2].row);
  ck_assert_int_eq(6, placement[3].col);
  ck_assert_int_eq(1, placement[3].row);

  priv_get_placement(placement, PIECE_I, ROT_1, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(4, placement[1].col);
  ck_assert_int_eq(0, placement[1].row);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_eq(2, placement[2].row);
  ck_assert_int_eq(4, placement[3].col);
  ck_assert_int_eq(3, placement[3].row);

  priv_get_placement(placement, PIECE_I, ROT_2, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_eq(1, placement[1].row);
  ck_assert_int_eq(3, placement[2].col);
  ck_assert_int_eq(1, placement[2].row);
  ck_assert_int_eq(2, placement[3].col);
  ck_assert_int_eq(1, placement[3].row);

  priv_get_placement(placement, PIECE_I, ROT_3, 4, 2);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(2, placement[0].row);
  ck_assert_int_eq(4, placement[1].col);
  ck_assert_int_eq(3, placement[1].row);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_eq(1, placement[2].row);
  ck_assert_int_eq(4, placement[3].col);
  ck_assert_int_eq(0, placement[3].row);
}
END_TEST

START_TEST(test_get_placement_piece_o)
{
  TETROMINO_PLACEMENT placement[4];
  priv_get_placement(placement, PIECE_O, ROT_0, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_eq(1, placement[1].row);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_eq(2, placement[2].row);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_eq(2, placement[3].row);

  priv_get_placement(placement, PIECE_O, ROT_1, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_eq(1, placement[1].row);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_eq(2, placement[2].row);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_eq(2, placement[3].row);

  priv_get_placement(placement, PIECE_O, ROT_2, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_eq(1, placement[1].row);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_eq(2, placement[2].row);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_eq(2, placement[3].row);

  priv_get_placement(placement, PIECE_O, ROT_3, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_eq(1, placement[1].row);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_eq(2, placement[2].row);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_eq(2, placement[3].row);
}
END_TEST

START_TEST(test_get_placement_piece_j)
{
  TETROMINO_PLACEMENT placement[4];
  priv_get_placement(placement, PIECE_J, ROT_0, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(3, placement[1].col);
  ck_assert_int_eq(1, placement[1].row);
  ck_assert_int_eq(5, placement[2].col);
  ck_assert_int_eq(1, placement[2].row);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_eq(2, placement[3].row);

  priv_get_placement(placement, PIECE_J, ROT_1, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(4, placement[1].col);
  ck_assert_int_eq(0, placement[1].row);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_eq(2, placement[2].row);
  ck_assert_int_eq(3, placement[3].col);
  ck_assert_int_eq(2, placement[3].row);

  priv_get_placement(placement, PIECE_J, ROT_2, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_eq(1, placement[1].row);
  ck_assert_int_eq(3, placement[2].col);
  ck_assert_int_eq(1, placement[2].row);
  ck_assert_int_eq(3, placement[3].col);
  ck_assert_int_eq(0, placement[3].row);

  priv_get_placement(placement, PIECE_J, ROT_3, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(4, placement[1].col);
  ck_assert_int_eq(2, placement[1].row);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_eq(0, placement[2].row);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_eq(0, placement[3].row);
}
END_TEST

START_TEST(test_get_placement_piece_l)
{
  TETROMINO_PLACEMENT placement[PLACEMENT_COUNT];
  priv_get_placement(placement, PIECE_L, ROT_0, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_eq(1, placement[1].row);
  ck_assert_int_eq(3, placement[2].col);
  ck_assert_int_eq(1, placement[2].row);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_eq(0, placement[3].row);

  priv_get_placement(placement, PIECE_L, ROT_1, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(4, placement[1].col);
  ck_assert_int_eq(2, placement[1].row);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_eq(0, placement[2].row);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_eq(2, placement[3].row);

  priv_get_placement(placement, PIECE_L, ROT_2, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(3, placement[1].col);
  ck_assert_int_eq(1, placement[1].row);
  ck_assert_int_eq(5, placement[2].col);
  ck_assert_int_eq(1, placement[2].row);
  ck_assert_int_eq(3, placement[3].col);
  ck_assert_int_eq(2, placement[3].row);

  priv_get_placement(placement, PIECE_L, ROT_3, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(4, placement[1].col);
  ck_assert_int_eq(0, placement[1].row);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_eq(2, placement[2].row);
  ck_assert_int_eq(3, placement[3].col);
  ck_assert_int_eq(0, placement[3].row);
}
END_TEST

START_TEST(test_get_placement_piece_s)
{
  TETROMINO_PLACEMENT placement[PLACEMENT_COUNT];
  priv_get_placement(placement ,PIECE_S, ROT_0, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(4, placement[1].col);
  ck_assert_int_eq(0, placement[1].row);
  ck_assert_int_eq(5, placement[2].col);
  ck_assert_int_eq(0, placement[2].row);
  ck_assert_int_eq(3, placement[3].col);
  ck_assert_int_eq(1, placement[3].row);

  priv_get_placement(placement, PIECE_S, ROT_1, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_eq(1, placement[1].row);
  ck_assert_int_eq(5, placement[2].col);
  ck_assert_int_eq(2, placement[2].row);
  ck_assert_int_eq(4, placement[3].col);
  ck_assert_int_eq(0, placement[3].row);

  priv_get_placement(placement, PIECE_S, ROT_2, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(4, placement[1].col);
  ck_assert_int_eq(2, placement[1].row);
  ck_assert_int_eq(3, placement[2].col);
  ck_assert_int_eq(2, placement[2].row);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_eq(1, placement[3].row);

  priv_get_placement(placement, PIECE_S, ROT_3, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(3, placement[1].col);
  ck_assert_int_eq(1, placement[1].row);
  ck_assert_int_eq(3, placement[2].col);
  ck_assert_int_eq(0, placement[2].row);
  ck_assert_int_eq(4, placement[3].col);
  ck_assert_int_eq(2, placement[3].row);
}
END_TEST

START_TEST(test_get_placement_piece_z)
{
  TETROMINO_PLACEMENT placement[PLACEMENT_COUNT];
  priv_get_placement(placement, PIECE_Z, ROT_0, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(3, placement[1].col);
  ck_assert_int_eq(0, placement[1].row);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_eq(0, placement[2].row);
  ck_assert_int_eq(5, placement[3].col);
  ck_assert_int_eq(1, placement[3].row);

  priv_get_placement(placement, PIECE_Z, ROT_1, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_eq(0, placement[1].row);
  ck_assert_int_eq(5, placement[2].col);
  ck_assert_int_eq(1, placement[2].row);
  ck_assert_int_eq(4, placement[3].col);
  ck_assert_int_eq(2, placement[3].row);

  priv_get_placement(placement, PIECE_Z, ROT_2, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(5, placement[1].col);
  ck_assert_int_eq(2, placement[1].row);
  ck_assert_int_eq(4, placement[2].col);
  ck_assert_int_eq(2, placement[2].row);
  ck_assert_int_eq(3, placement[3].col);
  ck_assert_int_eq(1, placement[3].row);

  priv_get_placement(placement, PIECE_Z, ROT_3, 4, 1);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(1, placement[0].row);
  ck_assert_int_eq(3, placement[1].col);
  ck_assert_int_eq(2, placement[1].row);
  ck_assert_int_eq(3, placement[2].col);
  ck_assert_int_eq(1, placement[2].row);
  ck_assert_int_eq(4, placement[3].col);
  ck_assert_int_eq(0, placement[3].row);
}
END_TEST

START_TEST(test_place_piece_valid)
{
  TETROMINO_GAME game;
  reset_game(&game);
  priv_place_piece(&game, PIECE_T, ROT_0, 4, 1);
  // should result in piece being placed
  ck_assert_int_eq(PIECE_T, game.curr_piece);

  ck_assert_int_eq(4, game.curr_placement[0].col);
  ck_assert_int_eq(1, game.curr_placement[0].row);
  ck_assert_int_eq(4, game.curr_placement[1].col);
  ck_assert_int_eq(0, game.curr_placement[1].row);
  ck_assert_int_eq(3, game.curr_placement[2].col);
  ck_assert_int_eq(1, game.curr_placement[2].row);
  ck_assert_int_eq(5, game.curr_placement[3].col);
  ck_assert_int_eq(1, game.curr_placement[3].row);
}
END_TEST

START_TEST(test_placement_validity_bounds)
{
  TETROMINO_GAME game;
  reset_game(&game);
  // valid placement, in-bounds and unobstructed
  ck_assert_int_eq(TRUE, priv_placement_is_valid(&game, PIECE_T, ROT_0, 4, 1));

  // invalid placement, out-of-bounds on the top
  ck_assert_int_eq(FALSE, priv_placement_is_valid(&game, PIECE_T, ROT_0, 4, 0));
  // invalid placement, out-of-bounds on the bottom
  ck_assert_int_eq(FALSE, priv_placement_is_valid(&game, PIECE_T, ROT_2, 4, 19));
  // invalid placement, out-of-bounds on the left
  ck_assert_int_eq(FALSE, priv_placement_is_valid(&game, PIECE_T, ROT_2, 0, 1));
  // invalid placement, out-of-bounds on the right
  ck_assert_int_eq(FALSE, priv_placement_is_valid(&game, PIECE_T, ROT_2, 9, 19));
}
END_TEST

START_TEST(test_placement_validity_obstruction)
{
  TETROMINO_GAME game;
  reset_game(&game);

  // valid placement, in-bounds and unobstructed
  ck_assert_int_eq(TRUE, priv_placement_is_valid(&game, PIECE_T, ROT_0, 4, 1));

  // put an obstruction at 3,19
  game.field[3] |= GET_ROW(19);
  // invalid placement, is obstructed by item above
  ck_assert_int_eq(FALSE, priv_placement_is_valid(&game, PIECE_T, ROT_0, 4, 19));
}
END_TEST

START_TEST(test_get_random_piece)
{
  TETROMINO_PIECE piece = PIECE_NONE;
  piece = priv_get_random_piece();
  // as long as it isn't PIECE_NONE let's call it a day
  ck_assert_int_ne(PIECE_NONE, piece);
}
END_TEST

START_TEST(test_new_game_places_a_piece) {
  TETROMINO_GAME game;
  new_game(&game);
  ck_assert_int_ne(PIECE_NONE, game.curr_piece);
  ck_assert_int_eq(4, game.curr_placement[0].col);
  ck_assert_int_eq(0, game.curr_placement[0].row);
}
END_TEST

START_TEST(test_soft_drop_no_landing)
{
  TETROMINO_GAME game;
  ck_assert_int_eq(TRUE, FALSE);
}
END_TEST

START_TEST(test_initial_placement)
{
  TETROMINO_PLACEMENT placement[PLACEMENT_COUNT];
  uint8_t rot;

  priv_set_initial_placement_for(placement, PIECE_T, &rot);
  ck_assert_int_eq(ROT_2, rot);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(0, placement[0].row);

  priv_set_initial_placement_for(placement, PIECE_I, &rot);
  ck_assert_int_eq(ROT_0, rot);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(0, placement[0].row);

  priv_set_initial_placement_for(placement, PIECE_O, &rot);
  ck_assert_int_eq(ROT_0, rot);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(0, placement[0].row);

  priv_set_initial_placement_for(placement, PIECE_L, &rot);
  ck_assert_int_eq(ROT_2, rot);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(0, placement[0].row);

  priv_set_initial_placement_for(placement, PIECE_J, &rot);
  ck_assert_int_eq(ROT_0, rot);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(0, placement[0].row);

  priv_set_initial_placement_for(placement, PIECE_S, &rot);
  ck_assert_int_eq(ROT_2, rot);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(0, placement[0].row);

  priv_set_initial_placement_for(placement, PIECE_Z, &rot);
  ck_assert_int_eq(ROT_2, rot);
  ck_assert_int_eq(4, placement[0].col);
  ck_assert_int_eq(0, placement[0].row);
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
    tcase_add_test(tc_core, test_get_random_piece);
    tcase_add_test(tc_core, test_soft_drop_no_landing);
    tcase_add_test(tc_core, test_new_game_places_a_piece);
    tcase_add_test(tc_core, test_initial_placement);
    suite_add_tcase(s, tc_core);

    return s;
}
