# This makefile contains the instructions for compiling all exercises
# Some advanced functions are used, such as definition of the variables, CC, and references $@ and $<.

# C++ compiler
CC=g++
FLAGS=-std=c++17 -Wall
# All programs to be generated
all: program1 program2 program3 pointer_array

program1: exercise1.cpp
	$(CC) -o $@ $<

program2: exercise2.cpp
	$(CC) -o $@ $<

program3: exercise3.cpp
	$(CC) -o $@ $<

pointer_array: pointer_array.cpp
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -rf program1
	rm -rf program2
	rm -rf program3
	rm -rf pointer_array