/*
  Exercise: Compute mean (input from file)
  Author: Jesús Urtasun  - 2020
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {

  // Declare variables
  fstream f;
  double num;
  double sum = 0.0, n = 0.0; 

  // Ope file
  f.open("../data.dat", ios::in);
  if (!f.good())
    {
      cout << "Problemi con il file data.dat" << endl;
      return -1;
    }
      
  // Read the numbers and compute sum 
  for (;;)
    {
      f >> num;
      if (f.eof()) break;
      sum += num;
      n++;
    }
  f.close();

  // Compute mean
  cout << "Mean = " << sum / n << endl;
  
  return 0;

}