/*
  Exercise 3: conditionals ii - bartender
*/

#include <iostream>
using namespace std;

int main() {

  // Declare variables
  int age;
  cout << "Welcome to the pub." << endl;
  cout << "What is your age?" << endl;

  // Store age
  cin >> age;

  // Conditional statement
  if(age > 18) {
      cout << "Have a pint!" << endl;
  } else if(age == 18) {
      cout << "Show me your ID and then have a pint!" << endl;
  } else {
      cout << "I'm calling the police." << endl;
  }

}