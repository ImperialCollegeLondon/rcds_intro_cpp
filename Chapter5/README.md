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

## Pointers and memory allocation

Where in memory is a variable being stored? Here we will introduce pointers, one of the main features of C++ that allows for an efficient way of addressing memory.

* Join in the following syntax in a C++ file, and save it as `pointers.cpp`:
```c++
#include <iostream>
using namespace std;

int main() {

   // Declare variables
   int x = 10;

   // Print value and address of the x variable
   cout << "Value of x is " << x << endl;
   cout << "Address of x is " << &x << endl;

   return 0;

}
```
* The `&` sign indicates an address in memory.
* A *pointer* is a variable whose value is the address of another variable (eg. p = '&x'), and is notated with a `*`. 
* "\*pointer" means the value at the address the pointer is pointing at (eg. \*pointer = x) 
* Edit the `pointers.cpp` file to declare a pointer variable `p` containing the address od x.
```c++
#include <iostream>
using namespace std;

int main() {

   // Declare variables
   int x = 10;
   int *p;
   p = &x;          

   // Print value of x and p 
   cout << "Value of x is " << x << endl;
   cout << "Address stored in p is " << p << endl;
   cout << "Value of *p variable is " << *p << endl;

   return 0;
}
```

Your turn:

* See what happens to the value of `*p` if we change the value of `x`.

Historically pointers were used instead of arrays. Let's try that now.

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

Classes are one of the main things that separate C++ from C. Classes are ways for us to set up objects that have properties and functions which are particular to that type of object. Hence, a coding strongly relying on classes is often referred to as Object Oriented Programming, or OOP.

* Join in the following syntax in a C++ file, and save it as `rectangles.cpp`
```c++
#include <iostream>
using namespace std;

// Rectangle class
class Rectangle {

   // Public variables that every rectancle will have
   public:
      double width;
      double height;

};

// Main function
int main() {

   // Declare Rec1 as a type of the Rectangle class
   Rectangle Rec1;
   double area;

   // Rec1 specification
   Rec1.height = 5.0;
   Rec1.width = 6.0;

   // Define area with both public variables of Rec1
   area = Rec1.height * Rec1.width;
   cout << "Area of Rec1: " << area << endl;

   return 0;

}
```

Your turn:

* Edit the `rectangles.cpp` file to add another rectangle, `Rec2`
```c++
#include <iostream>
using namespace std;

// Rectangle class
class Rectangle {

   // Public variables that every rectancle will have
   public:
      double width;
      double height;

};

// Main function
int main() {

   // Declare Rec1 and Rec2 as a types of the Rectangle class
   Rectangle Rec1;
   Rectangle Rec2;
   double area;

   // Rec1 specification
   Rec1.height = 5.0;
   Rec1.width = 6.0;

   // Rec2 specification
   Rec2.height = 10.0;
   Rec2.width = 12.0;

   // Area of Rec1
   area = Rec1.height * Rec1.width;
   cout << "Area of Rec1: " << area << endl;

   // Area of Rec2
   area = Rec2.height * Rec2.width;
   cout << "Area of Rec2: " << area << endl;

   return 0;

}
```

* Edit the `rectangles.cpp` file and implement "member function", also called "method", of the class `Rectangle` that computes the area, so we can call `Rec1.area()`
```c++
// Rectangle class
class Rectangle {

   // Public variables that every rectancle will have
   public:
      double width;
      double height;
      double area() {return width * height;}

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
      double width;   // Length of rectangle
      double height;   // Height of rectangle
      double area() {return width*height;}
      void set_dimensions (double,double);
};

void Rectangle::set_dimensions (double x, double y) {
  width = x;
  height = y;
}
```

Your turn:

* Replace `Rec1.height = 5.0;` and `Rec1.width = 6.0;` with a call to `Rec1.set_dimensions`

If you want to use `Rectangle` in lots of files, it's annoying to define it every time.

Your turn:

* Put the class declaration and `set_dimensions` definition in a header file, `rectangle.hpp`, and call it from `rectangles.cpp`

For extra practice:

* Create a class `complex_number`. Set up some functions for adding and multiplying them.

## Optimisation

* When compiling, use the flag `-O2` to optimise for speed a little bit. Use `-O3` for more optimisation. `-O0` is the default. Example:
```bash
c++ helloworld.cpp -o hello -O3
```
Note: This will make the compile time LONGER, but runtime faster and more efficient! 
Other things we won't explore but worth looking into
* Parallelisation and HPC - OpenMP
* Particle physics data processing - ROOT framework (https://root.cern/)
* More HPC - OpenMPI
* A number of libraries for ML - TensorFlow, Keras, Pytorch

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

## Exercise 2 - Pointer arrays

1. Copy the file used for exercise 1

2. Create a dynamic array of type `double` and dimension 10, print the memory address for all components of the array.

3. Print the memory address of all components of the array.

4. Verify that the addresses are separated among each other with the number of bytes of type double `double`. (Remember to delete the array at the end of the main function)

## Exercise 3 - Classes

## Exercise 4 - Compute mean value (input from file)

1. Download the datafile copying the next command and running in the terminal:
```bash
wget https://raw.githubusercontent.com/JesusUrtasun/CppCourse/master/Chapter05/data.dat
```
The data contains 1000 numbers corresponding to physical measurements of the acceleration of gravity `g`.

2. Read all numbers from the file using an infinite `for`, controlled by the condition `eof`.

3. Save a variable `double sum = 0.0;` The incrementing sum of the numbers.

4. Compute the mean and print it on screen, verify that the value is near `g=9.7803184`.