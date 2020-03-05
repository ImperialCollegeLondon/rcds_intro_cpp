# Chapter 11

### Jesús Urtasun Elizari - University of Milan - 2019/20

**Subject:** Base exercises in C++: ssg, TH1F.

Before starting we suggest to create a folder for Lesson 4 where you can save all files that will be created for the exercise
```bash
cd ~/           # go the home directory
mkdir Chapter09  # create the directory Chapter09 in home
cd Chapter09     # go inside Chapter09
```
Create a `makefile` to compile all exercises

## Exercise 1 - ssh

Log on the machine of laboratorio di calcolo from the department of physics using ssh and copy some files.

1. Register on [link](https://registrazione.fisica.unimi.it/cgi-sec/register.php).

2. Log with `ssh <username>@tolab.fisica.unimi.it`.

3. Verify the content of the home directory.

4. Copy some files and flders between your machine and tolab using `scp` and `scp -r` respectively.

## Exercise 2 - Histogram

Write a **ROOT macro** where a histogram is designed.

1. Create a ROOT macro `exercise2.C`. Create a canvas of dimensions 800x600.

2. Create a1D histogram `TH1F` with 100 bins between [-4, 4].

3. Use the method `h1->FillRandom("gaus", 5000)` for filling the histogram.

4. Design the histogram and test the setup.

5. Add the title and the axis to the plot.

6. Color the histogram with the method `SetFillColor(kYellow)`. Color the line of the histogram with `SetLineColor(kBlue)`.

7. Test the macro.

8. Save the plot on the file `exercise2.png`.

## Exercise 3 - Fitting histogram

Write a **C++ program** where a histogram comes designed.

1. Convert the macro `exercise2.C` in a C++ program.

2. Test the program.

8. Fitting the histogram with a gaussian. Use the option `gStyle->SetOptFit()` for showing the result of the fit.

9. Save the plot as `exercise3.png`.

## Exercise 4 - TH1F fill from file

Write a **C++ program** where the histogram comes filled from a file.

1. Download with the command `wget` the data file:
```
https://raw.githubusercontent.com/JesusUrtasun/CppCourse/master/Chapter11/data4.dat
```

2. Download the ata in a histogram with 50 bins between [-20, 25].

3. Design the histogram, color and add the title.

4. Test the program.

## Exercise 5 - Template function

Write a **C++** where a function `sum` comes implemented with 2 numeric data(float, double, int, long, ecc).
Test the implementation.
