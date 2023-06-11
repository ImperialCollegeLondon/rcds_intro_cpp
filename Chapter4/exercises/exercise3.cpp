/*
  Exercise: Conversion temperature
*/

#include <iostream>
using namespace std;

int main() {

  // Declare variables
  int option;
  double T_Celsius;

  // Assign values
  cout << "Introduce temperature value in Celsius: ";
  cin >> T_Celsius;

  // Ask for option
  cout << "Press 1 for conversione to Kelvin." << endl;
  cout << "Press 2 for conversion to Fahrenheit." << endl;
  cout << "Option chosen: ";
  cin >> option;

  // Preparare cout with 10 significant digits
  cout.precision(3);
  cout << fixed;
  
  if (option == 1) {

    // From Celsius to Kelvin
    double T_Kelvin = T_Celsius + 273.15;
    cout << "T(Celsius) = " << T_Celsius << " -> T(Kelvin) = " << T_Kelvin << endl;
  
  } else if (option == 2) {

    // From Celsius to Fahrenheit
    double T_Fahrenheit = T_Celsius * 9.0 / 5.0 + 32.0;
    cout << "T(Celsius) = " << T_Celsius << " -> T(Fahrenheit) = " << T_Fahrenheit << endl;      
    
  } else {

      cout << "Option not recognized." << endl;
  }

  return 0;

}