#include <ctime>
#include <cstdio>
#include "prime_counter.h"

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