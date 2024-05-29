import time

DEF RUNS = 10
DEF AMOUNT = 20000
DEF PRIME_AMOUNT = True


def prime_counter() -> tuple[list[int], int]:
    cdef int[AMOUNT] primes
    cdef unsigned int number = 2
    cdef unsigned int primes_found = 0
    primes[0] = 2

    while (primes_found if PRIME_AMOUNT else number) < AMOUNT:
        for i in range(primes_found):
            if number % primes[i] == 0:
                break
        else:
            primes[primes_found] = number
            primes_found += 1

        number += 1

    return primes, primes_found


def main() -> None:
    if AMOUNT <= 0 or RUNS <= 0:
        print("AMOUNT or RUNS must be greater than 0!")
        return
    
    print("Prime Counting Benchmark: Cython")
    cdef float total_time = 0, interval
    cdef int primes_found

    for run in range(RUNS):
        interval = time.perf_counter()
        _, primes_found = prime_counter()
        interval = time.perf_counter()  - interval
        total_time += interval
        print(f"- Test {run + 1} ran in: {interval:.3f} seconds")

    print(f"\nCounted {primes_found}"
    f"{'' if PRIME_AMOUNT else f' up to {AMOUNT}'}"
    f" in {RUNS} runs with an average of {(total_time/ RUNS):.3f} seconds"
    )


if __name__ == "__main__":
    main()