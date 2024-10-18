# RCDS - Introduction to C++

## Dr. Jesús Urtasun Elizari

## Imperial College London - 2024 / 2025

<img src="/readme-images/grad-school-logo.png">

### Find the content of the course in GitHub:
[https://github.com/ImperialCollegeLondon/RCDS-intro-cpp](https://github.com/ImperialCollegeLondon/RCDS-intro-cpp)

### Getting C++ set up on your own machine
Instructions are in the [appendix](#appendix).

# Roadmap of the course

## Chapter 1

- Introduction to Linux operative systems, terminal and bash.
- Programing languages and performance comparison. Text editors.
- First steps with C++. Hello world.

## Chapter 2

- Variable types in C++, input / output statements.
- Basic mathematical operations.
- Compiling in parallel. Makefile.

## Chapter 3

- Conditional statements if / else.
- Loops for, while, do while.
- Data file manipulation. Reading and writing files.

## Chapter 4

- Arrays and vectors. Basic algebra.
- Functions in C++.
- Compiling functions and header files.

## Chapter 5

- Pointers and memory allocation.
- Classes and OOP.
- Basic statistics. Computing momenta of a distribution.

## Chapter 6

- Real algebra: scalar product, matrix-vector product
- Armadillo library
- Real RCDS problems: Rectilinear movement, estimate Higgs mass, numerical integration.

# Appendix

## A1. Getting C++ set up on your own machine
Follow the instructions below, depending on which type of machine you will use.

### Step 1: Have a text editor ready
We are going to be writing our code in a text editor. This is a program which lets us produce plain text files. There are lots of choices available, but we recommend downloading [VSCode](https://code.visualstudio.com/).

### Step 2: Have a C++ compiler installed and working
A compiler is a program which takes the text file we have written and turns it into something we can run. Compilers do not look like normal programs, with windows and graphics. Instead they are run using the command line. We will discuss this in class but for now, follow the instructions below, depending on which type of machine you will use.

#### Instructions for Mac and Linux
A C++ compiler should be installed by default on macOS and most Linux distributions.

1. Open Terminal.
2. Type `c++` and press Enter.
3. If it says `clang: error: no input files` or `c++: fatal error: no input files`, then you are ready to go.
4. For Mac, if you don't see either of the error messages in 3. run `xcode-select --install` in terminal and try again.

#### Instructions for Windows (your own computer)
First let's check that you haven't already got a C++ compiler on your computer. If you have installed Fortran in the past, you might already have a C++ compiler.

1. Open Command Prompt from the Start menu (right-click the Start button and select Command Prompt).
2. Type `g++` and press Enter.
3. If you get the error `g++: fatal error: no input files`, then you are good to go. If you get a different message, you don't have a C++ compiler installed and should continue following these instructions.
4. To install the compiler, follow the instructions [on this YouTube video](https://www.youtube.com/watch?v=jfVqzNU3gPg).  Alternitavely you can install the windows subsystem for linux (WSL) and install a linux distribution from the Microsoft store. This is a bit more complicated and larger but will give you a linux environment on your windows machine with a C++ compiler pre-installed (I will be using WSL2 Ubuntu throughout the course). Is this awkward? Yes. Is it worth it? Yes!
5. Check that it works by following steps 1--3 above.


## A2. YouTube videos for distance learning
Timestamps are in the descriptions and correspond to the numbering in this document. Content in the videos may differ slightly. 
* [Part 0: Pre-course instructions](https://www.youtube.com/watch?v=fk4msOijTtU)
* [Part 1](https://youtu.be/wGOPWMY80lw). You must have C++ set up on your machine before starting.
* [Part 2](https://www.youtube.com/watch?v=4xHiVH4_XGo)
* [Part 3](https://www.youtube.com/watch?v=qCHm1EjD-JI)
* [Playlist](https://www.youtube.com/playlist?list=PLcRp2oAQBugtTRlYYarxVyrtwDHS5Mtiw)

# Licence
This work is licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Licence](http://creativecommons.org/licenses/by-nc-sa/4.0/).
