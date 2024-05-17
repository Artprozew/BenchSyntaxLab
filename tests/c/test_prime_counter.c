#include "../../src/c/prime_counter.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>

unsigned short int tested = 0;


void increase_tested(void) {
    tested++;
    printf(".");
}

void test_prime_counter_amount(void) {
    unsigned int found = prime_counter();
    assert(found >= 200 && "Amount of primes must be at least 200 to test!");
    increase_tested();
}

void test_prime_counter_small(void) {
    prime_counter();
    unsigned short int array[5] = {2, 3, 5, 7, 11};

    for (unsigned int i = 0; i < 5; i++) {
        assert(primes[i] == array[i] && "First 5 prime numbers doesn't match");
    }
    increase_tested();
}

void test_prime_counter_large(void) {
    prime_counter();
    unsigned short int array[46] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
        71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139,
        149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199
        };
    
    for (unsigned int i = 0; i < 46; i++) {
        assert(primes[i] == array[i] && "First 46 prime numbers doesn't match");
    }
    increase_tested();
}

void test_prime_counter_edge(void) {
    prime_counter();

    assert(primes[0] == 2 && "First prime number isn't equal to 2");
    increase_tested();
}

void test_prime_counter_last(void) {
    prime_counter();
    unsigned short int array[5] = {1187, 1193, 1201, 1213, 1217};
    unsigned short int index = 0;

    for (unsigned int i = 194; i < 199; i++) {
        assert(primes[i] == array[index] && "#200-195 prime numbers doesn't match");
        index++;
    }
    increase_tested();
}

int main() {
    printf("Running tests\n");

    clock_t interval = clock();
    test_prime_counter_amount();
    test_prime_counter_small();
    test_prime_counter_large();
    test_prime_counter_edge();
    test_prime_counter_last();
    interval = clock() - interval;

    printf("\n----------------------------------------------------------------------\n");
    printf("Ran %d tests in %.3fs\n", tested, (float) interval / CLOCKS_PER_SEC);
    printf("\nOK\n");
    return 0;
}
