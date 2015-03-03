// Copyright (c) 2015 Jeff Olson <olson.jeffery@gmail.com>
// This work is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
// See http://creativecommons.org/licenses/by-nc-sa/4.0/ for more information
//
// api.h - API needed in game-agnostic code; impls provided by both platform and test codebases

// api for rng stuff needed within the tetromino module
void seed_rng();
int get_random_number();

