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

## Arrays - theory

Join in:

* Edit `square_numbers.cpp`
```c++
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n = 10;
    int square_numbers[10];
    for(int i=0; i<n; ++i){
        square_numbers[i] = pow(i,2);
    }
    for(int i=0; i<n; ++i){
        cout << square_numbers[i] << endl;
    }    
    return 0;
}
```
* Note you can't `cout` an array
* We can also define arrays like this:
```c++
int main()
{
    int n = 10;
    int square_numbers[10];
    int favourite_numbers[10] = {3, 1, -4, 1}; // Note we haven't defined them all.;

    for(int i=0; i<n; ++i){
        square_numbers[i] = pow(i,2);
    }

    for(int i=0; i<n; ++i){
        cout << square_numbers[i] << endl;
    }    
    for(int i=0; i<n; ++i){
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

Try:
* Create a new file `multiplication_table.cpp`. We are going to make it print a 10x10 multiplication table. Make it:
    * Set up a 10x10 array `product`.
    * Loop through all rows and columns, so that `product[row][col] = row * col;`
    * Loop through all rows and columns again, `cout`ing appropriately the elements of the table.

## Arrays - exercise 1 - Multiplication table

## Functions I

Writing functions allows us to do more complicated things.

Join in:

* New file! `learning_functions.cpp`

```c++
#include <iostream>

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

int main()
{
    int n;
    n = 3;
    cout << sign_function(n) << endl;

    return 0;
}
```
* Global and local variables.
* Note: order is important. What happens if you define `sign_function` after `main`?

Your turn:

* Add an extra function to this file, `absolute_value`, which returns the absolute value of an integer which is passed to it.
* Add an extra line to the `main` function so that it also displays the absolute value of *n*.

## Functions II

Join in:

* There is a way to define functions with `main` first: it's called 'forward declaration'.
* In general, this is better because it allows more flexible code.

```c++
#include <iostream>

using namespace std;

int sign_function(int n);

int main()
{
    int n;
    n = 3;
    cout << sign_function(n) << endl;

    return 0;
}

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
* Compile and run!
* Now we're going to split our `sign_function` and `absolute_value` functions into separate files, and call them from our main file.

## Functions III

`learning_functions.cpp`:
```c++
#include <iostream>

using namespace std;

int sign_function(int n);
int absolute_value(int n);

int main()
{
    int n;
    n = 3;
    cout << sign_function(n) << endl;
    cout << absolute_value(n) << endl;

    return 0;
}
```

`sign_function.cpp`:
```c++
#include <iostream> // not strictly necessary

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

`absolute_value.cpp`:
```c++
#include <iostream> // not strictly necessary

using namespace std;

int absolute_value(int n)
{
    return abs(n);
}
```

* And now we compile like this:
```bash
c++ sign_function.cpp absolute_value.cpp learning_functions.cpp -o sign
```
* All these forward declarations can be tiresome, so we can put them in a header file and `#include` it:

`learning_functions.hpp`:
```c++
int sign_function(int n);
int absolute_value(int n);
```

`learning_functions.cpp`:
```c++
#include <iostream>
#include "learning_functions.hpp" // double quotes for user-defined header files

using namespace std;

int main()
{
    int n;
    n = 3;
    cout << sign_function(n) << endl;
    cout << absolute_value(n) << endl;

    return 0;
}
```

(`sign_function.cpp` and `absolute_value.cpp` unchanged)

* Compile and run, remembering to include all files in the compile command:
```bash
c++ sign_function.cpp absolute_value.cpp learning_functions.cpp -o sign
```
* The header file is also a good place to put constants you want to have pre-defined in all of the files in your project.

Your turn:
* Add a function `is_absolute_value_less_than_1`. Put it in its own file, add its declaration to the header file, make the main file output `is_absolute_value_less_than_1(n)`,  compile, and check that it works.
* Harder version: Look up the data type for `true` and `false` in C++


## Functions 3 - headers and source

Write a C++ program that uses a header file.

1. Create a header file named `functions.h` and declare a function `change1` of type `void` that takes as arguments
the referiments to two numbers of type `double`.

2. On the same header, declare a function called `change2` of type `void` that takes the pointers of two numbers of type `double`.

3. Create a file `functions.cc` and implement and algorithm that changes variables of type double `double` for the functions `change1` and `change2`.

4. Create a file `main.cc`, include the header `functions.h` and test the functions `change1` and `change2`.

5. Add to the `makefile` the rules for compiling all tiles `*.cc`.

## Exercise 5 - Conversion temperature

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

## Exercise 6 - Second order equations

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