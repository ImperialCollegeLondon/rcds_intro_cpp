/*
  Exercise: Template function
  Author: Jesús Urtasun - 2020
*/

#include <iostream>
using namespace std;

// Create a template function
template<typename T>
T sum(T a, T b) {
  return a+b;
}

int main() {

  // Testing function
  cout << sum(1,2) << endl;

  // Testing function
  cout << sum(1.5, 2.5) << endl;

  return 0;

}