CC=gcc
CFLAGS=-Isrc/c

CPP=g++
CPPFLAGS=-Wall -g -Isrc/cpp

CFILE=c_prime_counter
CPPFILE=cpp_prime_counter

SRCDIR=src
CDIR=c
CPPDIR=cpp
CYTHONDIR=cython
PYTHONDIR=python
TESTDIR=tests
BINDIR=bin

.PHONY: clean build

all: c cpp cython python

$(CFILE): $(SRCDIR)/$(CDIR)/prime_counter.c build
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $<

c: $(CFILE)
	./$(BINDIR)/$(CFILE)

$(CPPFILE): $(SRCDIR)/$(CPPDIR)/prime_counter.cpp build
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $<

cpp: $(CPPFILE)
	./$(BINDIR)/$(CPPFILE)

cpp_tests: $(TESTDIR)/$(CPPDIR)/test_prime_counter.cpp build
	$(CPP) $(CPPFLAGS) -o $(BINDIR)/$@ $< $(SRCDIR)/$(CPPDIR)/prime_counter.h -DAMOUNT=200

cpp_run_test: cpp_tests
	./$(BINDIR)/$<

cython_build: $(SRCDIR)/$(CYTHONDIR)/cython_prime_counter.py
	cd $(SRCDIR)/$(CYTHONDIR)/ && py setup.py build_ext --inplace

cython: cython_build
	cd $(SRCDIR)/$(CYTHONDIR)/ && py ./cython_prime_counter.py

cython_test: $(TESTDIR)/$(CYTHONDIR)/test_prime_counter.py
	py -m unittest $<

python: $(SRCDIR)/$(PYTHONDIR)/prime_counter.py
	py $<

python_test: $(TESTDIR)/$(PYTHONDIR)/test_prime_counter.py
	py -m unittest $<

build: # create bin folder, ignore stdout and stderr, exit code 0
	@mkdir $(BINDIR)>NUL 2>&1 || @echo true >NUL

clean:
	rmdir $(BINDIR)