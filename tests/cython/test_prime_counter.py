from src.cython import cython_prime_counter
import unittest

class TestPrimeCounter(unittest.TestCase):

    def setUp(self):
        self.test_prime_counter_amount()

    def test_prime_counter_amount(self):
        primes, found = cython_prime_counter.prime_counter()
        self.assertGreaterEqual(len(primes), 200, "Amount of primes must be at least 200 to test!")
        self.assertGreaterEqual(found, 200, "Amount of primes must be at least 200 to test!")

    def test_prime_counter_small(self):
        primes, _ = cython_prime_counter.prime_counter()
        self.assertEqual(primes[:6], [2, 3, 5, 7, 11, 13])

    def test_prime_counter_large(self):
        primes, _ = cython_prime_counter.prime_counter()
        self.assertEqual(primes[:46], [
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
            71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139,
            149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199
            ])

    def test_prime_counter_edge(self):
        primes, _ = cython_prime_counter.prime_counter()
        self.assertEqual(primes[0], 2)

    def test_prime_counter_last(self):
        primes, _ = cython_prime_counter.prime_counter()
        self.assertEqual(primes[194:199], [1187, 1193, 1201, 1213, 1217])
