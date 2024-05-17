CC = gcc
CFLAGS = -Wall -g
ALL_CFLAGS = -I$(src_dir)/$(c_dir) $(CFLAGS)

CPP = g++
CPPFLAGS = -Wall -g
ALL_CPPFLAGS = -I$(src_dir)/$(cpp_dir) $(CPPFLAGS)

c_file = c-prime-counter
cpp_file = cpp-prime-counter

src_dir = src
c_dir = c
cpp_dir = cpp
cython_dir = cython
python_dir = python
test_dir = tests
bin_dir = bin

supress_out = >NUL 2>&1
return_true = || echo true
supress_all = $(supress_out) $(return_true) $(supress_out)

.PHONY: clean build

all: c cpp cython python

$(c_file): $(src_dir)/$(c_dir)/prime_counter.c build
	$(CC) $(ALL_CFLAGS) -o $(bin_dir)/$@ $<

c: $(c_file)
	$(bin_dir)/$(c_file)

c-build-tests: $(test_dir)/$(c_dir)/test_prime_counter.c build
	$(CC) $(ALL_CFLAGS) -o $(bin_dir)/$@ $< $(src_dir)/$(c_dir)/prime_counter.h -DAMOUNT=400

c-tests: c-build-tests
	$(bin_dir)/$<

$(cpp_file): $(src_dir)/$(cpp_dir)/prime_counter.cpp build
	$(CPP) $(ALL_CPPFLAGS) -o $(bin_dir)/$@ $<

cpp: $(cpp_file)
	$(bin_dir)/$(cpp_file)

cpp-build-tests: $(test_dir)/$(cpp_dir)/test_prime_counter.cpp build
	$(CPP) $(ALL_CPPFLAGS) -o $(bin_dir)/$@ $< $(src_dir)/$(cpp_dir)/prime_counter.h -DAMOUNT=400

cpp-tests: cpp-build-tests
	$(bin_dir)/$<

cython-build: $(src_dir)/$(cython_dir)
	cd $< && \
	python setup.py build_ext --inplace

cython: $(src_dir)/$(cython_dir)/cython_prime_counter.py cython-build
	python $<

cython-tests: $(test_dir)/$(cython_dir)/test_prime_counter.py cython-build
	python -m unittest $<

python: $(src_dir)/$(python_dir)/prime_counter.py
	python $<

python-tests: $(test_dir)/$(python_dir)/test_prime_counter.py
	python -m unittest $<

build:
	mkdir $(bin_dir)$(supress_all)

clean: # needs return_true so the other recipes will run, but also needs to cd every line
	rmdir "$(bin_dir)" /s /q $(supress_all)
	rmdir "$(src_dir)/$(cython_dir)/build" /s /q $(supress_all)
	cd $(src_dir)/$(cython_dir) && \
	del /f /q *.pyd $(supress_all)
	cd $(src_dir)/$(cython_dir) && \
	del /f /q *.c $(supress_all)

.SILENT: build clean