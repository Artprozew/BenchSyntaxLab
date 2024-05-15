CC=gcc
CFLAGS=-Isrc/c
CPP=g++
CPPFLAGS=-Wall -g -Isrc/cpp

.PHONY: clean

c: src/c/prime_counter.c build
	$(CC) $(CFLAGS) -o build/$@ $<

c_run: c
	./build/c.exe

cpp: src/cpp/prime_counter.cpp build
	$(CPP) $(CPPFLAGS) -o build/$@ $<

cpp_run: cpp
	./build/cpp.exe

cpp_test: tests/cpp/test_prime_counter.cpp src/cpp/prime_counter.h build
	$(CPP) $(CPPFLAGS) -o build/$@ $< src/cpp/prime_counter.h -DAMOUNT=200

cython: src/cython/cython_prime_counter.py
	cd src/cython/ && py setup.py build_ext --inplace && py .\cython_prime_counter.py

cython_run: src/cython/cython_prime_counter.py
	cd src/cython/ && py .\cython_prime_counter.py

cython_test: tests\cython\test_prime_counter.py
	py -m unittest $<

python: src/python/prime_counter.py
	py $<

python_test: tests\python\test_prime_counter.py
	py -m unittest $<

build:
	@mkdir $@>NUL

clean:
	rd /s */output && rd /s */build