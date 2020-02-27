# This makefile contains the instructions for compiling all exercises
# Some advanced functions are used, such as definition of the variables, CC, and references $@ and $<.

# Cpp compiler
CC=g++

# All executables to be generated
all: program1 program2 program4 program5 program6 program7

# Exercise 3
program1: exercise1.cc
	$(CC) -o $@ $<

program2: exercise2.cc
	$(CC) -o $@ $<

# program2 is also run automatically
all: program2
	./program2

program4: exercise4.cc
	$(CC) -o $@ $<

program5: exercise5.cc
	$(CC) -o $@ $<

program6: exercise6.cc
	$(CC) -o $@ $<

program7: exercise7.cc
	$(CC) -o $@ $<

clean:
	rm program1
	rm program2
	rm program4
	rm program5
	rm program6
	rm program7
