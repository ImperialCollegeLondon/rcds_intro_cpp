/*
  Exercise 2: even / odd numbers
*/

#include <iostream>
using namespace std;

int main() {

  // Declare variables  
  int number;
  cout << "Introduce integer: ";
  cin >> number;

  // Check odd or even
  cout << "The number " << number << " is "; 
  if (number % 2 == 0)
    cout << "even." << endl;
  else
    cout << "odd." << endl;
  
  return 0;

}