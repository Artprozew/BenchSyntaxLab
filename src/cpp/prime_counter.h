#ifndef PRIME_COUNTER_H
#define PRIME_COUNTER_H

#include <stdio.h>

#define RUNS 3
#ifndef AMOUNT
#define AMOUNT 20000
#endif

int primes[AMOUNT];


int counter(void) {
    int found = 0;
    int number = 2;
    int array_size = 0;
    primes[0] = 2; // should start with a number

    while (found < AMOUNT) {
        bool flag_break = false;
        for (int i = 0; i < array_size; i++) {
            if (number % primes[i] == 0) {
                flag_break = true;
                break;
            }
        }

        if (!flag_break) {
            primes[found] = number;
            found++;
            array_size++;
            flag_break = false;
        }

        number++;
    }
    
    return array_size;
}

#endif