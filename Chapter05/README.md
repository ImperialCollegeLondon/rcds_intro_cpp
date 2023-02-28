# Chapter 5

## Loops

### Jesús Urtasun Elizari - University of Milan - 2019/20

**Subject:** Base exercises in C++: for loop, while, do/while.

Before starting we suggest to create a folder for Lesson 4 where you can save all files that will be created for the exercise
```bash
cd ~/
mkdir Chapter05
cd Chapter05
```
Create a `makefile` to compile all exercises

## Exercise 1 - Hello World for, while e do/while

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

## Exercise 2 - Compute mean value (input from terminal)

Write a C++ program that computes the mean value of a list of numbers using a `for` loop.

1. Ask the user how many numbers to introduce. Save the table of values in a variable `int n`.

2. Build a `for` loop that asks the user to introduce `n` numbers of type `double`.

3. Create a variable `double sum = 0;` and increment it inside the for loop using the values introduced by the user.

4. Create a variable that contains the mean.

5. Print the result on screen.

## Esercizio 3 - Counting odd and even numbers

Write a C++ program that computes the total number of odds and evens in a list using a `for` or `while` loop.

1. Create a `for` or `while` loop that asks the user to intriduce integer numbers. To finish use the condition CRTL+D (`cin.eof()`).

2. For every introduced number determine if it is odd or even using the if/else condition.
Use counters of type `int` for saving the total number of odds and evens introduced by the user.

3. Print the result on screen.

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
