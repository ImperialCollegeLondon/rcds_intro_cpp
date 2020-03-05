# Chapter 10

### Jesús Urtasun Elizari - University of Milan - 2019/20

**Subject:** Base exercises in C++: TF1, TGraph, TGraphErrors and TH1F.

Before starting we suggest to create a folder for Lesson 4 where you can save all files that will be created for the exercise
```bash
cd ~/           # go the home directory
mkdir Chapter09  # create the directory Chapter09 in home
cd Chapter09     # go inside Chapter09
```
Create a `makefile` to compile all exercises

## Exercise 1 - Multi TGraph


Write a **C++ program** where points are classified in 2 categories, inside and outside of the circle centered in
`(x,y) = (0.5, 0.5)` and radius`r = 0.5`.

1. Define the data structure for points on the plane `(x,y)`.

2. Download with the command `wget` the file with the coordinates `(x,y)` of a 1000 points:
```
https://raw.githubusercontent.com/JesusUrtasun/CppCourse/master/Chapter10/data1.dat
```

3. Download the data from a file to a dynamic array of the stucture defined in 1.

4. Create 2 `TGraph` objects, `g1` and `g2`. For every element of the array of points determine of it is inside or outside the circle.
Fill `g1` with the points inside the circle and `g2` with the points outside. *Hint*: build a function that computes the distance point - center.

5. Color markers of `g1` in blue and `g2` in red.

6. Create a canvas of dimensions `(800, 800)`, add the title and design `g1` and `g2`.

7. Save the plot in a file `exercise1.pdf`.

## Exercise 2 - Fitting a TGraphError

Write a **C++ program** and determine the acceleration of a moving object.

1. Download with the command `wget` the data file with the coordinates `(time, y(t))` of 100 points:
```
https://raw.githubusercontent.com/JesusUrtasun/CppCourse/master/Chapter10/data2.dat
```

2. Save the data in a `TGraphErrors`, considering the error on the axis `x` zero, and on the `y` axis costante `yerr = 0.1`.

3. Create a `TF1` where you define a function to fit `y(t) = 1/2 * a * t^2`, where `a` is the parameter to optimize.

4. Add title and axis to the plot, plot the points and the function to fit.

5. Use the option `gStyle->SetOptFit();` including the header `TStyle.h` such that the result of the fit are shown on the plot.

6. Print on the terminal the chi2 estimator and the final value of `a`.
