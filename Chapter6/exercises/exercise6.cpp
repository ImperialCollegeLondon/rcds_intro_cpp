/*
  Exercise 4: Second order equations
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

  // Declare variables
  double a, b, c;

  // Assign values
  cout << "Introduce the coefficients a b c (separated by space):\n";
  cin >> a >> b >> c;

  cout << "Solving " << a << "*x^2 + " << b << "*x + " << c << " = 0.\n";
  
  // Compute discriminant
  const double D = pow(b, 2) - 4 * a * c;

  if (D > 0) {

    const double x1 = (-b + sqrt(D)) / (2 * a);
    const double x2 = (-b - sqrt(D)) / (2 * a);
    cout << "Solution x1 = " << x1 << endl;
    cout << "Solution x2 = " << x2 << endl;  

  }  else if (D == 0) {

    const double x12 = -b / (2 * a);
    cout << "Solution x1,2 = " << x12 << endl;

  } else {

    // D < 0
    const double real = -b / (2 * a);
    const double imag1 = sqrt(-D) / (2 * a);
    const double imag2 = -imag1;
    cout << "Solution x1 = " << real << " + i * " << imag1 << endl;
    cout << "Solution x2 = " << real << " + i * " << imag2 << endl;

  }
    
  return 0;

}