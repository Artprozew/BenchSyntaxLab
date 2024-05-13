//#define NOT_DEBUGGING
#include "../../src/c/prime_counter.c"
#include <assert.h>
#include <stdio.h>


void test_prime_counter_small() {
    int size = counter();
    printf("%d\n", size);
    int array[200] = {2, 5, 7, 10, 11};
    for (int i = 0; i < 200; i++) {
        assert(primes[i] == array[i] && "aquilo n e igual a aquilo");
    }
}

void test_prime_counter_large() {
    int size = counter();
    printf("%d\n", size);
    int array[200] = {25, 56, 87, 100};
    for (int i = 0; i < 200; i++) {
        assert(primes[i] == array[i] && "n e igual a aquilo");
    }
}

void test_prime_counter_edge() {
    int size = counter();
    printf("%d\n", size);
    int array[200] = {25, 56, 87, 100};
    for (int i = 0; i < 200; i++) {
        assert(primes[i] == array[i] && "n e igual a aquilo");
    }
}

int main() {
    test_prime_counter_small();
    test_prime_counter_large();
    test_prime_counter_edge();
    return 0;
}
