/*
  Exercise 3: Input / output
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

  // Print resutls
  cout << "Base = " << base << endl;
  cout << "Height = " << height << endl;
  cout << "Area rectangle = " << area << endl;
  cout << "Perimeter rectangle = " << perimeter << endl;

  return 0;

}