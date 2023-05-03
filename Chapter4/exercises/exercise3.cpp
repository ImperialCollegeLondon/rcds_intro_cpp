/*
  Exercise 3: Headers and source
*/

#include <iostream>
#include "functions.h"
using namespace std;

int main() {

  // Declare variables
  double a = 5, b = 2;

  cout << "Initial values:" << endl;
  cout << a << " " << b << endl;

  // Call change1 function
  cout << "First change with change1:" << endl;
  change1(a, b);
  cout << a << " " << b << endl;

  // Call change2 function
  cout << "Second change with change2:" << endl;
  change2(&a, &b);
  cout << a << " " << b << endl;
  
  return 0;

}