# This makefile contains the instructions for compiling all exercises
# Some advanced functions are used, such as definition of the variables, CC, and references $@ and $<.

# Cpp compiler
CC=g++

# All executables to be generated
all: program1 program2 program3 program4 program5

# Instructions for compiling
program1: exercise1.cpp
	$(CC) -o $@ $<

program2: exercise2.cpp
	$(CC) -o $@ $<

program3: exercise3.cpp
	$(CC) -o $@ $<

program4: exercise4.cpp
	$(CC) -o $@ $<

program5: exercise5.cpp
	$(CC) -o $@ $<

# program2 is also run automatically
all: program5
	./program5

clean:
	rm program1
	rm program2
	rm program3
	rm program4
	rm program5
