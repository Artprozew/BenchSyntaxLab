#include <ctime>
#include <cstdio>
#include "prime_counter.h"


int main() {
    if (AMOUNT <= 0 || RUNS <= 0) {
        printf("AMOUNT or RUNS must be greater than 0!\n");
        return 1;
    }

    printf("Prime Counting Benchmark\n");
    float total_time = 0;
    unsigned int primes = 0;

    for (unsigned int i = 0; i < RUNS; i++) {
        clock_t interval = clock();
        primes = prime_counter();
        interval = clock() - interval;

        float interval_seconds = (float) interval / CLOCKS_PER_SEC;
        total_time += interval_seconds;
        printf("- Test %d ran in: %.3f seconds\n", i + 1, interval_seconds);
    }

    char formatted_str[20];
    snprintf(formatted_str, sizeof(formatted_str), "up to %d ", AMOUNT);

    printf(
        "\nCounted %d primes %sin %d runs"
        " with an average of %.3f seconds per run\n",
        primes, PRIME_AMOUNT ? "" : formatted_str, RUNS, total_time / RUNS);
    return 0;
}