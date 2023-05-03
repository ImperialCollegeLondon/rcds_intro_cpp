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

## Pointers - theory

Where in memory is a variable being stored?

Join in:
* New file! `pointers.cpp`:
```c++
#include <iostream>

using namespace std;

int main(){
   int x = 10;

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

int main(){
   int x = 10;
   int *p;
   p = &x;          

   cout << "Value of x is " << x << endl;
   cout << "Address stored in p is " << p << endl;
   cout << "Value of *p variable is " << *p << endl;

   return 0;
}
```

Your turn:

* See what happens to the value of `*p` if we change the value of `x`.

Join in:

* Historically pointers were used instead of arrays.
* New file! `pointer_array.cpp`

```c++
#include <iostream>

using namespace std;

int main () {
    int primes[3] = {2, 3, 5};
    int *p;

    p = primes; // Set the pointer to point at the start of the array

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

## Pointers - exercise 1

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

## Classes - theory

Classes are one of the main things that separate C++ from C. Classes are ways for us to set up objects that have properties and functions which are particular to that type of object.

Join in:
* New file `rectangles.cpp`
```c++
#include <iostream>

using namespace std;

class Rectangle {
   public:
      double width;    // Width of rectangle
      double height;   // Height of rectangle
};

int main() {
   Rectangle Rec1;        // Declare Rec1 of type Rectangle

   // Rec1 specification
   Rec1.height = 5.0;
   Rec1.width = 6.0;

   double area;

   // area of Rec1
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
      double width;    // Width of rectangle
      double height;   // Height of rectangle
};

int main() {
   Rectangle Rec1;        // Declare Rec1 of type Rectangle
   Rectangle Rec2;        // Declare Rec2 of type Rectangle

   // Rec1 specification
   Rec1.height = 5.0;
   Rec1.width = 6.0;

   // Rec2 specification
   Rec2.height = 10.0;
   Rec2.width = 12.0;

   double area;

   // area of Rec1
   area = Rec1.height * Rec1.width;
   cout << "Area of Rec1: " << area << endl;

   // area of Rec2
   area = Rec2.height * Rec2.width;
   cout << "Area of Rec2: " << area << endl;

   return 0;
}
```

Join in:

* Let's make area a 'member function' of the class (so we can call `Rec1.area()`, for example)

```c++
class Rectangle {
   public:
      double width;   // Length of rectangle
      double height;   // Height of rectangle
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

## Classes - exercise

(...)

## Optimisation

* When compiling, use the flag `-O2` to optimise for speed a little bit. Use `-O3` for more optimisation. `-O0` is the default. Example:
```bash
c++ helloworld.cpp -o hello -O3
```
Note: This will make the compile time LONGER, but runtime faster and more efficient! 

## Exercise 3 - Compute mean value (input from terminal)

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
