#ifndef __RAND_H
#define __RAND_H

#include <msp430.h>

// So my msp430f5229 has two timers, so the flags used
// in rand.c aren't right, have to define them here..
#define TACCTL0 TA1CCTL0
#define TACTL TA1CTL
#define TACCR0 TA1CCR0

/* LCG constants */
#define M 49381                               // Multiplier
#define I 8643                                // Increment

unsigned int rand();
unsigned int prand(unsigned int state);

#endif /* __RAND_H */
