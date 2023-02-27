/*
  Exercise 3: string and char
  Author: Jesús Urtasun - 2020
*/

#include <iostream>
#include <string>
using namespace std;

int main() {

  // Declare variables
  char name[20];
  string surname;
  int number;
  
  // Print to screen
  cout << "Name     : ";
  cin >> name;

  cout << "Surname  : ";
  cin >> surname;

  cout << "Number: ";
  cin >> number;

  cout << surname << ", " << name << " is registered with number " << number << ".\n";

  return 0;

}