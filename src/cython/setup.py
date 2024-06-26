from setuptools import Extension, setup
from Cython.Build import cythonize

setup(
    ext_modules=cythonize(Extension(
        "cython_prime_counter",
        sources=["cython_prime_counter.pyx"],
    ),
    language_level=3)
) # FIXME something ocasionally returns exit code -1073740791 ?