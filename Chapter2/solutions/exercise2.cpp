/*
  Esercise 2: Area and perimeter
*/

#include <iostream>
using namespace std;

int main() {

  // Declare variables
  double base, height;
  double area, perimeter;

  // Assign values
  base = 5.0;
  height = 2.0;

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