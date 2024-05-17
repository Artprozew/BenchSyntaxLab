#include <ctime>
#include <cstdio>
#include "prime_counter.h"


int main() {
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

    printf(
        "\nCounted %d primes in %d runs"
        " with an average of %.3f seconds per run\n",
        primes, RUNS, total_time / RUNS);
    return 0;
}