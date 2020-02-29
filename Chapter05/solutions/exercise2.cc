/*
  Exercise: Compute mean (input from terminal)
  Author: Jesús Urtasun - 2020
*/

#include <iostream>
using namespace std;

int main() {

  // Ask how many numbers to read
  int n;
  cout << "How many numbers to read?: ";  
  cin >> n;

  // Ask for the numbers and save the sum
  double num;
  double sum = 0.0;
  for (int i = 0; i < n; i++)
    {
      cout << "Introduce number: ";
      cin >> num;
      sum = sum + num;
    }

  // Compute mean value
  cout << "Mean =  " << sum / n << endl;
  
  return 0;

}