/*
  Exercise: Pointers
*/

#include <iostream>
using namespace std;

int main() {

  // Declare variables and pointers
  double x = 5.5;
  double *p = NULL;

  // Print on screen
  cout << "x = " << x << endl;
  cout << "&x = " << &x << endl;
  cout << "p = " << p << endl;
  cout << "&p = " << &p << endl;

  // Assign &x to p
  p = &x;
  cout << "p  = " << p << endl;
  cout << "*p = " << *p << endl;

  // Ask for a new double
  cout << "Introduce a double: ";
  cin >> *p;

  // Control the new value of x (modified by *p)
  cout << "x = " << x << endl;  

  return 0;

}