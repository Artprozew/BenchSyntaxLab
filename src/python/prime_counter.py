import time

def test(amount):
    primes = []
    found = 0
    number = 2

    while found < amount:
        for i in primes:
            if number % i == 0:
                break
        else:
            primes.append(number)
            found += 1

        number += 1

    return primes

def main():
    tests = []
    runs = 3
    amount = 20000

    for run in range(runs):
        timer = time.perf_counter()
        test(amount)
        timer = time.perf_counter()  - timer
        tests.append(timer)

    total = 0
    for run in tests:
        total += run
        print(f"Runs in: {run:.3f} seconds")

    avg = total / len(tests)
    print(f"Took: {runs} tests. Average: {avg:.3f} seconds")

if __name__ == "__main__":
    main()