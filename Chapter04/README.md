# Chapter 4

### Jesús Urtasun Elizari - Uiverisity of Milan - 2019/20

**Note:** Base exercises in C++: if/else, switch and for.

Before starting we suggest to create a folder for Lesson 4 where you can save all files that will be created for the exercise
```bash
cd ~/           # go the home directory
mkdir Chapter03  # create the directory Chapter03 in home
cd lezione3     # go inside Chapter03
```
Create a `makefile` to compile all exercises

## Exercise 1 - Conversion temperature

Write a C++ program where it is possible to convert a temperature from Celsius to Kelvin or Farenheit (using two-way selection `if` / `else`).

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

## Esercizio 2 - Second order equations

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

Write a C++ program tha, depending on the age, height and wright of the user (introduced by terminal) 
recommends a size for the bycicle (XS,S,M,L,XL) following the next criteria:

- Minor or equal to 10 anni: XS

- Between 10 and 18 year (included):
  - Height minor equal to 1.10m: XS
  - Height between 1.10m and 1.30m (included) and weight minor than 40kg (included): S
  - Height between 1.10m and 1.30m (included) and weight greater than 40kg: M
  - Height between 1.30m and 1.60m (inlcuded): M
  - Height greater than 1.70m: L

- More than 18 years:
  - Heigh minor than 1.40m (included) or weight minor than 40kg (included): XS
  - Height between 1.40m and 1.60m (included): S
  - Height between 1.60m and 1.70m (included): M
  - Height between 1.70m and 1.90m (included): L
  - Height greater than 1.90m: XL

Implement the conditions using the selection statements `if`, `else if`, `else`.

## Exercise 4 - switch

Use the control structure `switch` for printing your name given the enrollment number.

1. Create a variable `int` for storing the enrollment number.

2. Ask the enrollment number from the terminal.

2. Create a `switch` condition prints your name given your enrollment number,
otherwise it prints the error message: "Number not found".
