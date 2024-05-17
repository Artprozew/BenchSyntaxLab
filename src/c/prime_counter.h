#ifndef PRIME_COUNTER_H
#define PRIME_COUNTER_H

#include <stdbool.h>

#ifndef RUNS
    #define RUNS 3
#endif
#ifndef AMOUNT
    #define AMOUNT 0
#endif
#ifndef PRIME_AMOUNT
    #define PRIME_AMOUNT true
#endif

int primes[AMOUNT];


int prime_counter(void) {
    unsigned int primes_found = 0, number = 2;
    primes[0] = 2;

    while (((PRIME_AMOUNT) ? primes_found : number) < AMOUNT) {
        bool flag_break = false;
        
        for (unsigned i = 0; i < primes_found; i++) {
            if (number % primes[i] == 0) {
                flag_break = true;
                break;
            }
        }

        if (!flag_break) {
            primes[primes_found++] = number;
        }

        number++;
    }
    
    return primes_found;
}

#endif