# Chapter 3 - Conditional statements, loops, file manipulation

- Conditional statements if / else.
- Loops for, while, do while.
- File manipulation, reading and writing files.

Before starting we suggest to create a folder for Chapter 3 where you can save all files that will be created for the exercise
```bash
cd ~/           # Go the home directory
mkdir Chapter3  # Create the directory Chapter3
cd Chapter3     # Go inside Chapter3
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
In this way all programs will be compiled using the following command in the terminal:
```bash
$ make all
```
while all programs will be eliminated by using the folloing one:
```bash
$ make clean
```

## Conditionals

One of the most powerful tools of computer algorithms is the ability of design decision making. Conditional statements allow precisely that, 
by programing a given flow of operations depending on some conditions being fulfilled.
* Join in the following syntax in a C++ file, and save it as `bartender.cpp`
```c++
#include <iostream>
using namespace std;

int main() {

    // Declare variables
    int age;

    // Assign values
    cout << "Welcome to the pub." << endl;
    cout << "What is your age?" << endl;
    cin >> age;

    // Print different message depending on input
    if (age >= 18) {
        cout << "Have a pint!" << endl;
    }
    cout << "Goodbye!" << endl;

    return 0;

}
```
* Compile and run!
* Let's make it more fun adding a third option by means of the `else` condition
```c++
    if (age > 18) {
        cout << "Have a pint!" << endl;
    } else if(age == 18) {
        cout << "Show me your ID and then have a pint!" << endl;
    } else {
        cout << "I'm calling the police." << endl;
    }
```
* Compile and run!

Your turn:
* Also input the name of the customer
* If the name of the customer does not equal your name, get the bartender to ask for money.
    * Hint: `!=` stands for 'not equal to' in C++.
    * Maybe useful: in `if` statements, `&&` stands for AND, `||` for OR.

## Loops

The next tool we are going to put in practice is looping, which stands for the (in) finite repetition of a given task under a certain set of conditions being fulfilled.
The most comonly used loops in most of programming languages are the so called `for`, `while`, and `do while`.
* Join in the following syntax in a C++ file, and save it as `square_numbers.cpp`
```c++
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    // Declare variables
    int n = 10;

    // Loop and print square
    for (int i = 0; i < n; ++i) {
        cout << pow(i, 2) << endl;
    }

    return 0;

}
```
* Compile and run!
* Reference: [the difference between `++i` and `i++`](https://dev.to/somedood/the-difference-between-x-and-x-44dl)

Your turn:
* Change the script to display the 3rd to 9th cubes.

Join in:
* Change the file: let's **comment out** the for loop above and instead write it as a while loop.
```c++
    // Declare initialise a variable at the same time
    int i = 3;

    // Loopp and print cube
    while (i < n) {
        cout << pow(i, 3) << endl;
        ++i;
    }
```

Try:
* Replace `++i` with the more verbose command `i = i+1` and convince yourself that it is equivalent.
* Change the script to display the 3rd, 5th, 7th and 9th cubes.

## File manipulation

Most times, RCDS problems rely on reading data from a given input, or generating results in a specific format. To save and read files, we need to include the `<fstream>` library.
* Join in the following syntax in a C++ file, and save it as `save_to_file.cpp`
```c++
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    // Declare variables
    ofstream myfile;

    // Open file and write a message
    myfile.open ("greetings.txt");
    myfile << "Hello there!" << endl;

    // Close file
    myfile.close();

    return 0;

}
```

Your turn:
* Edit file to print the first 10 squares to a text file called `square_numbers.txt`.
* Run your program again. What can you say about how it writes to the text file?
* Replace `myfile.open ("square_numbers.txt");` with `myfile.open ("square_numbers.txt", ios_base::app);` to make C++ append to the end of a text file, rather than overwrite.

Now let's read in!
* Join in the following syntax in a C++ file, and save it as `read_from_file.cpp`
```c++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    // Declare variables
    string line;
    ifstream myfile;

    // Open file and read lines
    myfile.open ("greetings.txt");
    while (getline(myfile, line)) {
        cout << line << endl;
    }

    // Close file
    myfile.close();

    return 0;

}
```

## Exercise 1 - Increasing / decreasing

Recap of previous chapter. Write a program in C++ where:

1. The program asks for the user to introduce an integer `n`.

2. Increase and decrease `n` by using operators `++` and `--`.

3. Compute the division and module (rest) of `n` by an `int r = 2;`.

5. Print the result on the screen.

## Exercise 2 - Even / ood numbers

Write a program in C++ that produces a different output depending on the input variable

1. The program asks for the user to introduce an integer `n`.

2. Uses the module operator and the conditional statements (`if`, `else`) do determine if it is even or odd.

3. Print the result on the screen.

## Exercise 3 - Hello World with for, while, do while

Write a C++ program that uses loops for printing a result in the terminal.

1. Create a `for` loop tat prints 5 times the same message:
```
Hello World for index = {i}
```
where `{i}` corresponds to the integer number that represents loop index.

2. Analogously, implement a `while` cycle where the following message is printed:
```
Hello World while index = {i}
```

3. Finally, implement a `do/while` loop with message:
```
Hello World do/while index = {i}
```

## Exercise 4 - Collatz conjecture

Write a program in C++ that asks for a number and performs the Collatz algorithm

## Exercise 5 - Fibonacci series

Write a program in C++ that asks for a number and computes all Fibonacci numbers up to that one

## Exercise 6 - File manipulation

Modify the previous exercise in such a way that the final output comes written over a file called `result.dat`.

1. Create a copy of the previous exercise.

2. Implement with `fstream` the creation of an output file with the method `open()`, followed by a success test with the method `good()`.

3. Write the content in screen and in the file.

4. Close the file with the method `close()`.

## Exercise 7 - File manipulation

Modify the previous exercise in such a way that the final output comes red from an input file called `my_input.dat` with the following content:
```
<your name>
<your surname>
<your number>
```

1. Create a copy of the previous exercise.

2. Implement with `fstream` the oppening of the file `my_input.dat`.

3. Read the data from the file.

4. Close the file.

5. Print the result on screen and in the file `result.dat`.
