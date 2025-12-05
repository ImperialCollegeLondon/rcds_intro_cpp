## Chapter 5 - Pointers, classes and OOP

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

### Pointers

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

In C++, the placement of the `*` symbol in pointer declarations (`int* ptr` vs `int * ptr`) is a matter of style. Both styles are functionally equivalent, but each has different implications and preferences depending on the context. The compiler treats these declarations identically.
- The `int* ptr` style (Often preferred in modern C++), highlights that `ptr` is a pointer type.
- The `int * ptr` style, emphasizes the association of `*` with the variable name.

Feel free to choose the style that best aligns with your conventions or personal preference. Both styles are valid and widely accepted.

Another exercise to play with pointers and arrays.
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
      cout << "Reference to primes is " << &p << endl; // 
      cout << "Address of primes[" << i << "] is " << p << endl;
      cout << "Value of primes[" << i << "] is " << *p << endl;
      cout << "\n";
      ++p;
   }

   return 0;

}
```

Important distinction to note here:
* The variable `&p` is the *reference*, the address of the pointer itself. This is a single fixed location, where the pointer is stored.
* The variable `p` is the *pointer variable*, that prints the address of the current array element that `p` points to.
* The variable `*p` is the *value stored* at the memory location that `p` points to.

### Dynamic memory allocation

Historically pointers were used instead of arrays.
* Join in the following syntax in a C++ file, and save it as `pointer_array.cpp`

```c++
// Import libraries
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Print elements of a vector
void print_vector(double* v, int size);

// Compute inverse of a vector
double* inverse_vector(double* v, int size);

// Main function
int main() {

    // Declare variables
    int n;
    cout << "Enter size of vector: "; cin >> n;
    
    // Initialize dynamic array
    double* vec = new double[n];
    cout << "Enter vector elements separated by space: "; 
    for (int i = 0; i < n; i++) cin >> vec[i];

    // Print vector elements
    cout << "\nOriginal vector "; print_vector(vec, n);
    cout << "Size of dynamic vector: " << sizeof(double*) << " bytes \n";

    // Measure time with chrono
    auto start = high_resolution_clock::now();
    double* inv_vec = inverse_vector(vec, n);
    auto end = high_resolution_clock::now();

    // Print result and computation time
    cout << "\nInverse vector: "; print_vector(inv_vec, n);
    cout << "Size of dynamic vector: " << sizeof(double*) << " bytes \n";
    cout << "Computation time: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds\n";

    // Free allocated memory
    delete[] vec;
    delete[] inv_vec;

    return 0;
}

// Print elements of a vector
void print_vector(double* v, int size) {

    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << "\n";

}

// Compute inverse of a vector
double* inverse_vector(double* v, int size) {

    // Allocate new array for inverse
    double* inv = new double[size];

    for (int i = 0; i < size; i++) {
        if (v[i] == 0) throw runtime_error("\nDivision by zero in inverse_vector");
        inv[i] = 1.0 / v[i];
    }
    
    return inv;

}
```

### Optimize `reverse_string.cpp`

Let's open the `reverse_string.cpp` file of Chapter 3 and add some improvements concerning memory

* The key improvement is in `reverse_string`: we pre-allocate the output string to the correct size using the `reversed.reserve()`. 

* Use the function `.push_back()` to fill the reversed string, to avoid repeated reallocations during `+=`, which is becomes expensive with large / heavy inputs.

```c++
// Import libraries
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Function reversing a string
string reverse_string(const string& input) {

    // Reserve space to avoid reallocations #1
    string reversed;
    reversed.reserve(input.size());

    // Efficient reverse build
    for (int i = input.length() - 1; i >= 0; i--) {
        // Better than += for single chars #2
        reversed.push_back(input[i]);
    }

    return reversed;

}

// Main function
int main() {

    string original;

    cout << "Enter a string: ";
    getline(cin, original); // Read entire line

    // Reverse the string
    string reversed = reverse_string(original);

    // Print results
    cout << "\nOriginal string: " << original << endl;
    cout << "Reversed string: " << reversed << endl;

    // Append reversed string to existing file #3
    ofstream file("greetings.txt", ios::app);
    if (!file) {
        cout << "Error: Could not open file for appending.\n";
        return 1;
    }

    file << reversed << "\n";

    cout << "\nReversed string appended to greetings.txt\n";

    return 0;

}
```

### Optimisation

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

### Exercise 1 - Pointers

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

### Exercise 2 - Classes and inheritance

Write a C++ program that instances two objects of the class Rectancle.

* Both rectangle dimensions are set using the method `set_dimensions()`

* Implement a method computing area and another computing perimeter.

* Add a member function `perimeter` which returns the length of the perimeter

* Replace `area = Rec1.height * Rec1.width;` in theory session with `area = Rec1.area();`, and repeat for the perimeter.

### Exercise 3 - Compute mean value (input from file)

1. Download the datafile copying the next command and running in the terminal:
```bash
wget https://raw.githubusercontent.com/JesusUrtasun/CppCourse/master/Chapter05/data.dat
```
The data contains 1000 numbers corresponding to physical measurements of the acceleration of gravity `g`.

2. Read all numbers from the file using an infinite `for`, controlled by the condition `eof`.

3. Declare a variable `double sum = 0.0;`, and use it to store the incrementing sum of the numbers.

4. Compute the mean and standard deviation and print it on screen, verify that the value is near `g = 9.7803184`.
