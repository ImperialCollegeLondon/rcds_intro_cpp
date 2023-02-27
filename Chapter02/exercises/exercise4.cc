/*
  Exercise 4: correct version
  Author: Jesús Urtasun - 2020
*/

#include <iostream>
#include <cmath>
using namespace std; // using namespace std -> ; missing
 
int main() {

  const double angle = 9;
  const int a = 2, b = 3;
  int sum = 0; // sum can not be constant
 
  sum = a + b;// ; missing
 
  cout << "sin(9) = " << sin(angle) << endl; // missing space in <<sin
  cout << "sum = " << sum << "\n";
 
  return 0; // missing identing and many space btw return and 0

}