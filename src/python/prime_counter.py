import time
from typing import Final

RUNS: Final[int] = 10
AMOUNT: int = 20000 # Not really constant because the test module may modify it?
PRIME_AMOUNT: Final[bool] = True


def prime_counter() -> list[int]:
    primes: list[int] = []
    primes_found: int = 0
    number: int = 2

    while (primes_found if PRIME_AMOUNT else number) < AMOUNT:
        for i in primes:
            if number % i == 0:
                break
        else:
            primes.append(number)
            primes_found += 1

        number += 1

    return primes


def main() -> None:
    if AMOUNT <= 0 or RUNS <= 0:
        print("AMOUNT or RUNS must be greater than 0!")
        return
    
    print("Prime Counting Benchmark: Python")
    total_time: int = 0
    primes: list[int] = []

    for run in range(RUNS):
        interval: float = time.perf_counter()
        primes = prime_counter()
        interval = time.perf_counter() - interval
        total_time += interval
        print(f"- Test {run + 1} ran in: {interval:.3f} seconds")

    print(f"\nCounted {len(primes)}"
    f"{'' if PRIME_AMOUNT else f' up to {AMOUNT}'}"
    f" in {RUNS} with an average of {(total_time/ RUNS):.3f} seconds"
    )


if __name__ == "__main__":
    main()