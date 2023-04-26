# Chapter 3 - Conditional statements, loops, file manipulation

- Conditional statements if / else.
- Loops for, while, do while.
- File manipulation.

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

in this way all programs will be compiled using the following command in the terminal:
```bash
$ make
```
while all programs will be eliminated by using the folloing one:
```bash
$ make clean
```

## Exercise 1 - Increasing / decreasing

Recap of previous chapter. Write a program in C++ where:

1. The program asks for the user to introduce an integer `n`.

2. Increase and decrease `n` by using operators `++` and `--`.

3. Compute the division and module (rest) of `n` by an `int r = 2;`.

5. Print the result on the screen.

## Conditionals - theory

Join in:
* New file! `bartender.cpp`
```c++
#include <iostream>

using namespace std;

int main()
{
    int age;
    cout << "Welcome to the pub." << endl;
    cout << "What is your age?" << endl;
    cin >> age;
    if(age >= 18){
        cout << "Have a pint!" << endl;
    }
    cout << "Goodbye!" << endl;
    return 0;
}
```
* Compile and run!
* Let's make it more fun with `else`
```c++
if(age > 18){
    cout << "Have a pint!" << endl;
} else if(age == 18){
    cout << "Show me your ID and then have a pint!" << endl;
} else {
    cout << "I'm calling the police." << endl;
}
```
* Compile and run!

Your turn:
* Also input the name of the customer
* If the name of the customer does not equal your name, get the bartender to ask for money.
    * Hint: `!=` is 'not equal to' in C++.
    * Maybe useful: in `if` statements, `&&` is AND, `||` is OR.

## Conditionals - exercise 2 - even and ood numbers

Write a program in C++ that produces a different output depending on the input variable

1. The program asks for the user to introduce an integer `n`.

2. Uses the module operator and the conditional statements (`if`, `else`) do determine if it is even or odd.

3. Print the result on the screen.

## Exercise 3 - Conditionals II - bartender

Write a program in C++ that produces a different output depending on the input variable

1. The program asks for the user to introduce an integer `n`.

2. Uses the module operator and the conditional statements (`if`, `else`) do determine if it is even or odd.

3. Print the result on the screen.

## Loops I

Join in:
* New file! `square_numbers.cpp`
```c++
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n = 10;
    for(int i=0; i<n; ++i){
        cout << pow(i,2) << endl;
    }
    return 0;
}
```
* Compile and run!
* Reference: [the difference between `++i` and `i++`](https://dev.to/somedood/the-difference-between-x-and-x-44dl)

Try:
* Save the script as `cube_numbers.cpp`
* Change the script to display the 3rd to 9th cubes.

Join in:
* Change the file: let's **comment out** the for loop above and instead write it as a while loop.
```c++
int i=3; // We can define and initialise a variable at the same time.
while(i<n){
    cout << pow(i,3) << endl;
    ++i;
}
```

Try:
* Replace `++i` with the more verbose command `i = i+1` and convince yourself that it is equivalent.
* Change the script to display the 3rd, 5th, 7th and 9th cubes (i.e. go up in 2s, not in 1s)

## Loops I - exercise 4 - Hello World for, while, do/while

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

## Exercise 5 - Loops II - Square and cube numbers

Write a C++ program that uses loops for raising input to a given power.

1. Raise to the square.

2. Raise to the cube.

3. Collatz conjecture

## File manipulation - theory

To save and read files, we need to include the `<fstream>` library.

Join in:

* New file! `save_to_file.cpp`

```c++
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream myfile;
    myfile.open ("greeting.txt");
    myfile << "Hello there!" << endl;
    myfile.close();

    return 0;
}
```

Your turn:
* Create a new file, `save_to_file2.cpp`, where you print the first 10 squares to a text file called `square_numbers.txt`.
* Run your program again. What can you say about how it writes to the text file?
* Replace `myfile.open ("square_numbers.txt");` with `myfile.open ("square_numbers.txt", ios_base::app);` to make C++ append to the end of a text file, rather than overwrite.

Join in:

* Now let's read in!
* New file! `read_from_file.cpp`

```c++
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string line;
    ifstream myfile;
    myfile.open ("greeting.txt");
    while (getline(myfile,line)){
        cout << line << endl;
    }
    myfile.close();

    return 0;
}
```

## File manipulation - exercise 6

Modify the previous exercise in such a way that the final output comes written over a file called `result.dat`.

1. Create a copy of the previous exercise.
2. Implement with `fstream` the creation of an output file with the method `open()`,
followed by a success test with the method `good()`.
3. Write the content in screen and in the file.
4. Close the file with the method `close()`.

## File manipulation - exercise 7

Modify the previous exercise in such a way that the final output comes red from an input file called `myinput.dat`
with the following content:
```
<your name>
<your surname>
<your number>
```

1. Create a copy of the previous exercise.
2. Implement with `fstream` the oppening of the file `myinput.dat`.
3. Read the data from the file.
4. Close the file.
5. Print the result on screen and in the file `result.dat`.
