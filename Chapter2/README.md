# Chapter 2 - First steps to C++

- Variables, input / output statements.
- Basic mathematical operations.
- Makefile.

**Subject:** Basic exercises for C++ programming.

Before starting we suggest to create a folder for Chapter 2 in which you can save 
all files that will be used for the exercises.

*Example:* `cd ~/; mkdir Chapter2; cd Chapter2;`

## Variables in C++ - theory

Join in:

```c++
#include <iostream>

using namespace std;

int main()
{
    int x;
    x = 4;
    cout << "The value of x is " << x << endl;
    return 0;
}
```
* Compile and run.

Your turn:
* Change the code so it prints 2*x* instead.
* Let *x* = 3.9. What do you expect to happen? What happens?
* What happens if you forget to add the semicolon?

Join in:
```c++
#include <iostream>

using namespace std;

int main()
{
    double x;
    double y;
    x = 3.141;
    y = 1.618;
    cout << "The value of x is " << x << " and the value of y is " << y << endl;
    return 0;
}
```
* Compile and run.

Your turn:
* Change the code so that it also prints out the product of *x* and *y* on a new line.

## Variables in C++ - exercise 1

Write a program in C++ that declares an integer variable, two double variables, and prints them on screen.

1. Create a new file `exercise1.cpp`.

2. Declare the variable `x` in integer precision (`int`) and assign it an integer value.

2. Declare `y` and `z` in double precision (`double`) and assign them decimal values.

4. Write the values on screen using `cout`.

5. Compile the code with `g++`, calling the executable `program1`.

6. Run the code and check the output.

## Variables in C++ - exercise 2 - Compute area and pertimeter of a rectangle

Write a program in C++ that computes the area and perimeter of a rectangle.

1. Open a new file `exercise2.cpp`, declare the variables in double precision (`double`) for the `base` and `height` of the rectangle.

2. Assign a `base` of `5.0` and a height of `2.0`.

3. Write the formule for the area and perimeter if the rectangle using C++ variables.

4. Write th result on screen using `cout`.

5. Cimpile the code with `g++`, calling the executable `program2`.

6. Run the code and check the output.

## Input / output - theory

Join in:
* New file! `height.cpp`. Note that we're going to use strings here, which need the `<string>` library.
```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    double height;
    cout << "What is your name?" << endl;
    cin >> name;
    cout << "What is your height?" << endl;
    cin >> height;
    cout << name << " is " << height << " metres tall." << endl;
    return 0;
}
```
* Compile and run.

Your turn:
* Convert the height into feet (1 metre = 3.28084 feet)
* Harder: Convert the height into feet and inches (1 foot = 12 inches), rounding down to an integer number of inches. For example, entering 1.81 (metres) should produce "5 feet 11 inches".
    * Hint 1: If `a` and `b` are integers, then `a%b` = *a* mod *b*.
    * Hint 2: Convert to an integer number of inches first.
* What happens if we type nonsense into the inputs?

## Input/output - exercise 3

Copy the file `exercise2.cpp` (area/perimeter rectangle) in a new file `exercise3.cpp`.

Modify the program in such a way that the variables correspong to the base and hieght are read from terminal. Use the command `cin`.

## Input/output - exercise 4 - Notation for cout

Copy file of the previous exercise in `exercise4.cc`.

Print with `cout` the results of area and perimeter using 10 decimal digits, using the notation `fixed` and also `scientific`.

Print with `cout`, in any notation, the area and perimeter of the rectangle in the same row, separed by tabulation `\t`.

Basic arithmetic works out of the box, as you've seen. For 'scientific calculator' stuff, we need the `<cmath>` library. Libraries are like toolboxes.

## Basic maths - theory

Join in:
* New file! `calculator.cpp`
```c++
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x;
    cout << "Enter a number" << endl;
    cin >> x;
    cout << "That number squared is " << pow(x,2) << endl;
    cout << "The square root of that number is " << sqrt(x) << endl;
    return 0;
}
```

Your turn:
* Add a line displaying the sine of the inputted number.
* Change the code so that it inputs two integers, *a* and *b*, and displays *a*/*b*.
* Input *a* as 3, and *b* as 2. What do you notice?

## Basic maths - exercise 5 - Converting temperature

Write a program in C++ where is possible to convert a temperature from
Celsius to Kelvin using the equation:
```
T(Kelvin) = T(Celsius) + 273.15
```
where the user can introduce the temperature as input in Celsius using `cin`.

Verify the next conversions:
- 20 °C -> 293.15 K
- 30 °C -> 303.15 K

## Makefile - theory

* Long compilation scripts are a bit much:
```bash
c++ sign_function.cpp absolute_value.cpp learning_functions.cpp -o sign
```
* So let's put it in a makefile:
```bash
all:
    c++ sign_function.cpp absolute_value.cpp learning_functions.cpp -o sign
```
* (note you need a tab at the beginning, not spaces. Might need to be careful in most text editors. If it doesn't work try disabling 'soft tab' setting or use another editor like Notepad++.)
* Then run `make all`

## Makefile - exercise 6

Write a simple `makefile` where:

1. The precedent exercises are compiled with:
```bash
make program1
make program2
```

2. All exercises are compiled with:
```bash
make
```

3. `program5` is also run automatically with:
```bash
make all
```

4. All the binaries generated with the command `make` are deleted with:
```bash
make clean
```