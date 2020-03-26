# Chapter 3

## Data types and files

### Jesús Urtasun Elizari - University of Milan - 2019/20

**Subject:** Basics of C++: strings, cin, cout, input/output files, if and else.

Before starting we suggest to create a folder for Lesson 3 where you can save all files that will be created for the exercise
```bash
cd ~/           # go the home directory
mkdir Chapter03  # create the directory Chapter03 in home
cd Chapter03     # go inside Chapter03
```
Create a `makefile` with targets:
- `all`: compile all programs in this folder.
- `clean`: delete all programs created by `all`.

Example of `makefile`:

```makefile
all: program1

program1: exercise1.cc
  g++ -o program1 exercise1.cc
  # also: g++ -o $@ $<

clean:
  rm program1
```

in this way all programs will be compiled using the following command in the terminal:
```bash
$ make
```
while all programs will be eliminated by using the folloing one:
```bash
$ make clean
```

## Exercise 1 - Increasing / decreasing

Write a program in C++ where:

1. The program asks for the user to introduce an integer `n`.

2. Increase and decrease `n` by using operators `++` and `--`.

3. Compute the division and module (rest) of `n` by an `int r = 2;`.

5. Print the result on the screen.

## Exercise 2 - Even and ood numbers

Write a program that takes an integer and determines if it is an even or an odd number.
To do it use the module operator and the conditional statements (`if`, `else`).

## Exercise 3 - string and char

Write a C++ program in which:

1. Your name, surname and enrollment number are asked from terminal. Use variables of type `char name[20];` for the name,
`string` for the surname and `int` for the enrollment number. Implement the interface in the following way:
```text
Name     :
Surname  :
Number   :
```

2. Print with `cout` a row with the following syntax:
```bash
<surname>, <name> is registered with number: <number>.
```

## Exercise 4 - Output file

Modify the previous exercise in such a way that the final output comes written over a file called `result.dat`.

1. Create a copy of the previous exercise.
2. Implement with `fstream` the creation of an output file with the method `open()`,
followed by a success test with the method `good()`.
3. Write the content in screen and in the file.
4. Close the file with the method `close()`.

## Exercise 5 - Input file

Modify the previous exercise in such a way that the final output comes red from an input file called `myinput.dat`
with the following content:
```
<your name>
<your surname>
<your number>
```

1. Create a copy of the previous exercise.
2. Implement with `fstream` the oppening of the file `myinput.dat`.
3. Read the data from the file.
4. Close the file.
5. Print the result on screen and in the file `result.dat`.
