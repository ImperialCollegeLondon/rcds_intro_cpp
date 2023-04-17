/*
  Exercise 6: Nonation for cout
  Author: Jesús Urtasun
*/

#include <iostream>
using namespace std;

int main() {
  
  // Declare variables
  double base, height;
  double area, perimeter;

  // Assign values
  cout << "Introduce value for base: ";
  cin >> base;
  cout << "Introduce value for height: ";
  cin >> height;
  cout << "Rectangle base = " << base
       << ", height = " << height << endl;
  
  // Compute area
  area = base * height;

  // Compute perimeter
  perimeter = 2 * (base + height);

  // Prepare cout with 10 decimal digits
  cout.precision(10);
  
  // Print result with fixed
  cout << fixed;
  cout << "Area = " << area << "\tPerimeter = " << perimeter << endl;

  // Print results with scientific
  cout << scientific;
  cout << "Area = " << area << "\tPerimeter = " << perimeter << endl;

  return 0;
}
