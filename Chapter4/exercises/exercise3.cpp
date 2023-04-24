/*
  Exercise: Functions I.
*/

#include <iostream>
using namespace std;

int sign_function(int n) {

  // Declare variables
  int sign;

  if(n > 0) {
      sign = 1;
  } else if(n==0) {
      sign = 0;
  } else {
      sign = -1;
  }
  return sign;

}

int main() {
  
  // Declare variables
  int pos_n = 3;
  int neg_n = -3;
  // Call sign function
  cout << "Sign: " << sign_function(pos_n) << endl;
  cout << "Sign: " << sign_function(neg_n) << endl;

  return 0;

}