/*
  Exercise 4: Collatz conjecture
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

  // Declare variables
  int n;
  int f;

  // Ask input from keyboard
  cout << "Input a number" << endl;
  cin >> n;

  // Run Collatz algorithm
  while(n != 1) {

    if(n%2 == 0) {

        f = n / 2;

    } else {

        f = 3 * n + 1;

    }

    n = f;
    cout << n << endl;

  }

  return 0;
}