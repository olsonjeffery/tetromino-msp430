// copyright (c) 2015 jeff olson <olson.jeffery@gmail.com>
// this work is licensed under a creative commons attribution-noncommercial-sharealike 4.0 international license.
// see http://creativecommons.org/licenses/by-nc-sa/4.0/ for more information
//
// platform/api_impl.c -- impl of api.h for msp430 applications

#include "../api.h"
#include "rand.h"

static unsigned int SEED = 0;

void seed_rng() {
  SEED = rand();
}

int get_random_number() {
  SEED = prand(SEED);
  return SEED;
}
