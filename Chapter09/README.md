# Chapter 9

### Jesús Urtasun Elizari - University of Milan - 2019/20

**Subject:** Base exercises in C++: TF1, TGraph, TCanvas e TApplication.

Before starting we suggest to create a folder for Lesson 4 where you can save all files that will be created for the exercise
```bash
cd ~/           # go the home directory
mkdir Chapter09  # create the directory Chapter09 in home
cd Chapter09     # go inside Chapter09
```
Create a `makefile` to compile all exercises

## Exercise 1 - Functions of one variable

Write a ROOT macro that uses functions of one variable

1. Create a ROOT macro called `exercise1.C` and its respective function. All next questions must be done inside this macro.

2. Build a `TF1` object defined as `-sin(x*x)/x + 0.01 * x*x` between `x = [-3, 3]`.

3. Design the curve.

4. Modify the title of the graph with "Exercise 1", and the axis titles as `x` and `y`, and run the macro again.

4. Modify the color of the line using the `TF1` method `SetLineColor()`. Choose a color from https://root.cern.ch/doc/master/classTColor.html#C02.

5. Run the macro and save the final image in format `png`.

## Exercise 2 - Functions of 1 variables

Write a ROOT macro where 2 TF1 come defined on the same canvas.

1. Copu the next macro in a new file `exercise2.C`.

2. Create a `TF1` with the function `0.1*sin(4*x)/x` defined between `x = [-3, 3]`.

3. Create another `TF1` with the function `0.5*x` of color `kGreen`.

4. Draw both functions on the same plot. Add `Exercise 2` as title to the graph.

## Exercise 3 - Functions of 1 variable multi-canvas

Write a ROOT macro where 2 TF1 are designed on different canvas.

1. Create a macro `exercise3.C`.

2. Define a `TCanvas` of dimensions `(600,400)`.

3. Design the parabola `x^2` between `x = [-5, 5]`, add the title and the axis.

4. Save the plot in a file `c1.png` using the method `SaveAs()` of `TCanvas`.

5. Create a second canvas, design the curve `sin(x)/x`, save the output as `c2.png`.

## Exercise 4 - Program in C++ with ROOT

Write a C++ program using ROOT as a library.

1. Create a C++ file `exercise4.cc`.

2. Create a `TCanvas` of dimension `(800, 500)` and draw the function `1/x` between `x = [-10, 10]`.
Add title and axis to the plot. Save the canvas in a file `exercise4.png`.

3. Make it such that the graph window does not close at the end of the program.

4. Compile with the following flags:
```
`root-config --cflags` `root-config --libs`
```

5. Test the program.

## Exercise 5 - Fitting

Write a ROOT macro that performs a fit of the following the points.

1. Download the data with:
```
wget https://raw.githubusercontent.com/JesusUrtasun/CppCourse/master/Chapter09/data.dat
```

2. Read from the file the 100 coordinates. On the file there are 3 columns, build 3 arrays `x, y, y2` and fill with their content.

3. Create a canvas and draw `(x,y)` using the object `TGraph`. Perform a linear fit using the predefined function `pol1`.

4. Create a new canvas and draw `(x, y2)`, fit the data with a `TF1` defined as `[0]*x^2 + [1]*x + [2]`. 
Compare this result with a fit using the predefined function `pol2`.

5. Save both plots in `png` format.
