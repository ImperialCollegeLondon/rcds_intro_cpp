/*
  Exercise: Functions III.
*/

#include <iostream>
using namespace std;

// Function declarations
int function_sign(int n);
int function_abs(int n);

// Function definitions
int main() {

  // Declare variables
  int n;
  n = 3;

  // Call functions
  cout << "Sign: " << function_sign(n) << endl;
  cout << "Absolute value: " << function_abs(n) << endl;

  return 0;


}
