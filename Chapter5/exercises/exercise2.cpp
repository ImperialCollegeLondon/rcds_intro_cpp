/*
  Exercise: Pointer arrays.
*/

#include <iostream>
using namespace std;

int main () {

  // Declare variables
  int primes[3] = {2, 3, 5};
  int *p;

  p = primes; // Set the pointer to point at the start of the array

  for (int i = 0; i < 3; i++) {
      cout << "Address of primes[" << i << "] is " << p << endl;
      cout << "Value of primes[" << i << "] is " << *p << endl;
      ++p;
  }  

  return 0;

}