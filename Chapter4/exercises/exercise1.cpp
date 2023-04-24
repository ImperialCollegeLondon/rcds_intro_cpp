/*
  Exercise: Arrays.
*/

#include <iostream>
using namespace std;

int main() {

  // Declare variables
  int n = 10;
  int square_numbers[10];
  int favourite_numbers[10] = {3, 1, -4, 1}; // Note we haven't defined them all.;

  for(int i = 0; i < n; ++i) {
      square_numbers[i] = pow(i, 2);
  }

  for(int i = 0; i < n; ++i) {
      cout << square_numbers[i] << endl;
  }

  for(int i = 0; i < n; ++i) {
      cout << favourite_numbers[i] << endl;
  }        

  return 0;

}