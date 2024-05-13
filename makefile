CC=gcc
CFLAGS=-Isrc/c
CPP=g++
CPPFLAGS=-Wall -g -Isrc/cpp

all: c cpp

c: tests/c/test_prime_counter.c src/c/prime_counter.c src/c/prime_counter.h
	$(CC) $(CFLAGS) -o $@ $< src/c/prime_counter.c

cpp: src/cpp/prime_counter.cpp
	$(CPP) $(CPPFLAGS) -o $@ $^

cpp_test: tests/cpp/test_prime_counter.cpp src/cpp/prime_counter.h
	$(CPP) $(CPPFLAGS) -o $@ $^

cython: src/cython/cython_test_call.py
	cd src/cython/ && py setup.py build_ext --inplace && py .\cython_test_call.py
	
cython_run: src/cython/cython_test_call.py
	cd src/cython/ && py .\cython_test_call.py

clean:
	rd /s */output && rd /s */build