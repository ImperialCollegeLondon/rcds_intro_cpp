# Chapter 7

### Jesús Urtasun Elizari - University of Milan - 2019/20

**Subject:** Base exercies in C++: pointers and functions.

Before starting we suggest to create a folder for Lesson 4 where you can save all files that will be created for the exercise
```bash
cd ~/
mkdir Chapter07
cd Chapter07
```
Create a `makefile` to compile all exercises

## Exercise 1 - Hello World pointers

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

## Exercise 2 - Hello world funzions

Write a C++ program where functions are used

1. Create a stack array `int v[10] = {9,2,1,3,4,7,0,11,20,5};`.

2. Write a function `print_array` of type `void` that takes as argument an int array and its respective dimension, and prints the content on screen. Test on the `main` the call of `print_array` with `v`.

3. Write a function `max_array` of type `int` that obtains the maximum value present on an array.
Test the implementation `v`, printing on the main its maximum value.

4. Write a function `min_array` of type `int` that obtians the minumum value present on an array.
Test the implementation `v`, printing on the main its minimum vlaue.

5. Write a function `min_max_array` of type `void` that obtains the max an and also replaces them using two arguments `min` e `max` 
of type `int` passed by reference.

6. Write a function `sort_array` of type `void` that sorts out in increasing mode an array ot type `int`. Test the function with the array `v`.

## Exercise 3 - Numerical integration

Write a C++ program that computes the numerical integral of an analytical function usin the trapezoidal rule
```
 /b
 |  f(x) dx =  d * Sum_{i=0,n-1} ( f(a + i * d) + f(a + (i + 1) * d) ) / 2
 /a
```
where `d = (b-a)/n`.

1. Implement a function `gauss` of type `double` that replaces tha value of a normalized Gaussian centered in `mu = 0` and  `sigma = 1`:
```
gauss(x) = 1/(sqrt(2*pi)) * exp(-x*x/2)
```

2. Implement a function `integrate_gaussian` of type `double` that takes arguments `a`, `b` and `n` (steps),
and computes the integral of `gauss` between `a` and `b`.

3. Test the function for `(a,b) = (-10, 10)` and `(a,b) = (-1,1)`, for each configuration change `n = [10,100]`.

## Exercise 4 - Selecting points

Write a C++ program that dteremines if a point in cartesian coordinates `(x,y)` is inside of a circle centered in `c = (1, 1)` and radius `r = 1`.

0. Create variables of type `const double` and save the properties of the circle mentioned above.

1. Build a function `distance` of type `double` that computes the distance between 2 coordinates, `x` and `y` of type double and the center of circle.
For doing it, pass as argument the coordinates to test and te center of the circle.
Hint: use the Pythagoras theorem.

2. Implement a function `check_circle` of type `void` that takes as arguments the 4 precedent coordinates precedenti and the radius of the circle
`(x, y, x_c, y_c, r)` and a variable of type `status` of type `bool` by reference. Compute here: the call of the function `distance` followed by check if the point is inside the circle. Save in `status` the value `true` or `false`.

3. Implement an infinite loop where pairs of points `(x,y)` come introduced by terminal. Applay the discriminator for each pair.

3. Test the next pairs of points:
```
(x,y) = (1.1, 0.7)  ->  true
(x,y) = (2.1, 0.7)  ->  false
(x,y) = (0.5, 0.3)  ->  true
(x,y) = (1.0, 1.0)  ->  true
(x,y) = (0.1, 0.1)  ->  false
```

## Exercise 5 - Scalar product, norm, transposed matrix

Write a C++ program that computes the following algebra operations.

1. Create a 2 1D arrays of type `double` with `v = {1, 2, 3, 4, 5}, w = {10, 2, 4, 3, 2}`. 
Create a 2D array of type `double` with `M = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}`.

2. Implement a function `scalar` of type `double` that computes the scalar product between 2 arrays.
Test the function with `v` and `w` and print the result on screen.

3. Implement a function `norm` of type `double` that computes the norm of an array using the function `scalar`. Test the implementation of`v` and print the result on screen.

4. Implement a function `change` of type `void` that changes the values between 2 objects by reference.
Apply this function to `M` (e.g. compute the transpose) and print the result on screen.
