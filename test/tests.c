// Copyright (c) 2015 Jeff Olson <olson.jeffery@gmail.com>
// This work is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
// See http://creativecommons.org/licenses/by-nc-sa/4.0/ for more information
//
// tests.c -- unit tests
#include <stdlib.h>
#include <check.h>

#include "../src/base/tetromino.h"

START_TEST(test_tetromino_reset_game)
{
  TETROMINO_GAME game;
  reset_game(&game);
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
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = tetromino_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
