## RCDS - Introduction to C++

### Dr. Jesús Urtasun Elizari

### Imperial College London - 2024 / 2025

<img src="/readme-figures/grad-school-logo.png">

### Find the content of the course in GitHub:
[https://github.com/ImperialCollegeLondon/RCDS-intro-cpp](https://github.com/ImperialCollegeLondon/RCDS-intro-cpp)

This course provides an introduction to the C++ programming language.
The topics covered will include basic concepts on data science such as variable types, loops, conditional statements, arrays and vectors. 
The aim of the course is to provide strong foundations at the mathematical and theoretical level, while providing practical exercises to work on real data.

The course is organized in six chapters, covering the topics listed below. 
It will involve practical sessions and hands-on coding, which you can do both in your computer or in the codespaces provided by the course github.
No prior experience on programming is required for the attendance of this course.

## Roadmap of the course

### Chapter 1

- Introduction to Linux operative systems, terminal and bash.
- Programing languages and performance comparison. Text editors.
- First steps with C++. Hello world.

### Chapter 2

- Variable types in C++, input / output statements.
- Basic mathematical operations.
- Compiling in parallel. Makefile.

### Chapter 3

- Conditional statements if / else.
- Loops for, while, do while.
- Data file manipulation. Reading and writing files.

### Chapter 4

- Arrays and vectors. Basic algebra.
- Functions in C++.
- Compiling functions and header files.

### Chapter 5

- Pointers and memory allocation.
- Classes and OOP.
- Basic statistics. Computing momenta of a distribution.

### Chapter 6

- Real algebra: scalar product, matrix-vector product
- Armadillo library
- Real RCDS problems: Rectilinear movement, estimate Higgs mass, numerical integration.

## Getting C++ set up on your own machine

We will be working with *Visual Studio Code* as main editor, and *g++* as compiler. Although recommended, they do not need to be installed in your local computers, since we will use `Codespaces` provided by `Github`, which already implement an interface ready to program an execute the code.

For local instalation follow the instructions below, depending on which type of machine you will use.

### Step 1: Have a text editor ready
We are going to be writing our code in a text editor. This is a program which lets us produce plain text files. There are lots of choices available, but we recommend downloading [VSCode](https://code.visualstudio.com/).

### Step 2: Have a C++ compiler installed and working
A compiler is a program which takes the text file we have written and turns it into something we can run. Compilers do not look like normal programs, with windows and graphics. Instead they are run using the command line. We will discuss this in class but for now, follow the instructions below, depending on which type of machine you will use.

### Instructions for Mac and Linux
A C++ compiler should be installed by default on macOS and most Linux distributions.

1. Open Terminal.
2. Type `c++` and press Enter.
3. If it says `clang: error: no input files` or `c++: fatal error: no input files`, then you are ready to go.
4. For Mac, if you don't see either of the error messages in 3. run `xcode-select --install` in terminal and try again.

### Instructions for Windows (your own computer)
First let's check that you haven't already got a C++ compiler on your computer. If you have installed Fortran in the past, you might already have a C++ compiler.

1. Open Command Prompt from the Start menu (right-click the Start button and select Command Prompt).
2. Type `g++` and press Enter.
3. If you get the error `g++: fatal error: no input files`, then you are good to go. If you get a different message, you don't have a C++ compiler installed and should continue following these instructions.
4. To install the compiler, follow the instructions [on this YouTube video](https://www.youtube.com/watch?v=jfVqzNU3gPg). Alternitavely you can install the windows subsystem for linux (WSL) and install a linux distribution from the Microsoft store. This is a bit more complicated and larger but will give you a linux environment on your windows machine with a C++ compiler pre-installed.
5. Check that it works by following steps 1--3 above.

## Licence
This work is licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Licence](http://creativecommons.org/licenses/by-nc-sa/4.0/).
