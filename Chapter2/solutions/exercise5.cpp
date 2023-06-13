/*
  Exercise 5: Converting temperature
*/

#include <iostream>
using namespace std;

int main() {
  
  // Declaring variables
  double T_Celsius;

  // Assign values
  cout << "Introduce temperature in Celsius: ";
  cin >> T_Celsius;
  
  // Compute in kelvin
  double T_Kelvin = T_Celsius + 273.15;
  
  // Prepare cout with 10 significant digits
  cout.precision(3);
  
  // Pring result with fixed
  cout << fixed;
  cout << "T(Celsius) = " << T_Celsius << " -> T(Kelvin) = " << T_Kelvin << endl;

  return 0;

}