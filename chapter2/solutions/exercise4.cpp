/*
  Exercise 4: Notation for cout
*/

#include <iostream>
using namespace std;

int main() {
  
  // Declare variables
  double base, height;
  double area, perimeter;

  // Assign values
  cout << "Introduce value for the base: ";
  cin >> base;
  cout << "Introduce value for the height: ";
  cin >> height;
  cout << "Rectangle base = " << base << ", height = " << height << endl;
  
  // Compute area
  area = base * height;

  // Compute perimeter
  perimeter = 2 * (base + height);

  // Prepare cout with 5 decimal digits
  cout.precision(5);
  
  // Print result with fixed
  cout << fixed;
  cout << "Area = " << area << "\tPerimeter = " << perimeter << endl;

  // Print results with scientific
  cout << scientific;
  cout << "Area = " << area << "\tPerimeter = " << perimeter << endl;

  return 0;
  
}
