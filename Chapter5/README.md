# Chapter 5

## Pointers, classes and OOP

**Subject:** Basic exercises for C++ programming.

Before starting we suggest to create a folder for Lesson 5 where you can save all files that will be created for the exercise
```bash
cd ~/           # Go the home directory
mkdir Chapter5  # Create the directory Chapter5
cd Chapter5     # Go inside Chapter5
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

## Exercise 1 - Pointers

Write a C++ program where pointers are used

1. Create a variable `x` in a pointer `*p` of type `double` initialized with `5.5` and `NULL` respectively.

2. Print on screen:
   - the value in memory of the variables `x`.
   - the memory address of the variable `x`.
   - the memory address pointed by the pointer `p`.
   - the memory address of the pointer `p`.

3. Assign to the pointer `p` the memory address of the variable `x`, and print on terminal the address and print
on screen the address pointed by `p` and its value.

4. Ask on terminal a number of type `double` and assign it to the value pointed by `p`. Control that the value `x` has been modified.

5. Create a dynamic array of type `double` and dimension 10, print the memory address for all components of the array. Print the memory
address of all components of the array. Verify that the addresses are separated among each other with the number of bytes of type double `double`. (Remember to delete the array at the end of the main function)

## Exercise 2 - Pointer arrays

## Exercise 2 - Compute mean value (input from terminal)

Write a C++ program that computes the mean value of a list of numbers using a `for` loop.

1. Ask the user how many numbers to introduce. Save the table of values in a variable `int n`.

2. Build a `for` loop that asks the user to introduce `n` numbers of type `double`.

3. Create a variable `double sum = 0;` and increment it inside the for loop using the values introduced by the user.

4. Create a variable that contains the mean.

5. Print the result on screen.

## Exercise 3 - Counting odd and even numbers



## Exercise 4 - Compute mean value (input from file)

1. Download the datafile copying the next command and running in the terminal:
```bash
wget https://raw.githubusercontent.com/JesusUrtasun/CppCourse/master/Chapter05/data.dat
```
The data contains 1000 numbers corresponding to physical measurements of the acceleration of gravity `g`.

2. Read all numbers from the file using an infinite `for`, controlled by the condition `eof`.

3. Save a variable `double sum = 0.0;` The incrementing sum of the numbers.

4. Compute the mean and print it on screen, verify that the value is near `g=9.7803184`.

## Exercise 5 - Compute the Fibonacci series

Write a C++ program that computes the first `n` elements of the Fbonacci series.

An example of the the first 13 elements of the series is below:
```
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144
```
where the first 2 elements ara always 0 and 1, and then the succesive ones are the sume of the 2 precedent ones.

1. Ask the user how many elements for the Fibonacci series he wants to compute. Save this information in a vraible `int n`.

2. Implement a `for` loop where all elements come computed and printed.
