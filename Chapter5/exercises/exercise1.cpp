/*
  Exercise: Pointers
*/

#include <iostream>
using namespace std;

int main() {

  // Create variables and pointers
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

  // Create an array of pointers n = 2
  cout << "Array of pointers:" << endl;
  int n = 10;
  double *v = new double[10];
  for (int i = 0; i < n; i++)
    cout << "&v[" << i << "] = " << &v[i] << endl;
  delete[] v;

  return 0;

}