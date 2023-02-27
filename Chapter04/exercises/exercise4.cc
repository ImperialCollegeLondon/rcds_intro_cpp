/*
  Exercise: Switch
  Author: Jesús Urtasun - 2020
*/

#include <iostream>
using namespace std;

int main() {

  // Declare variables
  int number;

  // Ask for enrollment number
  cout << "Introduce your enrollment number: ";  
  cin >> number;

  switch(number)
    {
    case 123456:
      cout << "It's me" << endl;
      break;

    default:
      cout << "Number not found" << endl;
    }
  
  return 0;

}