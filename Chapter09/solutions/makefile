# This makefile contains the instructions for compiling all exercises
# Some advanced functions are used, such as definition of the variables, CC, and references $@ and $<.

# C++ compiler
CC=g++

all: program4

program4: exercise4.cc
	$(CC) -o $@ $< `root-config --cflags` `root-config --libs`

clean:
	rm -f program4
	rm -f *.png
