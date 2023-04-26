/*
  Exercise 3: Input / output
*/

#include <iostream>
using namespace std;

int main() {

  // Declare variables
  string name;
  double height;

  // Assign values
  cout << "What is your name?" << endl;
  cin >> name;
  cout << "What is your height?" << endl;
  cin >> height;
  cout << name << " is " << height << " metres tall." << endl;

  return 0;

}