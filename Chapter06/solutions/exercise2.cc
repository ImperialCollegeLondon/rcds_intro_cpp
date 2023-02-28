/*
  Esercizio: Prodotto scalare
  Author: Jesús Urtasun - 2020
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

  // Create variables & dynamic arrays
  const int n = 5;

  double *v = new double[n];
  v[0] = 2;
  v[1] = 5;
  v[2] = 10;
  v[3] = 20;
  v[4] = 50;

  double *w = new double[n];
  w[0] = 10;
  w[1] = -5;
  w[2] = 3;
  w[3] = 1;
  w[4] = 100;

  // Print v
  cout << "Array v:" << endl;
  for (int i = 0; i < n; i++)
    {
      cout << "v[" << i << "] = " << v[i] << endl;
    }
  
  // Print z
  cout << "Array w:" << endl;
  for (int i = 0; i < n; i++)
    {
      cout << "w[" << i << "] = " << w[i] << endl;
    }

  // Compute scalar product
  double s = 0;
  for (int i = 0; i < n; i++)
    s += v[i] * w[i];
  cout << "Scalar product v*w = " << s << endl;

  double *z = new double[n];
  for (int i = 0; i < n; i++)
    {
      if (i == 2)
	      z[i] = 0;
      else
	      z[i] = v[i];
    }
  // Print z
  cout << "Array z:" << endl;
  for (int i = 0; i < n; i++)
    {
      cout << "z[" << i << "] = " << z[i] << endl;
    }

  // Compute normalization of z
  double norm = 0;
  for (int i = 0; i < n; i++)
    norm += z[i] * z[i];
  norm = sqrt(norm);
  cout << "Norm z = " << norm << endl;

  // Normalize and print z
  cout << "Normalized z:" << endl;
  for (int i = 0; i < n; i++)
    {
      z[i] /= norm;
      cout << "z[" << i << "] = " << z[i] << endl;
    }

  delete[] v;
  delete[] w;
  delete[] z;

  return 0;

}