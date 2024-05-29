#ifndef PRIME_COUNTER_H
#define PRIME_COUNTER_H


#ifndef RUNS
    #define RUNS 10
#endif
#ifndef AMOUNT
    #define AMOUNT 20000
#endif
#ifndef PRIME_AMOUNT
    #define PRIME_AMOUNT true
    // true: gets AMOUNT of primes, instead of getting primes until AMOUNT
#endif

int primes[AMOUNT];


int prime_counter(void) {
    unsigned int primes_found = 0, number = 2;
    primes[0] = 2; // should probably start with a number

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