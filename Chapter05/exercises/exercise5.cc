/*
  Exercise: Fibonacci series
  Author: Jesús Urtasun - 2020
*/

#include <iostream>
using namespace std;

int main() {

  // Declare variables
  int n, element;
  int first = 0, second = 1;

  // Determine the number of elements to compute
  cout << "Introduce the number of elements to be generated from the Fibonacci series: ";
  cin  >> n;

  // Compute the elements
  cout << "First " << n << "elements of the Fibonacci series:" << endl;
  for (int i = 0; i < n; i++)
    {
      if (i <= 1)
	      element = i;
      else
      {
        element = first + second;
        first = second;
        second = element;
      }
      cout << element <<  endl;
    }

  return 0;

}