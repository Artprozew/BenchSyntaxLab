import time

def test():
    cdef int[10000] primes
    cdef int found = 0
    cdef int number = 2
    cdef int array_size = 0

    while found < 10000:
        for i in range(array_size):
            if number % primes[i] == 0:
                break

        else:
            primes[found] = number
            array_size += 1
            found += 1

        number += 1

    return primes

def main():
    cdef float[3] tests
    cdef int array_size = 0
    cdef int runs = 4
    cdef float timer

    for run in range(runs):
        timer = time.perf_counter()
        test()
        timer = time.perf_counter()  - timer
        tests[array_size] = timer
        array_size += 1

    cdef double total = 0
    for run in tests:
        total += run
        print(f"Runs in: {run:.3f} seconds")

    cdef float avg = total / len(tests)
    print(f"Took: {runs} tests. Average: {avg:.3f} seconds")

if __name__ == "__main__":
    main()