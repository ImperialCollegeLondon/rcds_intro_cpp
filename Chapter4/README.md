# Chapter 4

## Arrays & vectors, functions

**Subject:** Basic exercises for C++ programming.

Before starting we suggest to create a folder for Lesson 3 where you can save all files that will be created for the exercise
```bash
cd ~/           # Go the home directory
mkdir Chapter4  # Create the directory Chapter4
cd Chapter4     # Go inside Chapter4
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

## Exercise 1 - Arrays

## Exercise 2 - Multiplication table

## Exercise 3 - Functions I

## Exercise 4 - Functions II

## Exercise 5 - Functions III

## Exercise 5 - Conversion temperature

Recap of previous chapter. Write a C++ program where it is possible to convert a temperature from Celsius to Kelvin or Farenheit (using two-way selection `if` / `else`).

1. Ask the user for introducing on the terminal the temperature in Celsius using `cin`.

2. Save the value in a variable of type `double`.

3. Ask the user:
```text
Press 1 for conversion to Kelvin.
Press 2 for conversion to Fahrenheit.
Option chosen: <value_cin>
```

4. Save the user's choice in a variable of type `int`, and create the corresponding condition `if/else`.

5. Implement the formula for convertions:
```
T(Kelvin) = T(Celsius) + 273.15
T(Fahrenheit) = T(Celsius) * 9.0 / 5.0 + 32.0
```

6. Print the result in the following formato:
```text
T(Celsius) = <input_value> -> T(<option>) = <converted_value>
```

Verify the next conversions:
- 20 °C -> 68.0 °F
- 20 °C -> 293.15 K

## Exercise 6 - Second order equations

Write a program in C++ that solves a second order equation `a x^2 + b x + c = 0`
for all discriminants (>, < e = 0) and where the variables `a`, `b` e `c` come assigned with `cin`.

1. Ask the user to introduce 3 numbers of type `double` representing the coefficients.

2. Compute the discriminant `D = b^2 - 4ac` using the function `std::pow`.

3. Create a condition `if/else if/else` corresponding to the 3 possible cases of the discriminant.

4. Compute the solutions `x1` and `x2` using the quadratic formula for second order equations.
Note that for `D < 0`, the function `std::sqrt()` operates in the real numbers, therefore its argument must be a positive number.
Also in this case we will separe the computations of the real and imaginary part.

Verify the implementation for the following coefficients:
- `a = 2`, `b = 5`, `c = 2` -> solution `x1 = -0.5` e `x2 = -2`.
- `a = 4`, `b = -4`, `c = 1` -> solutions`x1,2 = 0.5`.
- `a = 1`, `b = 4`, `c = 5` -> solutions `x1 = -2 + i` e `x2 = -2 - i`.

## Exercise 3 - Chosing bycicle size

## Exercise 4 - Switch
