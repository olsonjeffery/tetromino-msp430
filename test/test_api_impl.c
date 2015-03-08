// copyright (c) 2015 jeff olson <olson.jeffery@gmail.com>
// this work is licensed under a creative commons attribution-noncommercial-sharealike 4.0 international license.
// see http://creativecommons.org/licenses/by-nc-sa/4.0/ for more information
//
// platform/api_impl.c -- impl of api.h for msp430 applications

#include "../src/api.h"
#include <time.h>
#include <stdlib.h>

void seed_rng() {
  srand(time(NULL));
}

int get_random_number() {
  return rand();
}
