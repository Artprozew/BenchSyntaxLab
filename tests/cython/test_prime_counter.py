from src.cython import cython_prime_counter
import unittest

class TestPrimeCounter(unittest.TestCase):

    def test_prime_counter_small(self):
        self.assertEqual(cython_prime_counter.test(6), [2, 3, 5, 7, 11, 13])

    def test_prime_counter_large(self):
        self.assertEqual(cython_prime_counter.test(46), [
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
            71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139,
            149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199
            ])
        
    def test_prime_counter_edge(self):
        self.assertEqual(cython_prime_counter.test(1), [2])
