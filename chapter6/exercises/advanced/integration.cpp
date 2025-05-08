// RCDS introductoin to c++
// Advanced - numerical integration

// Import libraries
#include <iostream>
#include <cmath>
using namespace std;

// Gaussian function
double gauss(double x) {

  return 1 / sqrt(2*M_PI) * exp(-x*x/2);

}

// Numerical integration by trapezoidal rule
double integrate_gaussian(double a, double b, int n) {

  // Set parameters
  double area = 0;
  double d = (b-a)/n;

  // Trapezoidal rule  
  for (int i = 0; i < n; i++) {
    area += (gauss(a + i*d) + gauss(a + (i+1)*d)) / 2;
  }

  return d * area;

}

// Main function
int main() {

  // Set number of iterations
  int n = 100;

  // Compute the integral 
  cout << "n = " << n << endl;
  cout << "Integral from -1 to 1: " << integrate_gaussian(-1, 1, n) << endl;
  cout << "Integral from -5 to 5: " << integrate_gaussian(-5, 5, n) << endl;
  cout << "Integral from -10 to 10: " << integrate_gaussian(-10, 10, n) << endl;
  cout << "Integral from -100 to 100: " << integrate_gaussian(-100, 100, n) << endl;

  return 0;

}