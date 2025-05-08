/*
  Exercise: Multiplication table
*/

#include <iostream>
using namespace std;

int main() {

  // Declare variables
  const int n = 10;
  int product[n][n];

  // Loop filling array
  for(int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        product[i][j] = (i + 1) * (j + 1);
    }
  }

  // Loop prining array elements
  for(int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        cout << product[i][j] << "\t";
    }
    cout << "\n";
  }

  return 0;

}