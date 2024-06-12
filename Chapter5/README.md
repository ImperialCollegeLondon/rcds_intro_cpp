# Chapter 5 - Pointers, classes and OOP

- Pointers and memory allocation.
- Classes and OOP.
- Basic statistics. Computing mean value and std.

Before starting we suggest to create a folder for Chapter 5 where you can save all files that will be created for the exercise
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

## Pointers

Where in memory is a variable being stored?
Today we will address memory allocation and the use of pointers, indeed one of the main features of the C++ language.
* Join in the following syntax in a C++ file, and save it as `pointers.cpp`:
```c++
#include <iostream>
using namespace std;

int main() {

   // Declare variables
   int x = 10;

   // Check value and memory address
   cout << "Value of x is " << x << endl;
   cout << "Address of x is " << &x << endl;

   return 0;

}
```
* The `&` sign indicates an address in memory.
* A *pointer* is a variable whose value is the address of another variable (eg. p = '&x'), and is notated with a `*`. 
* "\*pointer" means the value at the address the pointer is pointing at (eg. \*pointer = x) 

```c++
#include <iostream>
using namespace std;

int main() {

   // Declare variables
   int x = 10;
   int *p;
   p = &x;          

   // Check value and memory address
   cout << "Value of x is " << x << endl;
   cout << "Address stored in p is " << p << endl;
   cout << "Value of *p variable is " << *p << endl;

   return 0;

}
```
Your turn:
* See what happens to the value of `*p` if we change the value of `x`.

Historically pointers were used instead of arrays.
* Join in the following syntax in a C++ file, and save it as `pointer_array.cpp`

```c++
#include <iostream>
using namespace std;

int main () {

   // Declare variables
   int primes[3] = {2, 3, 5};
   int *p;

   // Set the pointer to point at the start of the array
   p = primes;

   // Iterate over the values of the pointer
   for (int i = 0; i < 3; i++) {
      cout << "Address of primes[" << i << "] is " << p << endl;
      cout << "Value of primes[" << i << "] is " << *p << endl;
      ++p;
   }  

   return 0;

}
```

Your turn:
* See what `*(primes + 2)` outputs.

## Classes and OOP

Classes are one of the main things that separate C++ from C. Classes are ways for us to set up objects that have properties and functions which are particular to that type of object. That is why programming relying on classes and objects is commonly referred to as "Object Oriented Programming", or OOP.
* Join the following syntax in a C++ file, and save it as `rectangles.cpp`
```c++
#include <iostream>
using namespace std;

class Rectangle {

   public:
      // Width of rectangle
      double width;
      // Height of rectangle
      double height;

};

int main() {

   // Declare Rec1 of type Rectangle
   Rectangle Rec1;
   
   // Rec1 specification
   Rec1.height = 5.0;
   Rec1.width = 6.0;

   // Declare variables
   double area;

   // Compute area of Rec1
   area = Rec1.height * Rec1.width;
   cout << "Area of Rec1: " << area << endl;

   return 0;

}
```

Your turn:
* Add another rectangle, `Rec2`

You should get something like:

```c++
#include <iostream>
using namespace std;

class Rectangle {

   public:
      // Width of rectangle
      double width;
      // Height of rectangle
      double height;

};

int main() {

   // Declare Rec1 and Rec2 of type Rectangle
   Rectangle Rec1;
   Rectangle Rec2;

   // Rec1 specification
   Rec1.height = 5.0;
   Rec1.width = 6.0;

   // Rec2 specification
   Rec2.height = 10.0;
   Rec2.width = 12.0;

   // Declare variables
   double area;

   // Compute area of Rec1
   area = Rec1.height * Rec1.width;
   cout << "Area of Rec1: " << area << endl;

   // Compute area of Rec2
   area = Rec2.height * Rec2.width;
   cout << "Area of Rec2: " << area << endl;

   return 0;

}
```

Same as when we declare variables of the class rectangle, we can also declare functios, or "methods".
* Let's make area a 'member function' of the class rectangle, so we can call `Rec1.area()`, for example:

```c++
class Rectangle {

   public:
      // Length of rectangle
      double width;
      // Height of rectangle
      double height;
      // Method computing area
      double area() {return width*height;}

};

```

Your turn:
* Replace `area = Rec1.height * Rec1.width;` with `area = Rec1.area();` and see that it works.
* Add a member function `perimeter` which returns the length of the perimeter.

Join in:
* We're going to look at another way of creating a member function. This is entirely equivalent.
* Just like how we forward declared functions earlier, we can forward declare them here.

```c++
class Rectangle {

   public:
      // Length of rectangle
      double width;
      // Height of rectangle
      double height;
      // Method computing area
      double area() {return width*height;}
      // Method specifying dimensions
      void set_dimensions (double,double);

};

void Rectangle::set_dimensions (double x, double y) {

  width = x;
  height = y;

}
```

Your turn:
* Replace `Rec1.height = 5.0;` and `Rec1.width = 6.0;` with a call to `Rec1.set_dimensions`
* If you want to use `Rectangle` in lots of files, it's annoying to define it every time.

Your turn:
* Put the class declaration and `set_dimensions` definition in a header file, `rectangle.hpp`, and call it from `rectangles.cpp`

For extra practice:
* Create a class `complex_number`. Set up some functions for adding and multiplying them.

## Optimisation

* The first level optimization we can try is at the level of compilation. That is, at the stage of building of bulding the executable program out of our c++ syntax.
When compiling, use the flag `-O2` to optimise for speed a little bit. Use `-O3` for more optimisation. `-O0` is the default. Example:
```bash
c++ helloworld.cpp -o hello -O3
```
Note: This will make the compile time LONGER, but runtime faster and more efficient! 

* Another way commonly used in C++ is called multi-threading. That is, allowing different parts of the code to be executed in parallel, at the same time.
Not to be confused with multi tasking (*). Multi-threading is an available tool since c++ v11, back in 2011, and we will see a couple of simple examples.

* Join in the following syntax in a C++ file, and save it as `multi_thread.cpp`:
```c++
#include <iostream>
using namespace std;

// Function 1 - write "+" symbol two hundred times
void function1() {
    for (int i = 0; i < 200; i++) {
        cout << "+";
    }
}
// Function 2 - write "-" symbol two hundred times
void function2() {
    for (int i = 0; i < 200; i++) {
        cout << "-";
    }
}

// Main function
int main() {

    // Call functions
    function1();
    function2();

    return 0;

}
```

This will print out a very predictable outcome. Let's now allow for function1 to be executed by one thread, and function2 by a different one in parallel.
The first thing we will need to add is a thread heather, such as the `thread` one in the same way we include the `iostream` library.

```c++
#include <iostream>
#include <thread>
using namespace std;

// Function 1 - write "+" symbol two hundred times
void function1() {
    for (int i = 0; i < 200; i++) {
        cout << "+";
    }
}
// Function 2 - write "-" symbol two hundred times
void function2() {
    for (int i = 0; i < 200; i++) {
        cout << "-";
    }
}

// Main function
int main() {

    // Call two instances of the class thread
    std::thread worker1(function1);
    std::thread worker2(function2);

    // Join for proper syncronization
    // Avoid termination issues
    worker1.join();
    worker2.join();

    cout << "" << endl;
    
    return 0;

}
```

## Exercise 1 - Pointers

Write a C++ program where pointers are used.

1. Create a variable `x` in a pointer `*p` of type `double` initialized with `5.5` and `NULL` respectively.

2. Print on screen:
   - the value in memory of the variables `x`.
   - the memory address of the variable `x`.
   - the memory address pointed by the pointer `p`.
   - the memory address of the pointer `p`.

3. Assign to the pointer `p` the memory address of the variable `x`. Print on terminal the address pointed by `p` and its value.

4. Ask on terminal a number of type `double` and assign it to the value pointed by `p`. Control that the value `x` has been modified.

5. Create a dynamic array of type `double` and dimension 10, print the memory address for all components of the array. Print the memory
address of all components of the array. Verify that the addresses are separated among each other with the number of bytes of type double `double`. (Remember to delete the array at the end of the main function).

## Exercise 2 - Classes

Write a C++ program that instances two objects of the class Rectancle.

* Both rectangle dimensions are set using the method `set_dimensions()`

* Implement a method computing area and another computing perimeter.

* Add a member function `perimeter` which returns the length of the perimeter

* Replace `area = Rec1.height * Rec1.width;` in theory session with `area = Rec1.area();`, and repeat for the perimeter.

## Exercise 3 - Compute mean value (input from file)

1. Download the datafile copying the next command and running in the terminal:
```bash
wget https://raw.githubusercontent.com/JesusUrtasun/CppCourse/master/Chapter05/data.dat
```
The data contains 1000 numbers corresponding to physical measurements of the acceleration of gravity `g`.

2. Read all numbers from the file using an infinite `for`, controlled by the condition `eof`.

3. Declare a variable `double sum = 0.0;`, and use it to store the incrementing sum of the numbers.

4. Compute the mean and standard deviation and print it on screen, verify that the value is near `g = 9.7803184`.