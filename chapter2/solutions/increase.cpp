/*
  Exercise 1: Increasing / Decreasing
*/

#include <iostream>
using namespace std;

int main() {

  // Declare variables
  int number;
  const int r = 2;

  // Read the number as input
  cout << "Introduce an integer: ";
  cin >> number;

  // Compute operations
  int increasing, decreasing, division, rest;
  increasing = number;
  decreasing = number;
  increasing++;  
  decreasing--;
  division = number / r;
  rest = number % r;
  
  // Print on screen
  cout << "number: " << number << endl;
  cout << "ratio: " << r << endl;
  cout << "increased: " << increasing << endl;
  cout << "decreased: " << decreasing << endl;
  cout << "division : " << division << endl;
  cout << "rest     : " << rest << endl;  
  
  return 0;

}