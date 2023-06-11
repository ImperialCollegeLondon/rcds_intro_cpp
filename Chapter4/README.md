# Chapter 4 - Arrays & vectors, functions

- Arrays and vectors.
- Functions
- Compiling functions and header files.

Before starting we suggest to create a folder for Chapter 4 where you can save all files that will be created for the exercise
```bash
cd ~/           # Go the home directory
mkdir Chapter4  # Create the directory Chapter4
cd Chapter4     # Go inside Chapter4
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

## Arrays

The use of arrays is a very powerful tool for both mathematical computations, and also for storing informationin an efficient way.
Basic algebra is deeply relying in vector and matrix manipulation, so today we will focus on how to deal with multidimensional objects in C++. 
Let's begin by editing the square numbers exercise of previos chapter, such that the square numbers are now stored in an array
* Join in the following syntax in a C++ file, and save it as `square_numbers.cpp`.
```c++
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    // Declare variables
    int n = 10;
    int square_numbers[10];

    // Iterate and store values in the array
    for(int i = 0; i < n; ++i) {
        square_numbers[i] = pow(i, 2);
    }

    // Print elements of the array
    for(int i = 0; i < n; ++i) {
        cout << square_numbers[i] << endl;
    }

    return 0;

}
```
* Note you can't `cout` an array
* We can also define arrays like this:
```c++
int main() {

    // Declare variables
    int n = 10;
    int square_numbers[10];
    int favourite_numbers[10] = {3, 1, -4, 1}; // Note we haven't defined them all.;

    // Iterate and store values in the array
    for(int i = 0; i < n; ++i) {
        square_numbers[i] = pow(i, 2);
    }

    // Print elements of the array
    cout << "Square numbers: " << endl;
    for(int i = 0; i < n; ++i) {
        cout << square_numbers[i] << endl;
    }

    // Print elements of the array
    cout << "Favourite numbers: " << endl;
    for(int i = 0; i < n; ++i) {
        cout << favourite_numbers[i] << endl;
    }        

    return 0;

}

```
* You can only use curly brackets like this at initialisation time.
* We can also declare:
    * `int favourite_numbers[] = {3,1,-4,1};`

* Multidimensional arrays work too
    * `int magic_square[3][3] = {{4,9,2},{3,5,7},{8,1,6}};`

## Functions

Until now, we have been always writing all our code inside the main function.
Writing functions that perform specific tasks allows us to do more complicated things in a sequential way.
* Join in the following syntax in a C++ file, and save it as `learning_functions.cpp`
```c++
#include <iostream>
using namespace std;

// Function computing sign
int function_sign(int n) {

    // Declare variables
    int sign;

    // Compute sign
    if(n > 0) {
        sign = 1;
    } else if(n == 0) {
        sign = 0;
    } else {
        sign = -1;
    }

    // Return sign
    return sign;

}

// Main function
int main() {

    // Declare variables
    int n;

    // Assign value
    cout << "Enter an integer number: ";
    cin >> n;

    // Call function
    cout << "Sign: " << function_sign(n) << endl;

    return 0;

}
```
* Global and local variables.
* Note: order is important. What happens if you define `function_sign` after `main`?

Your turn:
* Modify the code such that the n variables is stored from keyboard.
* Add an extra function to this file, `function_abs`, which returns the absolute value of an integer which is passed to it.
* Add an extra line to the `main` function so that it also displays the absolute value of *n*.

There is a way to define functions with `main` first: it's called 'forward declaration'. In general, this is better because it allows more flexible code.
* Modify the file to implement forward declaration.

```c++
#include <iostream>
using namespace std;

// Function computing sign
int function_sign(int n);
// Function computing absolute value
int function_abs(int n);

// Main function
int main() {

    // Declare variables
    int n;

    // Assign value
    cout << "Enter an integer number: ";
    cin >> n;

    // Call function
    cout << "Sign: " << function_sign(n) << endl;
    cout << "Absolute value: " << function_abs(n) << endl;

    return 0;

}

int function_sign(int n) {

    // Declare variables
    int sign;

    // Compute sign
    if(n > 0) {
        sign = 1;
    } else if(n == 0) {
        sign = 0;
    } else {
        sign = -1;
    }

    // Return sign
    return sign;

}

int function_abs(int n) {

    // Return absolute value
    return abs(n);

}
```

Now we're going to split our sign_function and absolute_value functions into separate files, and call them from our main file.
* Create two files, `function_sign.cpp` and  `function_abs.cpp` which implement the functions used before.
* Modify `learning_functions.cpp` such that it includes the function files, and contains just the main function.

`function_sign.cpp`:
```c++
#include <iostream> // Not strictly necessary
using namespace std;

int sign_function(int n)
{
    int sign;
    if(n>0){
        sign = 1;
    } else if(n==0){
        sign = 0;
    } else {
        sign = -1;
    }
    return sign;
}
```
`function_abs.cpp`:
```c++
#include <iostream> // Not strictly necessary
using namespace std;

int function_abs(int n) {

    // Return absolute value
    return abs(n);

}
```

* And now we compile like this:
```bash
c++ function_sign.cpp function_abs.cpp learning_functions.cpp -o learning_functions
```
* All these forward declarations can be tiresome, so we can put them in a header file and `#include` it:
`learning_functions.hpp`:
```c++
int function_sign(int n);
int function_abs(int n);
```
`learning_functions.cpp`:
```c++
#include <iostream>
#include "learning_functions.hpp"
using namespace std;

// Main function
int main() {

    // Declare variables
    int n;

    // Assign value
    cout << "Enter an integer number: ";
    cin >> n;

    // Call function
    cout << "Sign: " << function_sign(n) << endl;
    cout << "Absolute value: " << function_abs(n) << endl;

    return 0;

}
```

* Compile and run, remembering to include all files in the compile command:
```bash
c++ function_sign.cpp function_abs.cpp learning_functions.cpp -o learning_functions
```
* The header file is also a good place to put constants you want to have pre-defined in all of the files in your project.

Your turn:
* Add a function `is_absolute_value_less_than_1`. Put it in its own file, add its declaration to the header file, make the main file output `is_absolute_value_less_than_1(n)`,  compile, and check that it works.
* Harder version: Look up the data type for `true` and `false` in C++

## Exercise 1 - Multiplication table

Create a C++ code that prints a 10x10 multiplication table.

1. Set up a 10x10 array `product`.

2. Loop through all rows and columns, so that `product[row][col] = row * col;`

3. Loop through all rows and columns again, `cout` ing appropriately the elements of the table.

## Exercise 2 - Arrays and functions

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

## Exercise 3 - Conversion temperature

Recap of previous chapter. Write a C++ program where it is possible to convert a temperature from Celsius to Kelvin or Farenheit (using two-way selection `if` / `else`).

1. Ask the user for introducing on the terminal the temperature in Celsius using `cin`.

2. Save the value in a variable of type `double`.

3. Ask the user:
```text
Press 1 for conversion to Kelvin.
Press 2 for conversion to Fahrenheit.
Option chosen: <value_cin>
```

4. Save the user's choice in a variable of type `int`, and create the corresponding condition `if/else`.

5. Implement the formula for convertions:
```
T(Kelvin) = T(Celsius) + 273.15
T(Fahrenheit) = T(Celsius) * 9.0 / 5.0 + 32.0
```

6. Print the result in the following formato:
```text
T(Celsius) = <input_value> -> T(<option>) = <converted_value>
```

Verify the next conversions:
- 20 °C -> 68.0 °F
- 20 °C -> 293.15 K