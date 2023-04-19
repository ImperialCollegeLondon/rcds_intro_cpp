# Chapter 3

## Conditional statements, loops, file manipulation

**Subject:** Basic exercises for C++ programming.

Before starting we suggest to create a folder for Lesson 3 where you can save all files that will be created for the exercise
```bash
cd ~/           # Go the home directory
mkdir Chapter3  # Create the directory Chapter3
cd Chapter3     # Go inside Chapter3
```
Create a `makefile` with targets:
- `all`: compile all programs in this folder.
- `clean`: delete all programs created by `all`.

Example of `makefile`:

```makefile
all: program1

program1: exercise1.cc
  g++ exercise1.cc -o program1
  # also: g++ $< -o $@

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

Recap of previous chapter. Write a program in C++ where:

1. The program asks for the user to introduce an integer `n`.

2. Increase and decrease `n` by using operators `++` and `--`.

3. Compute the division and module (rest) of `n` by an `int r = 2;`.

5. Print the result on the screen.

## Exercise 2 - Conditionals - even and ood numbers

Write a program in C++ that produces a different output depending on the input variable

1. The program asks for the user to introduce an integer `n`.

2. Uses the module operator and the conditional statements (`if`, `else`) do determine if it is even or odd.

3. Print the result on the screen.

## Exercise 3 - Conditionals II - bartender

Write a program in C++ that produces a different output depending on the input variable

1. The program asks for the user to introduce an integer `n`.

2. Uses the module operator and the conditional statements (`if`, `else`) do determine if it is even or odd.

3. Print the result on the screen.

## Exercise 4 - Loops I - Hello World for, while, do/while

Write a C++ program that uses loops for printing a result in the terminal.

1. Create a `for` loop tat prints 5 times the same message:
```
Hello World for index = {i}
```
where `{i}` corresponds to the integer number that represents loop index.

2. Analogously, implement a `while` cycle where the following message is printed:
```
Hello World while index = {i}
```

3. Finally, implement a `do/while` loop with message:
```
Hello World do/while index = {i}
```

## Exercise 5 - Loops II - Square and cube numbers

Write a C++ program that uses loops for raising input to a given power.

1. Raise to the square.

2. Raise to the cube.

3. Collatz conjecture

## Exercise 6 - Output file

Modify the previous exercise in such a way that the final output comes written over a file called `result.dat`.

1. Create a copy of the previous exercise.
2. Implement with `fstream` the creation of an output file with the method `open()`,
followed by a success test with the method `good()`.
3. Write the content in screen and in the file.
4. Close the file with the method `close()`.

## Exercise 7 - Input file

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
