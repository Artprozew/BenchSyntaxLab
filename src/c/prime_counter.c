#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "prime_counter.h"

#define RUNS 4
#define AMOUNT 40000

#define NOT_DEBUGGING
int primes[AMOUNT];

#ifdef NOT_DEBUGGING
int main() {
    clock_t tests[RUNS];
    int array_size = 0;

    for (int i = 0; i < RUNS; i++) {
        clock_t timer = clock();
        counter();
        timer = clock() - timer;
        tests[i] = timer;
        array_size++;
    }

    float total = 0;
    for (int i = 0; i < RUNS; i++) {
        total += (double)tests[i] / CLOCKS_PER_SEC;
        printf("Runs in: %.3f seconds\n", (float)tests[i] / CLOCKS_PER_SEC);
    }

    double avg = total / array_size;
    printf("Took: %d tests. Average: %.3f seconds", RUNS, avg);
    return 0;
}
#endif

int counter(void) {
    int found = 0;
    int number = 2;
    int array_size = 0;

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
    
    printf("%d\n", primes[0]);
    return array_size;
}