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

In today;'s chapter in we will discuss arrays and vectors, as a way of storing and manipulating high dimensional data.
* Edit the `square_numbers.cpp` file to store the square numbers in a 10-dimensional array
```c++
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    // Declare variables
    int n = 10;
    int square_numbers[10];

    // Iterate storing squares in array
    for (int i = 0; i < n; ++i) {
        square_numbers[i] = pow(i, 2);
    }
    for (int i = 0; i < n; ++i) {
        cout << square_numbers[i] << endl;
    }

    return 0;
}
```
* Note you can't `cout` an array. The way to do it would be to print the values element-wise
* We can also define arrays with explicit values as follows:
```c++
int main() {

    // Declare and initialize
    int n = 10;
    int square_numbers[10];
    int favourite_numbers[10] = {3, 1, -4, 1}; // Note we haven't defined them all

    // Iterate storing squares in array
    for (int i = 0; i < n; ++i) {
        square_numbers[i] = pow(i, 2);
    }

    // Iterate printing elements
    for (int i = 0; i < n; ++i) {
        cout << square_numbers[i] << endl;
    }

    // Iterate printing elements
    for (int i = 0; i < n; ++i) {
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

## Functions - I

Writing functions allows us to split computations and perform complicated tasks.
* Join in the following syntax in a C++ file, and save it as`learning_functions.cpp`
```c++
#include <iostream>
using namespace std;

// Function returning the sign of an integer
int function_sign(int n) {

    // Declare variables
    int sign;

    if (n > 0) {
        sign = 1;
    } else if (n == 0) {
        sign = 0;
    } else {
        sign = -1;
    }

    return sign;

}

// Main function
int main() {

    // Declare variables
    int n;
    n = 3;

    // Call sign function
    cout << function_sign(n) << endl;

    return 0;

}
```
* Global and local variables.
* Note: order is important. What happens if you define `function_sign` after `main`?

Your turn:

* Add an extra function to this file, `function_abs`, which returns the absolute value of an integer which is passed to it.
* Add an extra line to the `main` function so that it also displays the absolute value of *n*.

## Functions - II

* A code with many functions can easy become lengthy and difficult to read.
Hence, there is a standard way of organizing functions with `main` first: it's called 'forward declaration'.
* In general, this is better because it allows more flexible code.

```c++
#include <iostream>
using namespace std;

// Function declaration
int function_sign(int n);

// Main function
int main() {

    // Declare variables
    int n;
    n = 3;

    // Call sign function
    cout << function_sign(n) << endl;

    return 0;

}

// Function definition
int function_sign(int n) {

    // Declare variables
    int sign;

    if (n > 0) {
        sign = 1;
    } else if(n == 0) {
        sign = 0;
    } else {
        sign = -1;
    }

    return sign;

}

```
* Compile and run!

## Functions - III

* Now we're going to split our `function_sign` and `function_abs` functions into separate files, and call them from our main file.
* Join in the following syntax in a C++ file, and save it as `learning_functions.cpp`:
```c++
#include <iostream>
using namespace std;

// Function declarations
int function_sign(int n);
int function_abs(int n);

int main() {

    // Declare variables
    int n;
    n = 3;

    // Call functions
    cout << function_sign(n) << endl;
    cout << function_abs(n) << endl;

    return 0;

}
```

`function_sign.cpp`:
```c++
#include <iostream> // not strictly necessary
using namespace std;

int function_sign(int n) {

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
#include <iostream> // not strictly necessary
using namespace std;

int function_abs(int n) {

    return abs(n);

}
```

* And now we compile like this:
```bash
c++ function_sign.cpp function_abs.cpp learning_functions.cpp -o learning_functions
```
* All these forward declarations can be tiresome, so as a last step we can put them in a header file and `#include` it:

`learning_functions.hpp`:
```c++
int function_sign(int n);
int function_abs(int n);
```

`learning_functions.cpp`:
```c++
#include <iostream>
#include "learning_functions.hpp" // Double quotes for user-defined header files

using namespace std;

int main() {

    // Declare variables
    int n;
    n = 3;

    // Call functions
    cout << function_sign(n) << endl;
    cout << function_abs(n) << endl;

    return 0;

}
```

(`function_sign.cpp` and `function_abs.cpp` unchanged)

* Compile and run, remembering to include all files in the compile command:
```bash
c++ function_sign.cpp function_abs.cpp learning_functions.cpp -o sign
```
* The header file is also a good place to put constants you want to have pre-defined in all of the files in your project.

Your turn:
* Add a function `is_function_abs_less_than_1`. Put it in its own file, add its declaration to the header file, make the main file output `is_function_abs_less_than_1(n)`,  compile, and check that it works.
* Harder version: Look up the data type for `true` and `false` in C++


## Exercise 1 - Collatz conjecture

1. Challenge to see if you remember what we did last time

2. Try to run the Collatz conjecture: create a new script, `collatz_conjecture.cpp`, which inputs a number *n*, and while *n* does not equal 1:
    * Let *f* = *n*/2 if *n* is even
    * Let *f* = 3*n* + 1 if *n* is odd
    * Display *f*
    * Let *n* = *f*

## Exercise 2 - Multiplication table

* Create a new file that prints a 10x10 multiplication table. Make it:
    
2. Set up a 10x10 array `product`.

3. Loop through all rows and columns, so that `product[row][col] = row * col;`

4. Loop through all rows and columns again, `cout`ing appropriately the elements of the table.

## Exercise 3 - Function headers

Write a C++ program that uses a header file.

1. Create a header file named `functions.h` and declare a function `change1` of type `void` that takes as arguments
the referiments to two numbers of type `double`.

2. On the same header, declare a function called `change2` of type `void` that takes the pointers of two numbers of type `double`.

3. Create a file `functions.cc` and implement and algorithm that changes variables of type double `double` for the functions `change1` and `change2`.

4. Create a file `main.cc`, include the header `functions.h` and test the functions `change1` and `change2`.

5. Add to the `makefile` the rules for compiling all tiles `*.cc`.

## Exercise 4 - Conversion temperature

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

## Exercise 5 - Second order equations

Write a program in C++ that solves a second order equation `a x^2 + b x + c = 0`
for all discriminants (>, < e = 0) and where the variables `a`, `b` e `c` come assigned with `cin`.

1. Ask the user to introduce 3 numbers of type `double` representing the coefficients.

2. Compute the discriminant `D = b^2 - 4ac` using the function `std::pow`.

3. Create a condition `if/else if/else` corresponding to the 3 possible cases of the discriminant.

4. Compute the solutions `x1` and `x2` using the quadratic formula for second order equations.
Note that for `D < 0`, the function `std::sqrt()` operates in the real numbers, therefore its argument must be a positive number.
Also in this case we will separe the computations of the real and imaginary part.

Verify the implementation for the following coefficients:
- `a = 2`, `b = 5`, `c = 2` -> solution `x1 = -0.5` e `x2 = -2`.
- `a = 4`, `b = -4`, `c = 1` -> solutions`x1,2 = 0.5`.
- `a = 1`, `b = 4`, `c = 5` -> solutions `x1 = -2 + i` e `x2 = -2 - i`.