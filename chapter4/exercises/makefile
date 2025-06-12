# This makefile contains the instructions for compiling all exercises
# Some advanced functions are used, such as definition of the variables, CC, and references $@ and $<.

# C++ compiler
CC=g++
FLAGS=-std=c++17 -Wall

# All programs to be generated
all: program1 program2 program3 program4 vectors_and_functions

program1: exercise1.cpp
	$(CC) $< -o $@

program2: exercise2.cpp
	$(CC) $< -o $@

program3: exercise3.cpp
	$(CC) $< -o $@

program4: exercise4.cpp
	$(CC) $< -o $@

vectors_and_functions: vectors_and_functions.cpp
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -rf program1
	rm -rf program2
	rm -rf program3
	rm -rf program4
	rm -rf vectors_and_functions