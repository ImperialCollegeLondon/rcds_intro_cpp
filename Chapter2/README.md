# Chapter 2

## First steps to C++

**Subject:** Basic exercises for C++ programming.

Before starting we suggest to create a folder for Chapter 2 in which you can save 
all files that will be used for the exercises.

*Example:* `cd ~/; mkdir Chapter2; cd Chapter2;`

## Exercise 1 - Variable in C++

Write a program in C++ that declares an integer variable, two double variablesm, and prints them on screen.

1. Create a new file `exercise1.cpp`.

2. Declare the variable `x` in integer precision (`int`) and assign it an integer value.

2. Declare `y` and `z` in double precision (`double`) and assign them decimal values.

4. Write the values on screen using `cout`.

5. Compile the code with `g++`, calling the executable `program1`.

6. Run the code and check the output.

## Exercise 2 - Compute area and pertimeter of a rectangle

Write a program in C++ that computes the area and perimeter of a rectangle.

1. Open a new file `exercise2.cpp`, declare the variables in double precision (`double`) for the `base` and `height` of the rectangle.

2. Assign a `base` of `5.0` and a height of `2.0`.

3. Write the formule for the area and perimeter if the rectangle using C++ variables.

4. Write th result on screen using `cout`.

5. Cimpile the code with `g++`, calling the executable `program2`.

6. Run the code and check the output.


## Exercise 3 - Input/output

Copy the file `exercise2.cpp` (area/perimeter rectangle) in a new file `exercise3.cpp`.

Modify the program in such a way that the variables correspong to the base and hieght are read from terminal. Use the command `cin`.

## Exercise 4 - Notation for cout

Copy file of the previous exercise in `exercise4.cc`.

Print with `cout` the results of area and perimeter using 10 decimal digits, using the notation `fixed` and also `scientific`.

Print with `cout`, in any notation, the area and perimeter of the rectangle in the same row, separed by tabulation `\t`.

## Exercise 5 - Converting temperature

Write a program in C++ where is possible to convert a temperature from
Celsius to Kelvin using the equation:
```
T(Kelvin) = T(Celsius) + 273.15
```
where the user can introduce the temperature as input in Celsius using `cin`.

Verify the next conversions:
- 20 °C -> 293.15 K
- 30 °C -> 303.15 K

## Exercise 3 - Makefile

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