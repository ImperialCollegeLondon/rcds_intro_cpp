## Chapter 2 - First steps to C++

- Variables, input / output statements.
- Basic mathematical operations.
- Makefile.

Before starting we suggest to create a folder for Chapter 2 where you can save all files that will be created for the exercise
```bash
cd ~/           # Go the home directory
mkdir Chapter2  # Create the directory Chapter2
cd Chapter2     # Go inside Chapter2
```

### Variables in C++

In C++, like in any other programming languages, variables have *types*, such as integer, double precision, string, etc.
Let's do some exercises to see how different variables and data types can be manipulated.
* Join in the following syntax in a C++ file, and save it as `variables.cpp`:
```c++
#include <iostream>
using namespace std;

int main() {

    // Declare variables
    int x;

    // Assign values
    x = 4;

    // Print on screen
    cout << "The value of x is " << x << endl;
    
    return 0;

}
```
* Compile and run.

Your turn:
* Change the code so it prints 2*x* instead.
* Let *x* = 3.9. What do you expect to happen? What happens?
* What happens if you forget to add the semicolon?

* Join in the following syntax in a C++ file:
```c++
#include <iostream>
using namespace std;

int main() {

    // Declare variables
    double x;
    double y;

    // Assign values
    x = 3.141;
    y = 1.618;

    // Print on screen
    cout << "The value of x is " << x << " and the value of y is " << y << endl;
    
    return 0;

}
```
* Compile and run.

Your turn:
* Change the code so that it also prints out the product of *x* and *y* on a new line.

### Input / output

The next step is not only declaring variables and assigning values, but also to ask for the value to the user.
Let's write a script that asks the user to input some variables from the keyboard, and then perform some operations with them.
* Join in the following syntax in a C++ file, and save it as `height.cpp`. Note that we're going to use strings here, which need the `<string>` library.
```c++
#include <iostream>
#include <string>
using namespace std;

int main() {

    // Declare variables
    string name;
    double height;

    // Assign values from keyboard with cin
    cout << "What is your name?" << endl;
    cin >> name;
    cout << "What is your height?" << endl;
    cin >> height;

    // Print on screen
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

### Basic mathematical operations

Once we know how to deal with variables, and input / output them, we are ready to perform some computations.
* Join in the following syntax in a C++ file, and save it as `calculator.cpp`. From now on we will need to include the `<cmath>` library.
```c++
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    // Declare variables
    double x;

    // Assing value from keyboard
    cout << "Enter a number" << endl;
    cin >> x;

    // Print power and square root
    cout << "That number squared is " << pow(x,2) << endl;
    cout << "The square root of that number is " << sqrt(x) << endl;
    
    return 0;

}
```

Your turn:
* Add a line displaying the sine of the inputted number.
* Change the code so that it inputs two integers, *a* and *b*, and displays *a*/*b*.
* Input *a* as 3, and *b* as 2. What do you notice?

### Signed and unsigned variables

A key difference to understand about data types in C++ is signed vs unsigned.

In signed variables, one bit is reserved for the sign (positive or negative), reducing the range of values.
As an example, for a 4-byte (32-bit) signed integer, the range it can represent would be: -2,147,483,648 to 2,147,483,647.
* Use when negative values are valid or necessary for your data. For example:
- Temperature readings (e.g., -20°C to 50°C)
- Financial data, involving credits and debts (positive and negative).

With unsigned variables, no sign bit is required, so all bits are used for the value, effectively doubling the maximum range.
For a 4-byte (32-bit) unsigned integer, tha range would be: 0 to 4,294,967,295.
* Use when only non-negative values are valid, and you need a larger range of positive numbers. For example:
- Counting objects (e.g., number of files, age, etc.).
- Addressing memory locations (memory addresses are non-negative).

```cpp
#include <iostream>
using namespace std;

int main() {

    // Declare variables
    signed int signed_var = -10;
    unsigned int unsigned_var = 10;
    unsigned int unsigned_wrap = 0;

    // Substract 1 from the smallest possible value of unsigned variable
    unsigned_wrap = unsigned_wrap - 1;

    // Display values
    cout << "Signed variable: " << signed_var << endl;
    cout << "Unsigned variable: " << unsigned_var << endl;
    cout << "When an unsigned variable wraps around: " << unsigned_wrap << endl;

    // Input signed variable exceeding range
    cout << "\nEnter a signed integer: ";
    cin >> signed_var;
    cout << "You entered: " << signed_var << endl;

    // Input unsigned variable exceeding range
    cout << "Enter an unsigned integer: ";
    cin >> unsigned_var;
    cout << "You entered: " << unsigned_var << endl;

    return 0;

}
```

### Namespaces and libraries

A *namespace* in C++ is a way to group and organize related classes, functions, variables, and other identifiers to avoid name collisions.
It provides a logical scope for the identifiers it contains. 

```cpp
#include <iostream>

// First namespace
namespace First {
    void greet() {
        std::cout << "Hello from First namespace!" << std::endl;
    }
}

// Second namespace
namespace Second {
    void greet() {
        std::cout << "Hello from Second namespace!" << std::endl;
    }
}

// Main function
int main() {

    // Calls greet from First namespace
    First::greet();

    // Calls greet from Second namespace
    Second::greet();
    
    return 0;
}

```
The *std* namespace is the Standard Library namespace in C++. It contains all the identifiers (like functions, classes, objects) 
from the C++ Standard Library, such as *cout*, *cin*, *vector*, and *string*.

Although it may seem similar or equivalent to a *library*, there are some differences.

* Namespace:
- A logical grouping mechanism within the code.
- Exists in the code structure (not as a separate file or entity).
- Helps prevent name conflicts by separating identifiers with the same name.

* Library:
- A physical collection of precompiled code (functions, classes, etc.) stored in files (e.g., .lib, .dll, .so).
- You include a library in your project to use its functionalities.
- Libraries may or may not use namespaces internally.


As a summary, a *namespace* is a logical grouping for avoiding name conflicts, while a *Library* is a reusable collection of precompiled code.
Multiple namespaces are possible and commonly used for modularity and clarity.

### Makefile

* Until now we are compiling all scripts directly on terminal as:
```bash
c++ exercise1.cpp -o program1
```
* But eventually we will have many programs to compile, which will require something as follows:
```bash
c++ exercise1.cpp -o program1
c++ exercise2.cpp -o program2
c++ exercise3.cpp -o program3
```
* Also, long programs relying in more basic functions, as we will cover later on, require compilation information that can be a bit much:
```bash
c++ function1.cpp function2.cpp main_function.cpp -o main_program
```
* So let's put it in a makefile, which already contains the instructions for compiling all required files in one run:
```bash
# Cpp compiler
CC=g++

# All executables to be generated
all: program1 program2 program3 main_program

# Instructions for compiling
program1: exercise1.cpp
	$(CC) exercise1.cpp -o program1

program2: exercise2.cpp
	$(CC) exercise2.cpp -o program2

program3: exercise3.cpp
	$(CC) exercise3.cpp -o program3

main_program: main_function.cpp
	$(CC) function1.cpp function2.cpp main_function.cpp -o program1

clean:
	rm program1
	rm program2
    rm program3
    rm main_program
```
* Now all exercises are compiled with just writing the following command on the terminal:
```bash
make all
```
* And all the executables, or *binaries*, generated with the command `make` are deleted with:
```bash
make clean
```
* Note you need a tab at the beginning, not spaces. Might need to be careful in most text editors. If it doesn't work try disabling 'soft tab' setting or use another editor like Notepad++.

### Exercise 1 - Variables in C++

Write a program in C++ that declares an integer variable, two double variables, and prints them on screen.

1. Create a new file `exercise1.cpp`.

2. Declare the variable `x` in integer precision (`int`) and assign it an integer value.

2. Declare `y` and `z` in double precision (`double`) and assign them decimal values.

4. Write the values on screen using `cout`.

5. Compile the code with `g++`, calling the executable `program1`.

6. Run the code and check the output.

### Exercise 2 - Area and pertimeter of a rectangle

Write a program in C++ that computes the area and perimeter of a rectangle.

1. Open a new file `exercise2.cpp`, declare the variables in double precision (`double`) for the `base` and `height` of the rectangle.

2. Assign a `base` of `5.0` and a height of `2.0`.

3. Write the formule for the area and perimeter if the rectangle using C++ variables.

4. Write th result on screen using `cout`.

5. Cimpile the code with `g++`, calling the executable `program2`.

6. Run the code and check the output.

### Exercise 3 - Input / output

Copy the file `exercise2.cpp` (area/perimeter rectangle) in a new file `exercise3.cpp`.

Modify the program in such a way that the variables correspong to the base and hieght are read from terminal. Use the command `cin`.

### Exercise 4 - Notation for cout

Copy file of the previous exercise in `exercise4.cc`.

1. Print with `cout` the results of area and perimeter using 10 decimal digits, using the notation `fixed` and also `scientific`.

2. Print with `cout`, in any notation, the area and perimeter of the rectangle in the same row, separed by tabulation `\t`.

3. Basic arithmetic works out of the box, as you've seen. For 'scientific calculator' stuff, we need the `<cmath>` library. Libraries are like toolboxes.

### Exercise 5 - Converting temperature

Write a program in C++ where is possible to convert a temperature from

1. Use the following conversion equation:
```
T(Kelvin) = T(Celsius) + 273.15
```
2. where the user can introduce the temperature as input in Celsius using `cin`.

3. Verify the next conversions:
- 20 °C -> 293.15 K
- 30 °C -> 303.15 K

### Exercise 6 - Makefile

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
