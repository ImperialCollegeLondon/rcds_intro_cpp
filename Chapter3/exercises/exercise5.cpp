/*
  Exercise: Loops ii - square and cube numbers
*/

#include <iostream>
using namespace std;

int main() {

  // Declare variables
  int n = 10;

  // Square input
  cout << "\nSquare input" << endl;
  for(int i = 0; i < n; ++i) {
    cout << pow(i, 2) << endl;
  }

  // Declare and initialise at the same time
  int i = 3;

  // Cube input
  cout << "\nCube input" << endl;
  while(i < n) {
    cout << pow(i, 3) << endl;
    ++i;
  }

  // Collatz conjecture
  while(i < n) {
    cout << pow(i,3) << endl;
    ++i;
  }

}